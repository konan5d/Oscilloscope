#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QWidget>

class LcdRange : public QWidget
{
    Q_OBJECT
public:
    explicit LcdRange(QWidget *parent = nullptr, QString label="", uint nblcd=3, int min=0, int max=999, int valDep=-1);

signals:
    void valueChanged(int);
public slots:
};

#endif // LCDRANGE_H
