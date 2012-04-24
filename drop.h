#ifndef DROP_H
#define DROP_H

#include <QImage>
#include <QRect>

class Drop
{
  public:
    Drop() {xdir = 0; ydir = 1;}
    ~Drop() {}

  public:
    virtual void resetState(int){}
    virtual void moveBottom(int){}
    virtual void autoMove(int,int){}
    virtual int getYDir() {return ydir;}
    virtual QRect getRect() {return rect;}
    virtual QImage & getImage() {return image;}
    virtual void setState(int) {}

  private:
    int xdir;
    int ydir;
    bool stuck;
    QImage image;
    QRect rect;

};

#endif
