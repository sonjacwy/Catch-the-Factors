#ifndef MON_H
#define MON_H

#include <QImage>
#include <QRect>
#include "drop.h"

class Mon: public Drop
{

  public:
    Mon();
    ~Mon();

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
