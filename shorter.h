#ifndef SHORTER_H
#define SHORTER_H

#include <QImage>
#include <QRect>
#include "drop.h"

class Shorter: public Drop
{

  public:
    Shorter();
    ~Shorter();

  public:
    virtual void resetState(int);
    virtual void moveBottom(int);
    virtual void autoMove(int,int x);
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
