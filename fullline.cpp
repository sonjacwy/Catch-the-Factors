#include "fullline.h"
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

FullLine::FullLine()
{
image.load("full_line.png");

  rect = image.rect();
  resetState();
}

FullLine::~FullLine()
{
 std::cout << ("Line deleted\n");
}

void FullLine::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void FullLine::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void FullLine::resetState()
{
  rect.moveTo(0, 390);
}

QRect FullLine::getRect()
{
  return rect;
}

QImage & FullLine::getImage()
{
  return image;
}
