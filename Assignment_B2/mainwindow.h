#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPainter>
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void mousePressEvent(QMouseEvent *);
    void line(int , int, int, int);
    int sign(int);
    void seed(int , int, QRgb ,QRgb);

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
