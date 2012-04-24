#ifndef LONGLINE_H
#define LONGLINE_H

#include <QImage>
#include <QRect>
#include "line.h"

class LongLine:public Line
{

  public:
    LongLine();
    ~LongLine();

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
