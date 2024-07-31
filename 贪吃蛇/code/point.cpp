#include "point.hpp"

// Point类的构造函数实现
Point::Point(int x, int y) : _x(x), _y(y) {};

// 移动点到指定坐标
void Point::move(int x, int y)
{
    _x = x;
    _y = y;
}

// 获取当前点的x坐标
int Point::x() const
{
    return _x;
}

// 获取当前点的y坐标
int Point::y() const
{
    return _y;
}

// 设置点的x坐标
void Point::setx(int x)
{
    _x = x;
}

// 设置点的y坐标
void Point::sety(int y)
{
    _y = y;
}
