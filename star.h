#ifndef STAR_H
#define STAR_H

#include <QImage>
#include <QRect>
#include "drop.h"

class Star: public Drop
{

  public:
    Star();
    ~Star();

  public:
    virtual void resetState(int);
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
