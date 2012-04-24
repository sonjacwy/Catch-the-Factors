#ifndef FULLLINE_H
#define FULLLINE_H

#include <QImage>
#include <QRect>
#include "line.h"


class FullLine: public Line
{

  public:
    FullLine();
    ~FullLine();

  public:
    virtual void resetState();
    virtual void moveLeft(int);
    virtual void moveRight(int);
    virtual QRect getRect();
    virtual QImage & getImage();

  private:
   QImage image;
   QRect rect;

};

#endif
