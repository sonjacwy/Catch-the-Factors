#ifndef LONGER_H
#define LONGER_H

#include <QImage>
#include <QRect>
#include <string>
#include "drop.h"

class Longer: public Drop
{

  public:
    Longer();
    ~Longer();

  public:
    virtual void resetState();
    virtual void moveBottom(int);
    virtual void autoMove(int,int);
    virtual void setYDir(int);
    virtual int getYDir();
    virtual QRect getRect();
    virtual QImage & getImage();

  private:
    int xdir;
    int ydir;
    bool stuck;
    QImage image;
    QRect rect;

};

#endif
