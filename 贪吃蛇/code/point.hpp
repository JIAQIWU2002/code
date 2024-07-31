#ifndef POINT_HPP
#define POINT_HPP

// 定义一个Point类
class Point
{
public:
    // 构造函数，初始化坐标为(0,0)
    Point(int x = 0, int y = 0);
    
    // 移动点到指定坐标
    void move(int x, int y);
    
    // 获取当前点的x坐标
    int x() const;
    
    // 获取当前点的y坐标
    int y() const;
    
    // 设置点的x坐标
    void setx(int x);
    
    // 设置点的y坐标
    void sety(int y);

private:
    int _x; // 点的x坐标
    int _y; // 点的y坐标
};

#endif
