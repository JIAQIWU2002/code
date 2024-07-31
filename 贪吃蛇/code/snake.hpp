#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "map.hpp"
#include "rect.hpp"
#include "direction.hpp"
#include "food.hpp"
#include <deque>
#include <random>

class Snake
{
public:
    // 构造函数，传入地图指针
    Snake(Map *map);

    // 析构函数
    ~Snake();

    // 移动蛇的方向
    void move(Direction d);

    // 吃食物，返回是否成功吃到食物
    bool eat(Food *food);

    // 判断蛇是否死亡
    bool dead() const;

    // 绘制蛇
    void draw();

    // 增加蛇的身体长度
    void add_body();

private:
    // 蛇的身体，使用双端队列存储
    std::deque<Rect> _snake;
    // 地图指针
    Map *_map;
};

#endif
