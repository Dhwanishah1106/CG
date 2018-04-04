#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    float original[1][2], final[1][2],trans[2][2];

    void translate(int ,int);
    void matrix_mul();

    void reflection(int, int, int);
    void line(int, int, int, int, int);
    int sign(int );
private:
    Ui::MainWindow *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
