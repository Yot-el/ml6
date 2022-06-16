#include "rectarea.h"
#include <QPainter>

RectArea::RectArea()
    :Rect(0, 0, 0, 0)
{

}

RectArea::RectArea(int x1, int y1, int x2, int y2, int rect_count)
    :Rect(x1, y1, x2, y2)
{
    this->rect_count = rect_count;
}

void RectArea::draw(QPainter *painter)
{
    if(rect_count == 2){
        QBrush brush(QColor(255,0,0));
        painter->setBrush(brush);
        painter->drawRect(QRect(min_x, min_y, (max_x - min_x), (max_y - min_y)));
    }
    else if(rect_count == 3){
        QBrush brush(QColor(255,255,0));
        painter->setBrush(brush);
        painter->drawRect(QRect(min_x, min_y, (max_x - min_x), (max_y - min_y)));
    }
    else if(rect_count == 4){
        QBrush brush(QColor(0,255,0));
        painter->setBrush(brush);
        painter->drawRect(QRect(min_x, min_y, (max_x - min_x), (max_y - min_y)));
    }
    else if(rect_count == 5){
        QBrush brush(QColor(0,0,255));
        painter->setBrush(brush);
        painter->drawRect(QRect(min_x, min_y, (max_x - min_x), (max_y - min_y)));
    }
    else if(rect_count >= 6){
        QBrush brush(QColor(0,0,0));
        painter->setBrush(brush);
        painter->drawRect(QRect(min_x, min_y, (max_x - min_x), (max_y - min_y)));
    }
}

int RectArea::getRect_count() const
{
    return rect_count;
}
