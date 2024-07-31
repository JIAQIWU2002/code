#include "food.hpp"
#include <time.h>
#include <random>
#include <algorithm>

Food::Food(Map *map, Color color) : _color(color), _map(map)
{
    _rect = Rect(_map->cellSize(), _map->cellSize(), Point(0, 0), _color);
    this->put();
}
Food::~Food()
{
}
void Food::draw()
{
    _rect.draw();
}
void Food::put()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis1(0, 40);
    std::uniform_int_distribution<int> dis2(0, 30);
    std::uniform_int_distribution<int> dis3(0, 200);
    int x = dis1(gen);
    int y = dis2(gen);
    _rect.move(_map->cellPosition(x, y));
}

Point Food::pos() const
{
    return _rect.pos();
}