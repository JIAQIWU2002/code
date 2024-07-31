#ifndef MAP_HPP
#define MAP_HPP

#include "rect.hpp"  // 包含矩形类头文件
#include "color.hpp" // 包含颜色类头文件

class Map
{
public:
    // 构造函数
    Map();
    // 析构函数
    ~Map();
    // 绘制地图
    void draw();
    // 获取单元格位置
    Point cellPosition(int x, int y);
    // 获取单元格大小
    int cellSize() const;
    // 获取间隙大小
    int gapSize() const;
    // 获取行数
    int get_rows() const;
    // 获取列数
    int get_cols() const;
    // 重置单元格颜色
    void resetCellColor(Point pos);
    // 左边界位置
    int left() const;
    // 右边界位置
    int right() const;
    // 上边界位置
    int up() const;
    // 下边界位置
    int bottom() const;

private:
    // 行数
    int _rows;
    // 列数
    int _cols;
    // 单元格大小
    int _cell_size;
    // 间隙大小
    int _gap_size;
    // 单元格数组
    Rect *_cells;
    // 单元格颜色
    Color _cell_color;
};

#endif
