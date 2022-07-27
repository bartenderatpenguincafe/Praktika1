#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    A = 1;
    fs = 1.28e7;
    h = 1/fs;
    xBegin_1 = 0 ;
    xBegin_2 = 0 ;
    xBegin_3 = 0 ;
    tau = 10e-5;
    xEnd_1 = tau;
    xEnd_2 = tau;
    xEnd_3 = tau;
    d_f = 1e5;
    f_n = 0;
    T = 100e-5;
    T_a = tau/13;
    new_T = T+xEnd_2;
    N_repeat = 3;
    I = sqrt(-1);
    ui->widget->xAxis->setRange(0,3*(T*1.2));
    ui->widget->yAxis->setRange(-(A*2),(A*2));
    Vector_clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getData()
{
   // A = ui->lineEdit->text().toDouble();
}


void MainWindow::on_pushButton_clicked() //ЛЧМ импульс
{
    Vector_clear();
    for (int i = 0 ; i< N_repeat; i++)
     {
     new_T = (i+1)*new_T;
     for(X = xBegin_2 ; X<= xEnd_2; X += h)
     {
         x_rab = x_rab = A*cos((X*0)+(2*pi*d_f*(X*X))/(2*xEnd_2));
         Vector_push_back(x_rab);
     }
     draw_graph();
     for(X = xEnd_2 ; X<= new_T; X += h)
     {
         x_rab = 0;
         Vector_push_back(x_rab);
     }
     xBegin_2 = xEnd_2+T;
     xEnd_2 = xBegin_2+tau;
    }
    draw_graph();
}


void MainWindow::on_pushButton_2_clicked() //прямоугольный импльс
{
    Vector_clear();
    for (int i = 0 ; i< N_repeat; i++)
     {
     new_T = (i+1)*new_T;
     for(X = xBegin_1 ; X<= xEnd_1; X += h)
     {
         x_rab_c = A*exp(I*0);
         x_c.push_back(X);
         y_c.push_back(x_rab);
     }
     draw_graph();
     for(X = xEnd_1 ; X<= new_T; X += h)
     {
         x_rab = 0;
         Vector_push_back(x_rab);
     }
     xBegin_1 = xEnd_1+T;
     xEnd_1 = xBegin_1+tau;
    }
    draw_graph();
}

void MainWindow::on_pushButton_3_clicked()//код Баркера
{
    Vector_clear();
    for (int i = 0 ; i< N_repeat; i++)
     {
     new_T = (i+1)*new_T;
     for(X = xBegin_1 ; X<= xEnd_1; X += h)
     {
         for (int k = 0 ; k < 13; k++)
         {
         if (I_b[k] == -1)
         {
         phi = pi;
         x_rab = A*cos((X*X*2*pi*f_n/(T_a*2))+phi);
         Vector_push_back(x_rab);
         }
         else
         {
         phi = 0 ;
         x_rab = A*cos((X*X*2*pi*f_n/(T_a*2))+phi);
         Vector_push_back(x_rab);
         }
         }
     }
     draw_graph();
     for(X = xEnd_1 ; X<= new_T; X += h)
     {
         x_rab = 0;
         Vector_push_back(x_rab);
     }
    xBegin_1 = xEnd_1+T;
    xEnd_1 = xBegin_1+tau;
    }
    draw_graph();
}

void MainWindow::on_pushButton_4_clicked()//вобуляция ППИ
{
    Vector_clear();
    for (int i = 0 ; i< 3; i++)
     {
     double new_T_ppi = T_ppi[i];
     new_T_ppi = (i+1)* new_T_ppi;
     for(X = xBegin_3 ; X< xEnd_3; X += h)
     {
         x_rab = A*cos(X*0);
         Vector_push_back(x_rab);
     }
     draw_graph();
     for(X = xEnd_3 ; X< new_T_ppi; X += h)
     {
         x_rab = 0;
         Vector_push_back(x_rab);
     }
     xBegin_3 = xEnd_3+T_ppi[i];
     xEnd_3 = xBegin_3+tau;
    }
    draw_graph();
}

void MainWindow::on_pushButton_6_clicked()//запись в файл
{
    QFile save_signal("C:\\Users\\Гогма\\Documents\\save_signal.txt");//забавный юзер-нейм
    if(save_signal.open(QIODevice::WriteOnly)){

        QTextStream textStream(&save_signal);
        QStringList stringList;
        for( int c = 0; c < y.size(); c++ )
                    {

                        textStream<<x.at(c)<<"       "<<y.at(c)<<endl;
                    }
        textStream << stringList.join( ';' )+"\n";
    }
    save_signal.close();
}

void MainWindow::draw_graph()
{
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
}

double MainWindow::Vector_push_back(double x_rab)
{
    x.push_back(X);
    y.push_back(x_rab);
    return 0;
}

void MainWindow::Vector_clear()
{
    ui->widget->clearGraphs();
    x.clear();
    y.clear();
}



