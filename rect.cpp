#include "rect.h"
#include <QPainter>

Rect::Rect()
    :Rect(0,0,0,0)
{

}

Rect::Rect(int x1, int y1, int x2, int y2)
{
    max_x = x1 > x2 ? x1 : x2;
    min_x = x1 < x2 ? x1 : x2;
    max_y = y1 > y2 ? y1 : y2;
    min_y = y1 < y2 ? y1 : y2;
}

void Rect::draw(QPainter *painter)
{
    painter->drawLine(max_x, max_y, max_x, min_y);
    painter->drawLine(max_x, max_y, min_x, max_y);
    painter->drawLine(max_x, min_y, min_x, min_y);
    painter->drawLine(min_x, max_y, min_x, min_y);
}

bool Rect::contains(int x, int y)
{
    if((max_x >= x && x >= min_x) && (max_y >= y && y >= min_y))
        return true;
    return false;
}

int Rect::getMin_x() const
{
    return min_x;
}

void Rect::setMin_x(int newMin_x)
{
    min_x = newMin_x;
}

int Rect::getMin_y() const
{
    return min_y;
}

void Rect::setMin_y(int newMin_y)
{
    min_y = newMin_y;
}

int Rect::getMax_x() const
{
    return max_x;
}

void Rect::setMax_x(int newMax_x)
{
    max_x = newMax_x;
}

int Rect::getMax_y() const
{
    return max_y;
}

void Rect::setMax_y(int newMax_y)
{
    max_y = newMax_y;
}
