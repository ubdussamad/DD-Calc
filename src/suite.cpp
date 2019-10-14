#include <iostream>
#include <window.h>
#include <string>

class calc {
public:
	std::string buffer;
	std::string last_buffer;
	std::string push ( std::string word );
	void clear ( void );
	std::string parse ( void );
};

std::string calc::push( std::string word ) {
	buffer = buffer + word;
	return (buffer);
}

std::string calc::parse (void) {
	// Process buffer here
	return("Result");
}

void calc::clear (  void ) {
	buffer = "";
	return;
}


void Ui_MainWindow::connect_signals (QMainWindow *MainWindow) {
  QObject::connect(pushButton , SIGNAL (clicked()), this , SLOT(handleButton())  ); 
  QObject::connect(pushButton_2, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_3, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_4, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_5, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_6, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_7, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_8, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_9, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_10, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_11, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_12, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_13, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_14, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_15, SIGNAL(clicked()), this, SLOT(handleButton()) );
  QObject::connect(pushButton_17, SIGNAL(clicked()), this, SLOT(handleButton()) );
  

}

calc instance;

void Ui_MainWindow::handleButton () {
  
  QPushButton * stuff =  (QPushButton *) QObject::sender();

  std::string key_string = stuff->text().toUtf8().constData();

  if (key_string == "=") {
  	// Suite for processing the buffer
  	label->setText( QString::fromUtf8( instance.parse().c_str() ) );
  	return;
  }

  else if (key_string == "C") {
  	instance.clear();
  	label->setText("");
  	return;
  }

  else {
  	std::string buff = instance.push(key_string);
  	QString str = QString::fromUtf8(buff.c_str());
  	label->setText(str);
}
  return;
}
