#include "game.hpp"
#include "screen.hpp"
#include <mutex>
#include <random>
#include <thread>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <string>
#include <cstdlib>

using namespace std;

int score = 0;
int speed = 200;
int paihan[3];
std::mutex mtx;
Game::Game() : _cur_direct(Direction::Right)
{
    _map = new Map;
    _logo = new Bitmap24("./images/logo2.bmp");
    _gameover = new Bitmap24("./images/game_over2.bmp");
    _snake = new Snake(_map);
    _food1 = new Food(_map, Color(255, 0, 0));   // 红
    _food2 = new Food(_map, Color(0, 0, 0));     // 黑
    _food3 = new Food(_map, Color(0, 255, 128)); // 绿
    _food4 = new Food(_map, Color(0, 0, 255));   // 蓝
    _fenshu = new Bitmap24("./images/fenshu.bmp");
    _main_show = new Bitmap24("./images/main_show.bmp");
    _pai_han = new Bitmap24("./images/pai_han.bmp");
    _ts = new TouchEvent();
}

Game::~Game()
{
    delete _map;
    delete _food1;
    delete _food2;
    delete _food3;
    delete _food4;
    delete _ts;
    delete _logo;
    delete _gameover;
    delete _snake;
    delete _fenshu;
}

void Game::setBackground(const Color &color)
{
    for (int i = 0; i < 480; i++)
    {
        for (int j = 0; j < 800; j++)
        {
            Screen::instance()->draw_point(j, i, color.value());
        }
    }
}

void Game::charge(int _num)
{
    switch (_num)
    {
    case 0:
        _food1->put();
        _food1->draw();
        break;
    case 1:
        _food2->put();
        _food2->draw();
        break;
    case 2:
        _food3->put();
        _food3->draw();
        break;
    case 3:
        _food4->put();
        _food4->draw();
        break;
    }
}

void Game::run()
{
    // 设置背景为纯白色
    setBackground(Color(255, 255, 255));
    _map->draw();
    _logo->draw(640, 32);
    _fenshu->draw(640, 3);
    _snake->draw();
    _food1->put();
    _food1->draw();
    _food2->put();
    _food2->draw();
    _food3->put();
    _food3->draw();
    _food4->put();
    _food4->draw();
    // 创建一个线程，用于捕获按键事件
    std::thread(&Game::handleKeyEvent, this).detach();
    // 游戏主循环
    while (1)
    {
        if (_snake->dead())
        {
            add_score(score, "data.txt");
            // _gameover->draw(0, 0);
            researt();
        }
        _snake->move(_cur_direct);
        _snake->draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        int _num;
        if (_snake->eat(_food1))
        {
            _num = 0;
            speed -= 10;
            if (speed <= 50)
            {
                speed = 50;
            }
            charge(_num);
        }
        else if (_snake->eat(_food2))
        {
            _num = 1;
            score += 50;
            charge(_num);
        }
        else if (_snake->eat(_food3))
        {
            _num = 2;
            score += 10;
            speed -= 5;
            if (speed <= 50)
            {
                speed = 50;
            }
            charge(_num);
        }
        else if (_snake->eat(_food4))
        {
            _num = 3;
            _snake->add_body();
            charge(_num);
        }
        Screen::instance()->lcd_draw_rectanle();
        Screen::instance()->lcd_draw_digit(score, 700, 0, 0x0000);
    }
    // add_score(score, "data.txt");
    // _gameover->draw(0, 0);
}

void Game::handleKeyEvent()
{
    while (1)
    {
        int key = _ts->direction();
        if (key == Up)
        {
            if (this->_cur_direct != Direction::Down)
                this->_cur_direct = Direction::Up;
        }
        else if (key == Down)
        {
            if (this->_cur_direct != Direction::Up)
                this->_cur_direct = Direction::Down;
        }
        else if (key == Left)
        {
            if (this->_cur_direct != Direction::Right)
                this->_cur_direct = Direction::Left;
        }
        else if (key == Right)
        {
            if (this->_cur_direct != Direction::Left)
                this->_cur_direct = Direction::Right;
        }
    }
}

void Game::show_score()
{
    read_score("data.txt");
    Screen::instance()->clear_led();
    _pai_han->draw(180, 0);
    Screen::instance()->lcd_draw_digit(paihan[0], 390, 225, 0x0000);
    Screen::instance()->lcd_draw_digit(paihan[1], 390, 330, 0x0000);
    Screen::instance()->lcd_draw_digit(paihan[2], 390, 420, 0x0000);
    int key = _ts->direction();
    if (key == Up || key == Left || key == Right || key == Down)
    {
        main_show();
    }
}

void Game::main_show()
{
    _main_show->draw(0, 0);
    int key = _ts->direction();
    if (key == Up || key == Left || key == Right)
    {
        run();
    }
    else if (key == Down)
    {
        show_score();
    }
}

void Game::add_score(int number, const std::string &filename)
{
    std::ifstream inFile(filename);
    std::vector<int> numbers;
    int num;

    while (inFile >> num)
    {
        numbers.push_back(num);
    }
    inFile.close();

    numbers.push_back(number);
    std::sort(numbers.rbegin(), numbers.rend());

    std::ofstream outFile(filename);
    for (int i = 0; i < std::min(3, static_cast<int>(numbers.size())); ++i)
    {
        outFile << numbers[i] << std::endl;
    }
    outFile.close();
}

void Game::read_score(const std::string &filename)
{
    std::ifstream inFile(filename);
    std::vector<int> numbers;
    int num;

    while (inFile >> num)
    {
        numbers.push_back(num);
    }
    inFile.close();

    std::sort(numbers.rbegin(), numbers.rend());

    for (int i = 0; i < std::min(3, static_cast<int>(numbers.size())); ++i)
    {
        paihan[i] = numbers[i];
    }
}

void Game::researt()
{
    delete _food1;
    delete _food2;
    delete _food3;
    delete _food4;
    delete _snake;
    delete _ts;

    _snake = new Snake(_map);
    _food1 = new Food(_map, Color(255, 0, 0));   // 红
    _food2 = new Food(_map, Color(0, 0, 0));     // 黑
    _food3 = new Food(_map, Color(0, 255, 128)); // 绿
    _food4 = new Food(_map, Color(0, 0, 255));   // 蓝
    _ts = new TouchEvent();
    main_show();
}