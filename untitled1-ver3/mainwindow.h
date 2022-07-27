#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVector>
#include <complex>
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getData();
    void draw_graph();
    void Vector_clear();
    double Vector_push_back(double x_rab);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();
    
private:
    Ui::MainWindow *ui;
    int N_repeat,lchm_d,T_d, I_b[13]{1,1,1,1,1,-1,-1,1,1,-1,1,-1,1},f_n;
    double xBegin_1,xBegin_2,xEnd_1 ,xEnd_2,xBegin_3,xEnd_3, h , x_rab ,X , A , d_f ,T , fs,pi = 3.14159265359, new_T,tau,t_i, T_ppi[3]{140e-5,130e-5,150e-5},phi,T_a;
    QVector<double> x,y;
    QVector<std::complex<double>> x_c,y_c ;
    std::complex<double> I , x_rab_c, X_c;
};

#endif // MAINWINDOW_H
