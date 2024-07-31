#include "color.hpp"

Color::Color(int r, int g, int b) : _red(r), _green(g), _blue(b) {} // 构造函数实现

int Color::value() const
{
    return (_red << 16 | _green << 8 | _blue); // 计算颜色值
}