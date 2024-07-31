#ifndef COLOR_HPP
#define COLOR_HPP

class Color
{
public:
    Color() = default; // 默认构造函数
    Color(int r, int g, int b); // 自定义构造函数
    int value() const; // 获取颜色值

private:
    int _red; // 红色分量
    int _green; // 绿色分量
    int _blue; // 蓝色分量
};

#endif