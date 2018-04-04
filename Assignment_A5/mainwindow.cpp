#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage image(901,741,QImage::Format_RGB888);

QRgb white =qRgb(255,255,255);
QRgb black =qRgb(0,0,0);
QRgb red =qRgb(255,0,0);
QRgb green =qRgb(0,255,0);
QRgb blue =qRgb(0,0,255);
QRgb variable =qRgb(255,255,255);

int MainWindow::sign(int a)
{
    if(a>0)
    {
        return 1;
    }
    else if(a<0)
    {
        return -1;
    }
    else
        return 0;
}

void MainWindow::line(int x1, int y1, int x2, int y2)
{
            int dx,dy,e;
            int x,y;
            int inter,i=0;
            int s1,s2;
             x=x1;
             y=y1;
         dx=abs(x2-x1);
         dy=abs(y2-y1);
         s1=sign(x2-x1);
         s2=sign(y2-y1);
         if(dx<dy)
         {
             int temp=dx;
             dx=dy;
             dy=temp;
             inter=1;
         }
         else
         {
             inter=0;
         }
             e=(2*dy)-dx;
             for(i=0;i<dx;i++)
             {
                 image.setPixel(x,y,variable);

                 while(e>=0)
                 {
                     if(inter==1)
                     {
                         x=x+s1;
                     }
                     else
                     {
                         y=y+s2;
                     }
                     e=e-(2*dx);
                 }
                 if(inter==1)
                 {
                     y=y+s2;
                 }
                 else
                 {
                     x=x+s1;
                 }
                 e=e+(2*dy);
             }

             ui->Output->setPixmap(QPixmap::fromImage(image));
}

int i=0;
int x1,y1,x2=0,y2=0;

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QString x= QString::number(event->x());
    QString y= QString::number(event->y());

    if(i%2==0)
    {
        x1=x.toInt();
        y1=y.toInt();
        if(x2!=0 && y2!=0)
        {
            line(x1,y1,x2,y2);
        }
    }

    else
    {
        x2=x.toInt();
        y2=y.toInt();
        line(x1,y1,x2,y2);
    }
i++;
}


void MainWindow::on_radioButton_clicked()
{
    variable=red;
}

void MainWindow::on_radioButton_2_clicked()
{
    variable=blue;
}

void MainWindow::on_radioButton_3_clicked()
{
    variable=green;
}


void MainWindow::on_radioButton_4_clicked()
{
    variable=white;
}
