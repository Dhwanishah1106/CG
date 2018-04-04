#include "pixel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pixel w;
    //w.assign();
   // w.on_pushButton_clicked();
   //w.on_pushButton_2_clicked();
    w.show();

    return a.exec();
}
