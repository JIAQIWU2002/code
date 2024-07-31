#include "snake.hpp"

Snake::Snake(Map *map) : _map(map)
{
    // 初始化时 一个头+2节身体
    // 第一个矩形为 头部，朝右
    _snake.emplace_back(Rect(map->cellSize(), map->cellSize(), map->cellPosition(7, 3), Color(0, 190, 190)));
    // 后面两个是身体
    _snake.emplace_back(Rect(map->cellSize(), map->cellSize(), map->cellPosition(5, 3), Color(0, 250, 250)));
    _snake.emplace_back(Rect(map->cellSize(), map->cellSize(), map->cellPosition(4, 3), Color(0, 250, 250)));
}

Snake::~Snake()
{
}

void Snake::move(Direction d)
{
    // 获取尾部位置
    Point tail_pos = _snake.back().pos();

    // 移动身体，从后往前更新每节身体的坐标
    for (int i = _snake.size() - 1; i > 0; i--)
    {
        _snake.at(i).move(_snake.at(i - 1).pos());
    }

    // 移动头部，根据方向更新头部位置
    int step = _map->cellSize() + _map->gapSize(); // 步长，移动一次的像素点数
    if (d == Direction::Up)
    {
        _snake.front().move(_snake.front().x(), _snake.front().y() - step);
    }
    else if (d == Direction::Down)
    {
        _snake.front().move(_snake.front().x(), _snake.front().y() + step);
    }
    else if (d == Direction::Left)
    {
        _snake.front().move(_snake.at(0).x() - step, _snake.at(0).y());
    }
    else if (d == Direction::Right)
    {
        _snake.front().move(_snake.at(0).x() + step, _snake.at(0).y());
    }

    // 处理穿过边界的情况
    if (_snake.front().x() > _map->right())
    {
        _snake.front().move(_map->left(), _snake.front().y());
    }
    else if (_snake.front().x() < _map->left())
    {
        _snake.front().move(_map->right(), _snake.front().y());
    }
    else if (_snake.front().y() < _map->up())
    {
        _snake.front().move(_snake.front().x(), _map->bottom());
    }
    else if (_snake.front().y() > _map->bottom())
    {
        _snake.front().move(_snake.front().x(), _map->up());
    }

    // 擦除原尾巴的位置
    _map->resetCellColor(tail_pos);
}

bool Snake::eat(Food *food)
{
    // 获取食物的坐标
    int x1 = food->pos().x();
    int y1 = food->pos().y();

    // 获取蛇头的坐标
    int x2 = _snake.front().x();
    int y2 = _snake.front().y();

    // 判断食物是否与蛇头重合
    if (x1 == x2 && y1 == y2)
    {
        // 如果重合，则增加蛇的长度
        add_body();
        return true;
    }
    else
        return false;
}

bool Snake::dead() const
{
    // 获取蛇头坐标
    int head_x = _snake.front().x();
    int head_y = _snake.front().y();

    // 检查蛇是否撞到自己身体
    for (int i = _snake.size() - 1; i > 0; i--)
    {
        if (_snake.at(i).x() == head_x && _snake.at(i).y() == head_y)
        {
            return true; // 如果蛇头与身体某部分重合，则蛇死亡
        }
    }

    return false; // 蛇未死亡
}

void Snake::draw()
{
    // 绘制整条蛇
    for (int i = 0; i < _snake.size(); i++)
    {
        _snake.at(i).draw(); // 绘制蛇身每一部分
    }
}

void Snake::add_body()
{
    // 生成随机数种子
    std::random_device rd;
    // 初始化随机数生成器
    std::mt19937 gen(rd());
    // 定义均匀分布在0到200之间的随机数生成器
    std::uniform_int_distribution<int> dis3(0, 200);
    // 生成随机的RGB颜色值
    int r, g, b;
    r = dis3(gen);
    g = dis3(gen);
    b = dis3(gen);
    // 将新的矩形块添加到蛇身体中，初始位置在(-100, -100)，颜色为随机生成的RGB值
    _snake.push_back(Rect(15, 15, Point(-100, -100), Color(r, g, b)));
}
