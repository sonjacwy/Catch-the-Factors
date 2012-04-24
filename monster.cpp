#include "monster.h"
#include <iostream>

Monster::Monster()
{

  xdir = 1;
  ydir = 0; // Make downwards as the direction of the object in the y axis


  image.load("monster.png"); //Make the picture of a 'S' icon as the object image

  rect = image.rect();
  resetState();

}

Monster::~Monster() {
  std::cout << ("Ball deleted\n");
}


void Monster::autoMove(int x)
{
  rect.translate(xdir,ydir);

  if (rect.x() < x) {
    xdir = 1;
  }

  else if (rect.x() ==x){
    xdir = -0.5;}


  else if (rect.x()-10 >x) {
    xdir = -1;
  }

}

void Monster::resetState() { // function for setting the initial position of the icon
  rect.moveTo(0, 300);
}

void Monster::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void Monster::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int Monster::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect Monster::getRect(){ //function for getting the Rect
  return rect;
}

QImage & Monster::getImage(){ // function for returning the image
  return image;
}

void Monster::setState(int x){
	rect.moveTo(x, 300);}


