#include "widget.h"
#include "interface.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    //instanciation des widgets
    Interface *f=new Interface(this);

    //instanciation du layout
    QVBoxLayout *qv=new QVBoxLayout();
    qv->addWidget(f);
    setLayout(qv);
}
