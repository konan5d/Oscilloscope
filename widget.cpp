#include "widget.h"
#include "interface.h"
#include "lcdrange.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <Qt>
#include <QApplication>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    int val_l=70;
    int val_h=1;
    //instanciation des widgets
    Interface *f=new Interface(this);
    LcdRange *freq=new LcdRange(this, "Echelle ",3,1,200,val_l);
    LcdRange *amp=new LcdRange(this, "Amplitude f1(V)",2,1,20,val_h);
    LcdRange *amp2=new LcdRange(this, "Amplitude f2(V)",2,1,20,val_h);

    QPushButton *quit= new QPushButton("Quitter");
    quit->setFixedSize(200,30);
    //instanciation du layout
    QGridLayout *gridLayout =new QGridLayout;
    gridLayout->addWidget(f,0,0,1,0);
    gridLayout->addWidget(freq,1,0);
    gridLayout->addWidget(amp,2,0);
    gridLayout->addWidget(amp2,3,0);
    gridLayout->addWidget(quit,3,1);
    setLayout(gridLayout);

    //connexion des signaux aux slots :
    connect(freq,SIGNAL(valueChanged(int)),f,SLOT(changeEchelle(int)));
    connect(amp,SIGNAL(valueChanged(int)),f,SLOT(changeAmpCos(int)));
    connect(amp2,SIGNAL(valueChanged(int)),f,SLOT(changeAmpSin(int)));
    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));

    //init de l'affichage, en fonction des valeurs mises en paramètre
    emit freq->valueChanged(val_l);
    emit amp->valueChanged(val_h);
    emit amp2->valueChanged(val_h);
}
