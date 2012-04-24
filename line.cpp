#include "line.h"
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsView>

Line::Line(){
image.load("line.png"); // making the graphic as the icon of the Line object

  rect = image.rect();
  resetState();
}

Line::~Line(){ // destructor
 std::cout << ("Line deleted\n");
}

void Line::moveLeft(int left){ // function for moving the line to the left when the arrow key is pressed
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Line::moveRight(int right){ // function for moving the line to the right when the arrow key is pressed
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void Line::resetState(){ // function for resetting the window
  rect.moveTo(200, 390);
}

void Line::setState(int x){
	rect.moveTo(x,390);
}


QRect Line::getRect(){
  return rect;
}

QImage & Line::getImage(){
  return image;
}

int Line::getX(){
	return rect.x();}

int Line::getY(){
	return rect.y();
}

