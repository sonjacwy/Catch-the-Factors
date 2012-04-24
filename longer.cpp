#include "longer.h"
#include <iostream>
#include <string>

Longer::Longer()
{

  ydir = 1;
  xdir = 0;


  image.load("L.png");

  rect = image.rect();
  resetState();

}

Longer::~Longer() {
  std::cout << ("Ball deleted\n");
}


void Longer::autoMove(int level, int x)
{

  rect.translate(xdir, level);

 srand(time(0));

  int num= rand()%3;
  if (num==0)
	xdir = -2;
  else if (num==1)
	xdir = 0;
  else if (num==2)
	xdir = 2;

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Longer::resetState() 
{
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void Longer::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Longer::setYDir(int y)
{
  ydir = y;
}

int Longer::getYDir()
{
  return ydir;
}

QRect Longer::getRect()
{
  return rect;
}

QImage & Longer::getImage()
{
  return image;
}




