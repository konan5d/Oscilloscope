#include "lcdrange.h"
#include <QLCDNumber> //Affichage LCD
#include <QSlider>  //Slider
#include <QLabel> //Label
#include <QHBoxLayout> //Organisation du layout
#include <QApplication>

LcdRange::LcdRange(QWidget *parent, QString label, uint nblcd, int min, int max, int valDep) : QWidget(parent)
{
    //création des objets widgets utilisés
    QLabel *l=new QLabel(label);
    QSlider *qs= new QSlider(Qt::Horizontal);
    qs->setRange(min,max);
    //si la valeur de départ = -1
    int val;
    if(valDep == -1)
        // on fixe la valeur de départ au milieu du slider
        val=(min+max)/2;
    else
        // sinon on fixe la valeur, à la valeur donnée
        val=valDep;

    qs->setValue(val);
    QLCDNumber *qlcd=new QLCDNumber(nblcd);
    QHBoxLayout *qh=new QHBoxLayout();

    //insertion des widgets dans le layout
    qh->addWidget(l);
    qh->addWidget(qs);
    qh->addWidget(qlcd);
    setLayout(qh);

    //connexion des signaux
    connect(qs,SIGNAL(valueChanged(int)),qlcd,SLOT(display(int)));
    emit qs->valueChanged(val);
    connect(qs,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
}

