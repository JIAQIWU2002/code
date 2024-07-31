#ifndef GAME_HPP
#define GAME_HPP

#include "color.hpp"  // 包含颜色类头文件
#include "map.hpp"    // 包含地图类头文件
#include "bitmap.hpp" // 包含位图类头文件
#include "snake.hpp"  // 包含蛇类头文件
#include "food.hpp"   // 包含食物类头文件
#include "ts.hpp"     // 包含触摸事件类头文件
#include "screen.hpp" // 包含屏幕类头文件

class Game
{
public:
    // 构造函数
    Game();
    // 析构函数
    ~Game();
    // 游戏运行函数
    void run();
    // 设置背景颜色
    void setBackground(const Color &color);
    // 处理按键事件
    void handleKeyEvent();
    // 显示分数
    void showscore();
    // 主界面显示
    void main_show();
    // 显示分数
    void show_score();
    // 增加分数
    void add_score(int number, const std::string &filename);
    // 读取分数
    void read_score(const std::string &filename);
    // 充电
    void charge(int a);
    // 食物与蛇的碰撞检测
    bool food_snake(std::deque<Rect> *t, Food *food);
    // 重置游戏
    void researt();

private:
    // 地图指针
    Map *_map;
    // 蛇指针
    Snake *_snake;
    // 游戏logo位图指针
    Bitmap24 *_logo;
    // 游戏结束位图指针
    Bitmap24 *_gameover;
    // 触摸事件指针
    TouchEvent *_ts;
    // 当前方向
    Direction _cur_direct;
    // 食物1（红色）
    Food *_food1;
    // 食物2（黑色）
    Food *_food2;
    // 食物3（绿色）
    Food *_food3;
    // 食物4（蓝色）
    Food *_food4;
    // 分数位图指针
    Bitmap24 *_fenshu;
    // 主界面位图指针
    Bitmap24 *_main_show;
    // 排行榜位图指针
    Bitmap24 *_pai_han;
};
#endif
