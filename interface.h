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
    double m_unite=100;
public:
    Interface(QWidget *parent = nullptr);
    QPoint coo(double x, double y);
    void paintEvent(QPaintEvent *event) override;
};
#endif // INTERFACE_H
