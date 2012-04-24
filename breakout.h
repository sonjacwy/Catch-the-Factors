#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "line.h"
#include "shortline.h"
#include "longline.h"
#include "fullline.h"

#include "drop.h"
#include "oneup.h"
#include "longer.h"
#include "shorter.h"
#include "star.h"
#include "devil.h"
#include "bomb.h"
#include "nextlevel.h"
#include "double.h"

#include "monster.h"
#include "mon.h"

#include "number.h"

#include <QWidget>
#include <QKeyEvent>
#include <string>
#include <QString>

class Breakout : public QWidget
{
  Q_OBJECT

  public:
    Breakout(QWidget *parent = 0);
    ~Breakout();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void victory();
    bool checkdropCollision();
    bool checknumCollision();
    void setDrop();
    void ChangeLevel();
    bool CheckPrime(int);
    void ResetLine();


public slots:
    void startGame();
    void pauseGame();
    void stopGame();

signals:
     void scoreChanged(int score);
     void levelChanged(int level);
     void livesChanged(int lives);
     void numberChanged(int number);

  private:
    int x;
    int number;
    int timerId;

    Line *line;
    Line *doubleline;
    ShortLine *shortline;
    LongLine *longline;
    FullLine *fullline;

    OneUp *oneup;
    Longer *longer;
    Shorter *shorter;
    Drop *drop;
    Bomb *bomb;
    Star *star;
    Devil *devil;
    Monster *monster;
    Double *doub;
    Mon *mon;

    NextLevel *nextlevel;
    Number *dropnumber;
    int num;
    int score;
    int level;
    int lives;
    int i;

    bool gameOver;
    bool gameWon;
    bool gameStarted;

    bool paused;
    bool caughtshort;
    bool numdropped;
    bool caughtdevil;
    bool line_double;
    bool caughtmonster;


};

#endif
