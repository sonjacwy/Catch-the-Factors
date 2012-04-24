#include "shortline.h"
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

ShortLine::ShortLine()
{
image.load("short_line.png");

  rect = image.rect();
  resetState();
}

ShortLine::~ShortLine()
{
 std::cout << ("Line deleted\n");
}

void ShortLine::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void ShortLine::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void ShortLine::resetState()
{
  rect.moveTo(200, 390);
}

QRect ShortLine::getRect()
{
  return rect;
}

QImage & ShortLine::getImage()
{
  return image;
}
