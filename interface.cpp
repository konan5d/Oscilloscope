#include "interface.h"
#include "ui_interface.h"
#include <QPainter>
#include <QPen>
#include <cmath>
#include <QPolygonF>

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(m_largeur=900, m_hauteur=600);
}

QPoint Interface::coo(double x, double y)
{
    return QPoint(int(m_unite_x*x + m_largeur/2), int(-m_unite_y*y+m_hauteur/2));
}

void Interface::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen black(Qt::black,2);
    QPen red(Qt::red,2);
    QPen gray(Qt::gray,1);
    QPen blue(Qt::blue,2);
    painter.setPen(black);
    painter.drawLine(coo(-500,0), coo(500,0));
    painter.drawLine(coo(0,500), coo(0,-500));

    painter.setPen(gray);
    double x_unite = 0;
    double y_unite = 0;

    for(x_unite=-500;x_unite<=500;x_unite+=1){
        painter.drawLine(coo(-500,x_unite), coo(500,x_unite));
    }

    for(y_unite=-500;y_unite<=500;y_unite+=1){
        painter.drawLine(coo(y_unite,-500), coo(y_unite,500));
    }

    painter.setPen(red);
    QPolygonF polygon_cos;

    double x_i=0;
    double x = 0;
    double y = 0;
    for(x_i=-500;x_i<=500;x_i=x_i+0.01){
        x = x_i;
        y = m_amp_cos*sin(x);
        polygon_cos<<coo(x,y);
    }
    painter.drawPolyline(polygon_cos);

    painter.setPen(blue);
    QPolygonF polygon_sin;

    double sin_x_i=0;
    double sin_x = 0;
    double sin_y = 0;
    for(sin_x_i=-500;sin_x_i<=500;sin_x_i=sin_x_i+0.01){
        sin_x = sin_x_i;
        sin_y = m_amp_sin*cos(sin_x);
        polygon_sin<<coo(sin_x,sin_y);
    }
    painter.drawPolyline(polygon_sin);
}

void Interface::changeEchelle(int h)
{
    m_unite_x = h;
    m_unite_y = h;
    repaint();
}

void Interface::changeAmpCos(int amp_cos)
{
    m_amp_cos = amp_cos;
    repaint();
}

void Interface::changeAmpSin(int amp_sin)
{
    m_amp_sin = amp_sin;
    repaint();
}


