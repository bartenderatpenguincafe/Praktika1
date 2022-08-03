/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QLabel *N_label;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(707, 437);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 521, 361));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(550, 0, 151, 142));
        gridLayout_6 = new QGridLayout(layoutWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_4->addWidget(lineEdit_5, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_4->addWidget(lineEdit_4, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 1, 0, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(550, 150, 151, 111));
        gridLayout_7 = new QGridLayout(layoutWidget1);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 0, 1, 1);

        N_label = new QLabel(centralWidget);
        N_label->setObjectName(QString::fromUtf8("N_label"));
        N_label->setGeometry(QRect(550, 330, 71, 41));
        QFont font;
        font.setPointSize(20);
        N_label->setFont(font);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(550, 270, 151, 51));
        gridLayout_8 = new QGridLayout(layoutWidget2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(layoutWidget2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_8->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_8->addWidget(pushButton_6, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 707, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Tau = ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "A =", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "T= ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "N = ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "D_F = ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264 \320\221\320\260\321\200\320\272\320\265\321\200\320\260 ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\233\320\247\320\234.\320\270\320\274\320\277", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\321\213\320\271.\320\270\320\274\320\277", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\261\321\203\320\273\321\217\321\206\320\270\321\217 \320\237\320\237\320\230", nullptr));
        N_label->setText(QCoreApplication::translate("MainWindow", "x #", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
