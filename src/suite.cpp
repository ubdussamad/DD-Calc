//#define _GLIBCXX_USE_C99 1
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
	std::string back (void);
};

std::string calc::push( std::string word ) {
		//ascii_code >= 48 && ascii_code <= 57
		int last = ((int)buffer[buffer.size()-1]);
		int s_last = ((int)buffer[buffer.size()-2]);
		int next = (int) word[0];
	if ( !(next >= 48 && next <= 57) and !(last >= 48 && last <= 57) and !(s_last >= 48 && s_last <= 57) and (buffer.size()>2) ) {
		//std::cout << "Last two words are signs.\n";
		return(buffer);
	}
	if (last == 60) {
		buffer = "";
	}
	buffer = buffer + word;
	return (buffer);
}

std::string calc::parse (void) {
	// Process buffer here
	// Flawed LOGIC
	// Please Update 
	std::string::size_type sz;

	long long int result_main = 0;
	long long int buff_A = 0;
	bool A = false;
	long long int buff_B = 0;
	bool B = false;
	std::string opcode = "";
	std::string opcode_1 = "";
	std::string tmp_buffer = "";
	buffer += "<"; // Terminating char

	for(std::string::size_type i = 0; i < buffer.size(); ++i) {
    
    int ascii_code = (int) buffer[i]; // 48 -> 57 are the range for numbers everything else should be a operator.
    if (ascii_code >= 48 && ascii_code <= 57) {
    	////std::cout << "Number is punched." << buffer[i] << std::endl;
    	tmp_buffer += buffer[i];
    	//std::cout << "Number encountered.\n";
    }

    else {
    	////std::cout << "Operator is punched." << buffer[i] << std::endl;
    	//std::cout << "Operator encountered.\n";
    	
    	// if string buffer is empty start filling it wiht number and sign
    	// if it's filled then it's an operator
    	if (tmp_buffer == "") {
    		//std::cout << "Signed Number encountered.\n";
    		tmp_buffer += buffer[i]; //Signed number
    		continue;
    	}
    	else {
    		// Fill number buffer A or B
    		//std::cout << "Buffer is not empty and operator is encountered.\n";


    		if (!A) { // Meaning A is empty
    			// Clean Tmp buffer
    			// Fill buff_A
    			// Set A = true
    			// Pace forward from there
    			//std::cout << "Filling the Fisrt operand.\n";

    			buff_A = std::stoi (tmp_buffer,&sz);
    			//std::cout << "Number :" << tmp_buffer << " and OP is :  " << buffer[i] << std::endl;
    			tmp_buffer = "";

    			/////////////////////////////////
    			//result_main = buff_A;
    			A = true;
    			opcode = buffer[i];
    			if ( opcode == "<" ) {
    				switch ( (int)opcode_1[0] ){
    				case 43:
    					result_main =  result_main + buff_A;
    					break;
    				case 45:
    					result_main =  result_main - buff_A;
    					break;
    				case 42:
    					result_main =  result_main * buff_A;
    					break;
    				case 47:
    					result_main =  result_main / buff_A;
    					break;	
    			}
    			return(std::to_string(result_main));

    		}
    		}
    		else if (!B) { // Meaning B is empty
    			// Clean Tmp buffer
    			// Fill buff_A
    			// Set A = true
    			// Pace forward from there
    			//std::cout << "Filling the second operand..\n";
    			buff_B = std::stoi (tmp_buffer,&sz);
    			//std::cout << "Number :" << tmp_buffer << std::endl;
    			tmp_buffer = "";
    			long long int result;
    			//B = true;
    			////std::cout << (int)opcode[0] << " is the op code.\n";
    			switch ( (int)opcode[0] ){
    				case 43:
    					result =  buff_A + buff_B;
    					break;
    				case 45:
    					result =  buff_A - buff_B;
    					break;
    				case 42:
    					result =  buff_A * buff_B;
    					break;
    				case 47:
    					result =  buff_A / buff_B;
    					break;	
    			}

    			opcode = buffer[i];

    			//std::cout << "Result is: " << result << std::endl;
    			//opcode = ""; // Next opcode
    			tmp_buffer = "";
    			A = false;
    			B = false;

    			//std::cout << "OP code is: " << opcode << "\n";

    			if (opcode == "<") {

    			//std::cout << "Reached the end.\n";
    			
    			if (opcode_1 == "") {
    				//std::cout << "Nothing else to parse.\n";
    				return(std::to_string(result));
    			}

    			switch ((int)opcode_1[0]) {
    				case 43:
    					result_main += result;
    					break;
    				case 45:
    					result_main -= result;
    					break;
    				case 42:
    					result_main *= result;
    					break;
    				case 47:
    					result_main /= result;
    					break;
    			}
    				return(std::to_string(result_main));
    			}
    			else {
    				//std::cout << "Still a bin op left.\n";
    				//opcode_1 = buffer[i]
    				//std::cout << "Big opcode is: " << opcode_1  << "\n";

	    			switch ((int)opcode_1[0]) {
	    				case 43:
	    					result_main += result;
	    					break;
	    				case 45:
	    					result_main -= result;
	    					break;
	    				case 42:
	    					result_main *= result;
	    					break;
	    				case 47:
	    					result_main /= result;
	    					break;
	    				default:
	    					result_main = result;
	    			}

	    			//std::cout << "Result after last big op is: " << result_main << "\n";
    				opcode_1 = buffer[i];
    				opcode = "";
    				//result_main += result;
    				//return(std::to_string(result_main));
    			}
    		}


    	}
    }

}
	return(std::to_string(result_main));
}

std::string calc::back (void) {
	if (buffer == "") {return("Empty Buffer!");}
	buffer.pop_back();
	return(buffer);
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
  QObject::connect(pushButton_18, SIGNAL(clicked()), this, SLOT(handleButton()) );
  pushButton_17->setStyleSheet(QString::fromUtf8("background-color: #d45f55;color:black;border-radius:6px;font-weight:100;\n"));
  pushButton_12->setStyleSheet(QString::fromUtf8("background-color: #9a9a9a;color:white;border-radius:6px;font-weight:100;\n"));


}

calc instance;

void Ui_MainWindow::handleButton () {
  
  QPushButton * stuff =  (QPushButton *) QObject::sender();

  std::string key_string = stuff->text().toUtf8().constData();

  if (key_string == "=") {
  	// Suite for processing the buffer
  	label->setText( QString::fromUtf8( instance.parse().c_str() ) );
  	return;
    			// Set A = true
  }

  else if (key_string == "C") {
  	instance.clear();
  	label->setText("");
  	return;
  }

  else if (key_string == "<") {
  	std::string buff = instance.back();
  	QString str = QString::fromUtf8(buff.c_str());
  	label->setText(str);
  	return;
  }

  else {
  	std::string buff = instance.push(key_string);
  	QString str = QString::fromUtf8(buff.c_str());
  	label->setText(str);
  	return;
}
  return;
}
