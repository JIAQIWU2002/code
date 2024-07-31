#include "screen.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;

Screen *Screen::instance()
{
	static Screen s("/dev/fb0");
	return &s;
}

Screen::Screen(const char *name)
{
	_name = name;
	_w = 800;
	_h = 480;
	_bpp = 32;
	_fd = ::open(name, O_RDWR);
	if (_fd == -1)
	{
		perror("open screen error");
		exit(1);
	}
	_addr = (int *)mmap(NULL, _w * _h * _bpp / 8, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
	if (_addr == MAP_FAILED)
	{
		perror("mmap error");
		exit(1);
	}
	cout << "open screen success!" << endl;
}
Screen::~Screen()
{
	munmap(_addr, _w * _h * _bpp / 8);
	::close(_fd);
}

void Screen::draw_point(int x, int y, int color)
{
	if (x >= 0 && x < _w && y >= 0 && y < _h)
	{
		*(_addr + _w * y + x) = color;
	}
}

void Screen::draw_point(Point pos, Color color)
{
	draw_point(pos.x(), pos.y(), color.value());
}


void Screen::lcd_draw_word(char *ch, int len, int w, int color, int x0, int y0)
{
	int i, j;
	int x, y;
	int flag = w / 8;
	// 遍历整个点阵数组
	for (i = 0; i < len; i++)
	{
		for (j = 7; j >= 0; j--)
		{
			// if (ch[i] & (0x80/pow(2,7-j)))
			if ((ch[i] >> j) & 1)
			{
				x = 7 - j + 8 * (i % flag) + x0;
				y = i / flag + y0;
				draw_point(x, y, color);
			}
		}
	}
}

void Screen::lcd_draw_digit(int value, int x0, int y0, int color)
{
	int i = 0;
	if (value == 0)
	{
		lcd_draw_word(w_digit[0], sizeof(w_digit[0]), 16, color, x0 + 48 - 16 * i, y0);
	}

	// 当分数的值超过了一位数，那么有多个数字需要同时显示出来。
	while (value)
	{
		int x;
		x = value % 10;
		lcd_draw_word(w_digit[x], sizeof(w_digit[x]), 16, color, x0 + 48 - 16 * i, y0);
		value = value / 10;
		i++;
	}
}

void Screen::lcd_draw_rectanle()
{
	int i, j;
	for (i = 700; i < 800; i++)
	{
		for (j = 0; j < 32; j++)
			draw_point(i, j, 0xffffff);
	}
}

void Screen::clear_led()
{
	int i, j;
	for (i = 0; i < 800; i++)
	{
		for (j = 0; j < 480; j++)
			draw_point(i, j, 0xffffff);
	}
}
