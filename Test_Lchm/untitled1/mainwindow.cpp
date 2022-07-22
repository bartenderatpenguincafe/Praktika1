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
    h = 0.000001;
    xBegin = 0 ;
    xEnd = 10e-5;
    d_f = 1e5;
    ui->widget->xAxis->setRange(0,20e-5);
    ui->widget->yAxis->setRange(-3,3);

    for(X = xBegin ; X<= xEnd; X += h)
    {
        double x_rab = A*cos((X*0)+(2*pi*d_f*(X*X))/(2*xEnd));
        x.push_back(X);
        y.push_back(x_rab);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
}




