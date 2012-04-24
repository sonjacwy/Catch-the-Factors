#ifndef SHORTLINE_H
#define SHORTLINE_H

#include <QImage>
#include <QRect>
#include "line.h"


class ShortLine: public Line
{

  public:
    ShortLine();
    ~ShortLine();

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
