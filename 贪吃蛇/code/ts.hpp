#ifndef TS_HPP
#define TS_HPP

#include <string>
#include "point.hpp"
#include "direction.hpp"

class TouchEvent
{
public:
    //触摸屏初始化操作
    TouchEvent();
    //触摸屏析构函数
    ~TouchEvent();
    //用于返回用户操作的函数，上下左右滑动
    Direction direction();
private:
    //根据触摸屏接受到的两个点，分析出滑动的方向
    Direction analyseDirection(Point start,Point end);
    int fd_;
};

#endif