#include "map.hpp"

Map::Map() : _rows(30), _cols(40), _cell_size(15), _gap_size(1), _cell_color(222, 222, 222)
{
    //1200个格子
    _cells = new Rect[_rows * _cols];
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            //每个格子都是15*15的大小
            _cells[i * _cols + j].resize(_cell_size, _cell_size);
            //移动每个格子的起始位置
            _cells[i * _cols + j].move(j * (_cell_size + _gap_size), i * (_cell_size + _gap_size));
        }
    }
}

Map::~Map()
{
    delete[] _cells;
}

//对每个格子都画出颜色
void Map::draw()
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _cells[i * _cols + j].draw(_cell_color);
        }
    }
}
//返回格子的点对象
Point Map::cellPosition(int x, int y)
{
    return _cells[y * _cols + x].pos();
}

int Map::cellSize() const
{
    return _cell_size;
}
int Map::gapSize() const
{
    return _gap_size;
}

//重新设置格子的颜色
void Map::resetCellColor(Point pos)
{
    Rect(_cell_size, _cell_size, pos).draw(_cell_color);
}

int Map::left() const
{
    return 0;
}
int Map::right() const
{
    return (_cell_size + _gap_size) * (_cols - 1);
}
int Map::up() const
{
    return 0;
}
int Map::bottom() const
{
    return (_cell_size + _gap_size) * (_rows - 1);
}
int Map::get_cols() const
{
    return _cols;
}
int Map::get_rows() const
{
    return _rows;
}
