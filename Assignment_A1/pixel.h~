#ifndef PIXEL_H
#define PIXEL_H
#include <QMainWindow>
namespace Ui {
class Pixel;
}
class Pixel : public QMainWindow
{
    Q_OBJECT
public:
    explicit Pixel(QWidget *parent = 0);
    ~Pixel();
    double x,y,len,heig;
    int sign(double );
    void dda(double, double, double, double);
    void bresenham(double, double, double, double);
    void assign();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Pixel *ui;
};
#endif // PIXEL_H
