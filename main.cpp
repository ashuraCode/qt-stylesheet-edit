#include "ashurawind.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AshuraWind w;
    w.show();

    return a.exec();
}
