#include "interface.h"
#include "ui_interface.h"
#include <QPainter>

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(m_largeur, m_hauteur);
}

QPoint Interface::coo(double x, double y)
{
    return QPoint(int(m_unite*x + m_largeur/2), int(-m_unite*y+m_hauteur/2));
}

void Interface::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen black(Qt::black,2);
    painter.setPen(black);
    painter.drawLine(coo(-5,0), coo(5,0));
    painter.drawLine(coo(0,5), coo(0,-5));
}

