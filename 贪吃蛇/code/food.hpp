#ifndef FOOD_HPP
#define FOOD_HPP

#include "rect.hpp" // 包含矩形类头文件
#include "map.hpp"  // 包含地图类头文件

class Food
{
public:
    // 食物构造函数，接受地图指针和颜色作为参数
    Food(Map *map, Color color);
    // 食物析构函数
    ~Food();
    // 绘制食物
    void draw();
    // 放置食物
    void put();
    // 获取食物位置
    Point pos() const;

private:
    // 食物颜色
    Color _color;
    // 食物位置
    Point _pos;
    // 食物矩形
    Rect _rect;
    // 地图指针
    Map *_map;
};

#endif
