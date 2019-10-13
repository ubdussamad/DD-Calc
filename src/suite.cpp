#include <iostream>
#include <window.h>
//#include <Qstring>
// class Calc:
// {
//   QOBJECT
// public:
//   // Public Functions
//   bool load ( double value );
//   std::string buffer;
  
// };

void Ui_MainWindow::connect_signals( void ) {
  QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(handleButton) );
  //  QObject::connect(pushButton, SIGNAL(clicked()), this, [=](){ this->handleButton(pushButton->text())});

}
    
void Ui_MainWindow::handleButton () {
  std::cout << "Hi this is  MEeeeee!.\n";// << value.toUtf8().constData() << "\n";
  //  value.asprintf() 
  label->clear();
  return;
}
