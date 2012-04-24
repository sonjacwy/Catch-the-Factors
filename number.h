#ifndef NUMBER_H
#define NUMBER_H

#include <QImage>
#include <QRect>
#include <QString>
#include <string>
#include <iostream>
#include <QFontMetrics>
#include <ctime>

using namespace std;


class Number{
private:
    int x;
    int y;
    int num;
    bool stuck;
    QRect rect;
    QString str;

  public:
    Number();
    ~Number();

  public:
    void resetState();
    void moveBottom(int);
    void autoMove(int);
    void setYDir(int);
    int getX();
    int getY();
    int getNum();
    int getHeight();
    int getWidth();
    void setdropNum();
    QRect getRect();
    QString getNumber();

};

#endif


