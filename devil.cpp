#include "devil.h"
#include <iostream>

Devil::Devil()
{

  xdir = 0;
  ydir = 1; // Make downwards as the direction of the object in the y axis


  image.load("devil.png"); //Make the picture of a 'S' icon as the object image

  rect = image.rect();

}

Devil::~Devil() {
  std::cout << ("Ball deleted\n");
}


void Devil::autoMove(int level, int x)
{
if ((rect.y()) < 200){ // follow the position of the line for x coordinate < 200
  if ((rect.x()+20)< x)
	xdir = 1;

  else if ((rect.x()-20) >x)
	xdir = -1;}

else
	xdir =0;

  rect.translate(xdir, level);

  

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Devil::resetState(int x) { // function for setting the initial position of the icon
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void Devil::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void Devil::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int Devil::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect Devil::getRect(){ //function for getting the Rect
  return rect;
}

QImage & Devil::getImage(){ // function for returning the image
  return image;
}

