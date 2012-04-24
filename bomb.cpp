#include "bomb.h"
#include <iostream>


Bomb::Bomb()
{

  xdir = 0;
  ydir = 1; // Make downwards as the direction of the object in the y axis

  image.load("Bomb.png"); //Make the picture of a 'S' icon as the object image

  rect = image.rect();

}

Bomb::~Bomb() {
  std::cout << ("Ball deleted\n");
}


void Bomb::autoMove(int level,int x)
{

  rect.translate(xdir, level);

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Bomb::resetState(int x) { // function for setting the initial position of the icon
  srand(time(0));
  rect.moveTo(x, 0);
}

void Bomb::moveBottom(int bottom){ //function for moving the icon to the bottom
  rect.moveBottom(bottom);
}

void Bomb::setYDir(int y){ // function for setting the direction the icon is moving towards on the y axis
  ydir = y;
}

int Bomb::getYDir(){ // function for getting the direction the icon is moving towards on the y axis
  return ydir;
}

QRect Bomb::getRect(){ //function for getting the Rect
  return rect;
}

QImage & Bomb::getImage(){ // function for returning the image
  return image;
}

