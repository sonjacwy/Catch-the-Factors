#ifndef ONEUP_H
#define ONEUP_H

#include <QImage>
#include <QRect>
#include <string>
#include "drop.h"

class OneUp: public Drop
{

  public:
    OneUp();
    ~OneUp();

  public:
    virtual void resetState(int);
    virtual void moveBottom(int);
    virtual void autoMove(int,int);
    virtual void setYDir(int);
    virtual int getYDir();
    virtual QRect getRect();
    virtual QImage & getImage();

  private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool stuck;
    QImage image;
    QRect rect;

};

#endif
