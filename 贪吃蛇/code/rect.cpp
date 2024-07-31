#include "rect.hpp"

Rect::Rect(int w, int h) : _w(w), _h(h), _pos(0, 0), _color(0, 0, 0) {}
Rect::Rect(int w, int h, Point pos) : _w(w), _h(h), _pos(pos), _color(0, 0, 0) {}
Rect::Rect(int w, int h, Point pos, Color color) : _w(w), _h(h), _pos(pos), _color(color) {}

//给每个格子画颜色
void Rect::draw(const Color &color)
{
    for (int i = 0; i < _h; i++)
    {
        for (int j = 0; j < _w; j++)
        {
            Screen::instance()->draw_point(Point(j + _pos.x(), i + _pos.y()), color);
        }
    }
}

//调用自己的画格子函数
void Rect::draw()
{
    this->draw(_color);
}

void Rect::setWidth(int w)
{
    _w = w;
}
void Rect::setHeight(int h)
{
    _h = h;
}
int Rect::w() const
{
    return _w;
}
int Rect::h() const
{
    return _h;
}
int Rect::x() const
{
    return _pos.x();
}
int Rect::y() const
{
    return _pos.y();
}

void Rect::resize(int w, int h)
{
    _w = w;
    _h = h;
}
void Rect::move(int x, int y)
{
    this->_pos.move(x, y);
}
void Rect::move(Point pos)
{
    this->_pos.move(pos.x(), pos.y());
}
Point Rect::pos() const
{
    return _pos;
}
void Rect::setColor(Color color)
{
    this->_color = color;
}
