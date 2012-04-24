#ifndef NEXTLEVEL_H
#define NEXTLEVEL_H

#include <QImage>
#include <QRect>
#include "drop.h"

class NextLevel: public Drop
{

  public:
    NextLevel();
    ~NextLevel();

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
