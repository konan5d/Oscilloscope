#include "interface.h"

#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget x;
    x.show();
    return a.exec();
}
