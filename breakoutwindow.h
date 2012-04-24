#ifndef BREAKOUTWINDOW_H
#define BREAKOUTWINDOW_H
#include <QtGui>
#include <QFrame>
#include <QWidget>
#include <QApplication>
#include <string>
#include <QString>
#include "breakout.h"

 class QLCDNumber;
 class QLabel;
 class QPushButton;

 class Breakout;

 class BreakoutWindow : public QWidget
 {
     Q_OBJECT

 public:
     BreakoutWindow();

 private:
     QLabel *createLabel(const QString &text);
     Breakout *board;
     QWidget *instruction;
     QLCDNumber *scoreLcd;
     QLCDNumber *levelLcd;
     QLCDNumber *livesLcd;
     QLCDNumber *numLcd;
     QPushButton *quitButton;
     QPushButton *startButton;
 
 };

 #endif
