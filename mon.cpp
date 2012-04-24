#include "mon.h"
#include <iostream>

Mon::Mon()
{

  xdir = 0;
  ydir = 1; // Make downwards as the direction of the object in the y axis


  image.load("M.png"); //Make the picture of a 'S' icon as the object image

  rect = image.rect();

}

Mon::~Mon() {
  std::cout << ("Ball deleted\n");
}


void Mon::autoMove(int level,int x)
{
  rect.translate(xdir, level);

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Mon::resetState(int x) { // function for setting the initial position of the icon
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void Mon::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void Mon::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int Mon::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect Mon::getRect(){ //function for getting the Rect
  return rect;
}

QImage & Mon::getImage(){ // function for returning the image
  return image;
}

