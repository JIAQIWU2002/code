#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "point.hpp"
#include "color.hpp"

class Screen
{
public:
    // 获取屏幕实例
    static Screen *instance();

    // 析构函数
    ~Screen();

    // 在指定坐标(x, y)处绘制指定颜色的点
    void draw_point(int x, int y, int color);

    // 在指定点pos处绘制指定颜色的点
    void draw_point(Point pos, Color color);

    // 在指定坐标(x0, y0)处绘制数字value
    void lcd_draw_digit(int value, int x0, int y0, int color);

    // 在指定坐标(x0, y0)处绘制字符串ch，长度为len，字体大小为w，颜色为color
    void lcd_draw_word(char *ch, int len, int w, int color, int x0, int y0);

    // 绘制矩形
    void lcd_draw_rectanle();

    // 清除LED屏幕
    void clear_led();

private:
    // 构造函数，传入屏幕名称
    Screen(const char *name);

    // 禁止拷贝构造函数
    Screen(const Screen &) = delete;

    // 禁止赋值运算符重载
    Screen &operator=(const Screen &) = delete;

    const char *_name; // 屏幕名称
    int _w;            // 屏幕宽度
    int _h;            // 屏幕高度
    short _bpp;        // 每像素位数
    int _fd;           // 文件描述符
    int *_addr;        // 屏幕地址
};

// 这里是数字0到9的字模
static char w_digit[][58] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x1E, 0xF0,
     0x3C, 0x78, 0x38, 0x38, 0x78, 0x3C, 0x78, 0x3C, 0x70, 0x1C, 0x70, 0x1C, 0x70, 0x1C, 0x70, 0x1C,
     0x70, 0x1C, 0x70, 0x1C, 0x70, 0x3C, 0x78, 0x3C, 0x78, 0x38, 0x38, 0x38, 0x3C, 0x70, 0x1E, 0xF0,
     0x07, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x03, 0x80,
     0x1F, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80,
     0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0xC0,
     0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xE0, 0x1C, 0x70,
     0x38, 0x38, 0x78, 0x3C, 0x78, 0x3C, 0x78, 0x3C, 0x38, 0x38, 0x00, 0x78, 0x00, 0x70, 0x00, 0xE0,
     0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x0C, 0x38, 0x1C, 0x70, 0x3C, 0x7F, 0xF8,
     0x7F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xC0, 0x38, 0xF0,
     0x38, 0x78, 0x78, 0x78, 0x38, 0x78, 0x00, 0x78, 0x00, 0x70, 0x00, 0xE0, 0x07, 0xC0, 0x00, 0xF0,
     0x00, 0x78, 0x00, 0x38, 0x00, 0x3C, 0x00, 0x3C, 0x78, 0x3C, 0x78, 0x38, 0x78, 0x38, 0x38, 0xF0,
     0x0F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xE0, 0x01, 0xE0,
     0x03, 0xE0, 0x03, 0xE0, 0x07, 0xE0, 0x0E, 0xE0, 0x0C, 0xE0, 0x1C, 0xE0, 0x18, 0xE0, 0x30, 0xE0,
     0x70, 0xE0, 0x60, 0xE0, 0xFF, 0xFC, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0xE0, 0x01, 0xF0,
     0x07, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF8, 0x3F, 0xF8,
     0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x30, 0x00, 0x37, 0xE0, 0x3C, 0x70, 0x38, 0x38,
     0x10, 0x3C, 0x00, 0x3C, 0x00, 0x3C, 0x78, 0x3C, 0x78, 0x3C, 0x78, 0x38, 0x38, 0x78, 0x38, 0xF0,
     0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xF0, 0x0E, 0x78,
     0x1C, 0x78, 0x38, 0x78, 0x38, 0x00, 0x78, 0x00, 0x70, 0x00, 0x77, 0xE0, 0x7E, 0x78, 0x78, 0x38,
     0x78, 0x3C, 0x70, 0x3C, 0x70, 0x1C, 0x70, 0x1C, 0x78, 0x3C, 0x38, 0x3C, 0x3C, 0x38, 0x1E, 0x70,
     0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFC, 0x3F, 0xF8,
     0x78, 0x38, 0x70, 0x30, 0x60, 0x60, 0x00, 0x60, 0x00, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x03, 0x80,
     0x03, 0x80, 0x03, 0x80, 0x07, 0x80, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x0F, 0x00, 0x0F, 0x00,
     0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xE0, 0x3C, 0x70,
     0x38, 0x38, 0x70, 0x3C, 0x70, 0x1C, 0x70, 0x1C, 0x38, 0x38, 0x3E, 0x70, 0x0F, 0xE0, 0x1F, 0xE0,
     0x38, 0xF0, 0x70, 0x78, 0x70, 0x3C, 0x70, 0x1C, 0x70, 0x1C, 0x70, 0x1C, 0x70, 0x38, 0x3C, 0x70,
     0x0F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xC0, 0x3C, 0x70,
     0x38, 0x38, 0x78, 0x38, 0x70, 0x3C, 0x70, 0x3C, 0x70, 0x1C, 0x70, 0x3C, 0x70, 0x3C, 0x78, 0x7C,
     0x3C, 0xFC, 0x1F, 0xFC, 0x00, 0x3C, 0x00, 0x38, 0x00, 0x38, 0x38, 0x70, 0x38, 0x70, 0x3D, 0xE0,
     0x1F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

#endif