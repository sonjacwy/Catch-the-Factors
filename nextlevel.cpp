#include "nextlevel.h"
#include <iostream>

NextLevel::NextLevel()
{

  xdir = 0;
  ydir = 1; // Make downwards as the direction of the object in the y axis

  image.load("N.PNG"); //Make the picture of a 'N' icon as the object image

  rect = image.rect();

}

NextLevel::~NextLevel() {
  std::cout << ("Ball deleted\n");
}


void NextLevel::autoMove(int level,int x)
{
  rect.translate(xdir,level);

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void NextLevel::resetState(int x) { // function for setting the initial position of the icon
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void NextLevel::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void NextLevel::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int NextLevel::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect NextLevel::getRect(){ //function for getting the Rect
  return rect;
}

QImage & NextLevel::getImage(){ // function for returning the image
  return image;
}

