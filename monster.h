#ifndef MONSTER_H
#define MONSTER_H

#include <QImage>
#include <QRect>
#include "drop.h"

class Monster
{

  public:
    Monster();
    ~Monster();

  public:
    void resetState();
    void moveBottom(int);
    void autoMove(int);
    void setYDir(int);
    int getYDir();
    QRect getRect();
    QImage & getImage();
    void setState(int x);

  private:
    int xdir;
    int ydir;
    bool stuck;
    QImage image;
    QRect rect;

};

#endif
