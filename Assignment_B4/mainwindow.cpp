/*Write C++/Java program to implement reflection of 2-D object about X axis,
 Y axis and about X=Y axis. Also rotate object about arbitrary point given
 by user.*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
 QImage image(881,441, QImage::Format_RGB888);
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

void MainWindow::translate(int tx, int ty)
{


    for(int i=0;i<881;i++)
    {
        image.setPixel(i, ty, qRgb(255,0,0));
    }
    for(int i=0;i<441;i++)
    {
        image.setPixel(tx, i, qRgb(255,0,0));
    }
 ui->label_5->setPixmap(QPixmap::fromImage(image));
 }

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


void MainWindow::on_pushButton_clicked()
{

    int x= ui->textEdit_3->toPlainText().toInt();
    int y= ui->textEdit_4->toPlainText().toInt();
    int leng= ui->textEdit_7->toPlainText().toInt();
    int heig= ui->textEdit_8->toPlainText().toInt();
    int f= ui->textEdit_6->toPlainText().toInt();


    translate(440,220);
    line(x,y,x+leng,y,f);
    line(x,y,x,y+heig,f);
    line(x,y+heig,x+leng,y+heig,f);
    line(x+leng,y,x+leng,y+heig,f);
    //line(x1,y1,x2,y2,f);
}

void MainWindow::matrix_mul()
{
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<2;j++)
        {

            final[i][j]=0;
            for(int k=0;k<2;k++)
            {
                final[i][j]=final[i][j]+(original[i][k]*trans[k][j]);
            }
        }
    }

}


void MainWindow::reflection(int x1, int y1, int flag)
{
    int tx= ui->textEdit->toPlainText().toInt();
    int ty= ui->textEdit_2->toPlainText().toInt();
    int t=ui->textEdit_5->toPlainText().toInt();

    float theta=float ((3.14*t)/180);  //Converting into Radian


    original[0][0]=x1;
    original[0][1]=y1;

    if(flag==1)  //Reflection about X-axis
    {
        trans[0][0]=1;
        trans[0][1]=0;
        trans[1][0]=0;
        trans[1][1]=-1;
    }

    else if(flag==2)  //Reflection about Y-axis
    {
        trans[0][0]=-1;
        trans[0][1]=0;
        trans[1][0]=0;
        trans[1][1]=1;
    }

   else if(flag==3)  //Reflection about Y=X
    {
        trans[0][0]=0;
        trans[0][1]=1;
        trans[1][0]=1;
        trans[1][1]=0;
    }

   else if(flag==4) //Rotation by Theta
    {
        trans[0][0]=cos(theta);
        trans[0][1]=sin(theta);
        trans[1][0]=-sin(theta);
        trans[1][1]=cos(theta);
    }

    else if(flag==5)   //Rotation about point
    {
        trans[0][0]=cos(theta);
        trans[0][1]=sin(theta);
        trans[1][0]=-sin(theta);
        trans[1][1]=cos(theta);

        original[0][0]=x1-tx;
        original[0][1]= y1-ty;

        matrix_mul();

        final[0][0]= final[0][0]+tx;
        final[0][1]= final[0][1]+ty;

       goto label;

    }

    else            //Same point will be plotted
    {
        trans[0][0]=1;
        trans[0][1]=0;
        trans[1][0]=0;
        trans[1][1]=1;
    }

    matrix_mul();
  label:  image.setPixel(440+final[0][0],220-final[0][1], qRgb(255,255,255));
    ui->label_5->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::line(int x1, int y1, int x2, int y2, int f)
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
                 image.setPixel(440+x,220-y,qRgb(0,0,255));
                 reflection(x,y,f);

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
             ui->label_5->setPixmap(QPixmap::fromImage(image));
}
