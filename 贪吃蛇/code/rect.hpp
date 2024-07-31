#ifndef RECT_HPP
#define RECT_HPP

#include "screen.hpp" // 包含屏幕类头文件
#include "point.hpp"  // 包含点类头文件
#include "color.hpp"  // 包含颜色类头文件

class Rect
{
public:
    Rect() = default;                           // 默认构造函数
    Rect(int w, int h);                         // 宽高构造函数
    Rect(int w, int h, Point pos);              // 宽高位置构造函数
    Rect(int w, int h, Point pos, Color Color); // 宽高位置颜色构造函数
    void draw(const Color &color);              // 绘制带颜色
    void draw();                                // 绘制
    void setWidth(int w);                       // 设置宽度
    void setHeight(int h);                      // 设置高度
    int w() const;                              // 获取宽度
    int h() const;                              // 获取高度
    int x() const;                              // 获取 x 坐标
    int y() const;                              // 获取 y 坐标

    void setColor(Color color); // 设置颜色
    void resize(int w, int h);  // 调整大小
    void move(int x, int y);    // 移动
    void move(Point pos);       // 移动到指定位置
    Point pos() const;          // 获取位置

private:
    int _w;       // 宽度
    int _h;       // 高度
    Point _pos;   // 位置
    Color _color; // 颜色
};

#endif
