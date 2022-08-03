#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVector>
#include <QtGui>
#include <complex>
#include <cmath>
#include <iostream>


using std::ifstream;
using std::ofstream;
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void getData();
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    int N_repeat,lchm_d,T_d, I_b[13],f_n;
    double xBegin_1,xBegin_2,xEnd_1 ,xEnd_2,xBegin_3,xEnd_3, xBegin_4 ,xEnd_4, h , x_rab ,X , A , d_f ,T , fs,pi = 3.14159265359, new_T,tau,t_i, T_ppi[5]{160e-5,180e-5,10e-5,45e-5,96e-5},phi,T_a;
    QVector<double> x,y,y_real,y_image,y_real_temp,y_image_temp,x_temp;
    QVector<std::complex<double>> x_c,y_c ;
    std::complex<double> x_rab_c, X_c,t_d_a,t_d_b;
    const std::complex<double> _i = { 0, 1 };
    QVector<int> m_k_b;
};

#endif // MAINWINDOW_H
