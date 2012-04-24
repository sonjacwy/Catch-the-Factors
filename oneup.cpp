#include "oneup.h"
#include <iostream>

OneUp::OneUp()
{
 
  xdir = 0;
  ydir = 1;

  image.load("one-up.png");

  rect = image.rect();

}

OneUp::~OneUp() {
  std::cout << ("Ball deleted\n");
}


void OneUp::autoMove(int level,int x)
{

  rect.translate(xdir, level);

  if (rect.top() == 0) {
    ydir = 1;
  }

   srand(time(0));

  int num= rand()%3;
  if (num==0)
	xdir = -1;
  else if (num==1)
	xdir = 0;
  else if (num==2)
	xdir = 1;
}

void OneUp::resetState(int x) 
{
  srand(time(0));
  rect.moveTo(rand()%230, 0);
}

void OneUp::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void OneUp::setYDir(int y)
{
  ydir = y;
}

int OneUp::getYDir()
{
  return ydir;
}

QRect OneUp::getRect()
{
  return rect;
}

QImage & OneUp::getImage()
{
  return image;
}




