#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QPoint>

class Interface : public QWidget
{
    Q_OBJECT

private:
    int m_largeur=900;
    int m_hauteur=600;
    double m_unite_x=50;
    double m_unite_y=50;
    double m_amp_cos=1;
    double m_amp_sin=1;

public:
    Interface(QWidget *parent = nullptr);
    QPoint coo(double x, double y);
    void paintEvent(QPaintEvent *event) override;

public slots:
    void changeEchelle(int h);
    void changeAmpCos(int amp_cos);
    void changeAmpSin(int amp_sin);
};
#endif // INTERFACE_H
