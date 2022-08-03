#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QtGui>
#include <QLineEdit>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fs = 1.28e7;
    h = 1/fs;
    xBegin_2=xBegin_3=xBegin_4=xBegin_1=0;
    xEnd_2=xEnd_3=xEnd_4=xEnd_1= tau;
    f_n = 0;
    connect(ui->lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(getData()));//A
    connect(ui->lineEdit_2,SIGNAL(textChanged(const QString &)),this,SLOT(getData()));//tau
    connect(ui->lineEdit_3,SIGNAL(textChanged(const QString &)),this,SLOT(getData()));//T
    connect(ui->lineEdit_4,SIGNAL(textChanged(const QString &)),this,SLOT(getData()));//d_f
    connect(ui->lineEdit_5,SIGNAL(textChanged(const QString &)),this,SLOT(getData()));//N_repeat
    ui->widget->setNoAntialiasingOnDrag(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getData()
{
  A = ui->lineEdit->text().toDouble();//1
  N_repeat = ui->lineEdit_5->text().toInt();//3
  ui->N_label->setText(QString( "x" )+ QString::number(N_repeat) );
  tau = ui->lineEdit_2->text().toDouble(); //10e-5;
  T = ui->lineEdit_3->text().toDouble();//100e-5;
  d_f = ui->lineEdit_4->text().toDouble();//1e5;
  T_a = tau/13;
  new_T = T+tau;
}


void MainWindow::on_pushButton_clicked() //ЛЧМ импульс
{
    ui->widget->xAxis->setRange(0,1.5*T);
    ui->widget->yAxis->setRange((-A*1.2),(A*1.2));
    ui->widget->clearGraphs();
    x.clear();
    y_real.clear();
    y_image.clear();
         for(X = 0 ; X<= tau; X += h)
         {
             x_rab_c = A*exp(_i*((X*0)+(2*pi*d_f*(X*X))/(2*tau)));
             x.append(X);
             y_real.append(real(x_rab_c));
             y_image.append(imag(x_rab_c));
         }
         ui->widget->addGraph();
         ui->widget->graph(0)->addData(x,y_real);
         ui->widget->replot();

         for(X = tau ; X<= new_T; X += h)
         {
             x_rab_c = 0;
             x.append(X);
             y_real.append(real(x_rab_c));
             y_image.append(imag(x_rab_c));
         }
         ui->widget->addGraph();
         ui->widget->graph(0)->addData(x,y_real);
         ui->widget->replot();

}


void MainWindow::on_pushButton_2_clicked() //прямоугольный импльс
{

    ui->widget->xAxis->setRange(0,1.5*tau);
    ui->widget->yAxis->setRange((-A*0.001),(A*1.2));
    ui->widget->clearGraphs();
    x.clear();
    y_real.clear();
    y_image.clear();
    for(X = xBegin_1 ; X<= xEnd_1; X += h)
    {

        x_rab_c = A*exp(_i*((X*0)+(2*pi*(X*X))/(2*xEnd_1)));
        x.append(X);
        y_real.append(real(x_rab_c));
        y_image.append(imag(x_rab_c));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y_real);
    ui->widget->replot();


    for(X = xEnd_1 ; X<= new_T; X += h)
    {
        x_rab_c = 0;
        x.append(X);
        y_real.append(real(x_rab_c));
        y_image.append(imag(x_rab_c));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y_real);
    ui->widget->replot();

}

void MainWindow::on_pushButton_3_clicked()//код Баркера
{
    ui->widget->clearGraphs();
    x.clear();
    y_real.clear();
    y_image.clear();

    ui->widget->xAxis->setRange(0,T*0.4);
    ui->widget->yAxis->setRange((-A*0.001),(A*1.2));

double T_a_new = T_a ;
int MBk[13]{1,1,1,1,1,-1,-1,1,1,-1,1,-1,1};////массив баркера

for (int ijl = 0; ijl < 13; ijl++){

    for(X = 0 ; X<= T_a_new; X += h)
    {
        if (MBk[ijl]==1)
        {phi = 0;
            x_rab_c = A*exp(_i*(((X*0)+(2*pi*(X*X))/(2*T_a))+phi));
            x.push_back(X);
            y_real.push_back(real(x_rab_c));
            y_image.push_back(imag(x_rab_c));
        }

        else{
        phi = pi ;
        x_rab_c = A*exp(_i*(((X*0)+(2*pi*(X*X))/(2*T_a))+phi));
        x.push_back(X);
        y_real.push_back(real(x_rab_c));
        y_image.push_back(imag(x_rab_c));
        }

    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y_real);
    QPen pen;
    pen.setColor(QColor(0,0,255));
    pen.setWidth(4);
    ui->widget->replot();

xBegin_1 = T_a;
T_a_new += T_a;
}

for(X = xEnd_1 ; X<= new_T; X += h)
{
    x_rab_c = 0;
    x.append(X);
    y_real.append(real(x_rab_c));
    y_image.append(imag(x_rab_c));
}
ui->widget->addGraph();
ui->widget->graph(0)->addData(x,y_real);
ui->widget->replot();
}


void MainWindow::on_pushButton_4_clicked()//вобуляция ППИ
{
    ui->widget->clearGraphs();
    x.clear();
    y_real.clear();
    y_image.clear();

    ui->widget->xAxis->setRange(0,6*(T*1.5));
    ui->widget->yAxis->setRange((-A*1.2),(A*1.2));
    double summ=0;
    double T_ppi[6]{160e-5,180e-5,10e-5,45e-5,99e-5,145e-5};
    for (int iop = 0 ;iop < 6 ; iop++){
     new_T +=T_ppi[iop]+tau;
     for(X = xBegin_1 ; X<= xEnd_1; X += h)
     {

         x_rab_c = A*exp(_i*((X*0)+(2*pi*(X*X))/(2*xEnd_1)));
         x.append(X);
         y_real.append(real(x_rab_c));
         y_image.append(imag(x_rab_c));
     }
     ui->widget->addGraph();
     ui->widget->graph(0)->addData(x,y_real);
     ui->widget->replot();


     for(X = xEnd_1 ; X<= new_T; X += h)
     {
         x_rab_c = 0;
         x.append(X);
         y_real.append(real(x_rab_c));
         y_image.append(imag(x_rab_c));
     }
     ui->widget->addGraph();
     ui->widget->graph(0)->addData(x,y_real);
     ui->widget->replot();

     xBegin_1 = new_T;
     xEnd_1 = xBegin_1+tau;
     summ+= xEnd_1;
    }


}

void MainWindow::on_pushButton_6_clicked()//запись в файл
{
    FILE *fp;
    if ((fp=fopen("C:\\text.txt", "wt"))==NULL) {
    perror("Error");
    exit (1);
    }
    for (int ij = 0 ;ij < N_repeat ;ij++)
    for(int vec_pos=0;vec_pos<y_real.size();vec_pos++){
    fwrite(&y_real.at(vec_pos),sizeof(std::complex<double>), 1, fp);
    fwrite(&y_image.at(vec_pos),sizeof(std::complex<double>), 1, fp);
    }
    fclose (fp);
    QMessageBox::information(this,"test","Saved at C:");
}



void MainWindow::on_pushButton_5_clicked()//очистка
{
    ui->widget->clearGraphs();
    x.clear();
    y_real.clear();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y_real);
    ui->widget->replot();
}
