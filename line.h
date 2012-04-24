#ifndef LINE_H
#define LINE_H

#include <QImage>
#include <QRect>

class Line
{

  public:
    Line();
    ~Line();

  public:
    virtual void resetState();
    virtual void moveLeft(int);
    virtual void moveRight(int);
    virtual QRect getRect();
    virtual QImage & getImage();
    int getX();
    int getY();
    void setState(int x);

  private:
    QImage image;
   QRect rect;

};

#endif
