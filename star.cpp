#include "star.h"
#include <iostream>

Star::Star()
{

  xdir = 0;
  ydir = 1; // Make downwards as the direction of the object in the y axis


  image.load("star.png"); //Make the picture of a star icon as the object image

  rect = image.rect();


}

Star::~Star() {
  std::cout << ("Ball deleted\n");
}


void Star::autoMove(int level,int x)
{

  rect.translate(xdir, level);

srand(time(0));

  int num= rand()%3;
  if (num==0)
	xdir = -1;
  else if (num==1)
	xdir = 0;
  else if (num==2)
	xdir = 1;

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Star::resetState(int x) { // function for setting the initial position of the icon
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void Star::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void Star::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int Star::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect Star::getRect(){ //function for getting the Rect
  return rect;
}

QImage & Star::getImage(){ // function for returning the image
  return image;
}



