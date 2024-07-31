#include "bitmap.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "color.hpp"
using namespace std;

Bitmap24::Bitmap24(const char *filename)
{
    //打开位图文件
    _fd = open(filename, O_RDONLY);
    if (_fd == -1)
    {
        perror("open bmp error");
        exit(1);
    }
    char bm[2] = {0};
    read(_fd, bm, 2);
    if (bm[0] != 'B' || bm[1] != 'M')
    {
        cout << "this is not a bitmap!\n";
        exit(1);
    }
    read(_fd, &_size, 4);

    lseek(_fd, 0x12, SEEK_SET);
    read(_fd, &_w, 4);
    read(_fd, &_h, 4);

    _data = (uchar *)malloc(_size - 0x36);
    lseek(_fd, 0x36, SEEK_SET);
    read(_fd, _data, _size - 0x36);

    cout << _size << ": " << _w << ": " << _h << endl;
}
Bitmap24::~Bitmap24()
{
    free(_data);
    close(_fd);
}
// 正向显示、字节对齐处理 未实现
void Bitmap24::draw(int x, int y)
{
    uchar r, g, b;
    int k = 0;
    for (int i = 0; i < _h; i++)
    {
        for (int j = 0; j < _w; j++)
        {
            b = _data[k++];
            g = _data[k++];
            r = _data[k++];
            Screen::instance()->draw_point(Point(j + x, i + y), Color(r, g, b));
        }
    }
}