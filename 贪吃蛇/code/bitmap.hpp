#ifndef BITMAP_HPP
#define BITMAP_HPP

#include "screen.hpp" // 包含屏幕头文件

using uchar = unsigned char; // 定义无符号字符类型

class Bitmap24
{
public:
    Bitmap24(const char *filename);  // 构造函数，传入文件名
    ~Bitmap24();                     // 析构函数
    void draw(int x = 0, int y = 0); // 绘制函数，传入坐标，默认为(0, 0)

private:
    int _fd;      // 文件描述符
    int _size;    // 大小
    int _w;       // 宽度
    int _h;       // 高度
    uchar *_data; // 数据
};

#endif
