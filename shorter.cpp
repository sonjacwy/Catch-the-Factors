#include "shorter.h"
#include <iostream>

Shorter::Shorter()
{

  xdir = 0;
  ydir = 1; // Make downwards as the direction of the object in the y axis


  image.load("S.png"); //Make the picture of a 'S' icon as the object image

  rect = image.rect();


}

Shorter::~Shorter() {
  std::cout << ("Ball deleted\n");
}


void Shorter::autoMove(int level,int x)
{

  rect.translate(xdir, level);

srand(time(0));

  int num= rand()%3;
  if (num==0)
	xdir = -4;
  else if (num==1)
	xdir = 1;
  else if (num==2)
	xdir = 4;

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Shorter::resetState(int x) { // function for setting the initial position of the icon
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void Shorter::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void Shorter::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int Shorter::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect Shorter::getRect(){ //function for getting the Rect
  return rect;
}

QImage & Shorter::getImage(){ // function for returning the image
  return image;
}



