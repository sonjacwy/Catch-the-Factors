#include "number.h"
#include <iostream>
#include <string>
#include <QString>
#include <ctime>
#include <QFontMetrics>

using namespace std;


Number::Number(){
  srand(time(0));
  x = (rand()%230);
  y = 0; // Make downwards as the direction of the object in the y axis


  srand(time(0));
  num= (rand()%25+2);

  str.setNum(num);

  QFont font("times", 24);
  QFontMetrics fm(font);

  rect = fm.boundingRect(str);



  resetState();

}

Number::~Number() {

}


void Number::autoMove(int level)
{

  rect.translate(0, level);
}

void Number::resetState() { // function for setting the initial position of the icon
  srand(time(0));

  rect.moveTo(rand()%230, 0);

}

void Number::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}


int Number::getY(){ // function for getting the direction the icon is moving towards on the y axis
  return y;
}

int Number::getX(){
  return x;
}

QString Number::getNumber(){
	return str;
}

int Number::getNum(){
	return num;
}

QRect Number::getRect(){ //function for getting the Rect
  return rect;
}

int Number::getWidth(){
	return rect.width();
}

int Number::getHeight(){
	return rect.height();
}

void Number::setdropNum(){ // Randomly generate a number to be dropped
	srand(time(0));
	num= (rand()%25+2);
  	str.setNum(num);

  	QFont font("times", 24);
  	QFontMetrics fm(font);

  	rect = fm.boundingRect(str);

}



