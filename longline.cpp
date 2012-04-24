#include "longline.h"
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsView>

LongLine::LongLine()
{
image.load("long_line.png");

  rect = image.rect();
  resetState();
}

LongLine::~LongLine()
{
 std::cout << ("Line deleted\n");
}

void LongLine::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void LongLine::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void LongLine::resetState()
{
  rect.moveTo(200, 390);
}

QRect LongLine::getRect()
{
  return rect;
}

QImage & LongLine::getImage()
{
  return image;
}
