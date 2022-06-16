#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include "rectarea.h"
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    for(int i = 0; i<rects.size(); i++){
        rects[i]->draw(&painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){

    Rect *r = nullptr;
    QPoint point_1;

    if(event->modifiers() & Qt::ControlModifier){

        if(check_points % 2 == 0){
            point_2 = event->pos();
            check_points++;
        }
        else if(check_points % 2 == 1){
            QPoint point_1 = event->pos();
            r = new Rect(point_1.x(), point_1.y(), point_2.x(), point_2.y());
            check_points++;
        }
    }
    else{
        int c = 0;
        QRect contents_window = contentsRect();
        int c_x_max = contents_window.width();
        int c_y_max = contents_window.height();
        int c_x_min = 0;
        int c_y_min = 0;
        for(int i=0; i < rects.size(); i++)
            if(rects[i]->contains(event->x(), event->y())){
                RectArea *p = dynamic_cast<RectArea *>(rects[i]);
                if(!p){
                    c_x_max = c_x_max < rects[i]->getMax_x() ? c_x_max : rects[i]->getMax_x();
                    c_y_max = c_y_max < rects[i]->getMax_y() ? c_y_max : rects[i]->getMax_y();
                    c_x_min = c_x_min > rects[i]->getMin_x() ? c_x_min : rects[i]->getMin_x();
                    c_y_min = c_y_min > rects[i]->getMin_y() ? c_y_min : rects[i]->getMin_y();
                    c++;
                }
            }
        r = new RectArea(c_x_min, c_y_min, c_x_max, c_y_max, c);
    }
    if(r)
        rects.append(r);

    for(int i = 0; i<rects.size(); i++){
        RectArea *first_rectarea = dynamic_cast<RectArea *>(rects[i]);
        if(first_rectarea){
            for(int k = i+1; k<rects.size(); k++){
                RectArea *second_rectarea = dynamic_cast<RectArea *>(rects[k]);
                if(second_rectarea){
                    if(first_rectarea->getRect_count() > second_rectarea->getRect_count()){
                        RectArea *m = dynamic_cast<RectArea *>(rects[k]);
                        rects[k] = rects[i];
                        rects[i] = m;
                    }
                }
            }
        }
    }
    repaint();
}
