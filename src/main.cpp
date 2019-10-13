#include <QApplication>
#include <QtCore/QVariant>
#include <iostream>
#include <window.h>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QMainWindow window;

 Ui_MainWindow win;

 win.setupUi(&window);
 
 window.show();

 return app.exec();
}