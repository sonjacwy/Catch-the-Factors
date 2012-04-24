#include "double.h"
#include <iostream>

Double::Double()
{

  xdir = 0;
  ydir = 1; // Make downwards as the direction of the object in the y axis


  image.load("D.png"); //Make the picture of a 'S' icon as the object image

  rect = image.rect();

}

Double::~Double() {
  std::cout << ("Ball deleted\n");
}


void Double::autoMove(int level,int x)
{
  rect.translate(xdir, level);

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Double::resetState(int x) { // function for setting the initial position of the icon
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void Double::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void Double::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int Double::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect Double::getRect(){ //function for getting the Rect
  return rect;
}

QImage & Double::getImage(){ // function for returning the image
  return image;
}

