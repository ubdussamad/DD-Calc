/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <iostream>
// #include <QMainWindow>
// #include <QPushButton>

QT_BEGIN_NAMESPACE

 // namespace Ui {
 //    class MainWindow;
 // }
 
class Ui_MainWindow : public QMainWindow {
Q_OBJECT  // Bhery importtant for paring signlas and slots andnother stuff too
// Later macro instructs the moc compiler to replace these signals and other mechanisms
// to compiler understandable stuff.

public slots:
    void handleButton();

public:
    void connect_signals(QMainWindow *MainWindow);
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton; // 1 
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_15;
    QPushButton *pushButton_10;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_14;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_13;

    void setupUi(QMainWindow *MainWindow);
    void retranslateUi(QMainWindow *MainWindow);
};




 namespace Ui {
     class MainWindow: public Ui_MainWindow {};
 } // namespace Ui


QT_END_NAMESPACE

#endif // WINDOW_H
