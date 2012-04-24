#include <QtGui>
#include <QDesktopWidget>
#include <QFont>
#include <QApplication>
#include <QLabel>
 #include <QPixmap>
#include <QImage>

#include <string>
#include "breakout.h"
#include "breakoutwindow.h"

BreakoutWindow::BreakoutWindow()
{

QWidget::setFont(QFont("Courier New", 20, QFont::Bold));

    board = new Breakout(this);

    scoreLcd = new QLCDNumber(4);
    scoreLcd->setSegmentStyle(QLCDNumber::Flat);
    scoreLcd->setPalette(QPalette(QColor(0, 0, 0, 255)));
    scoreLcd->setAutoFillBackground(true);
    
    levelLcd = new QLCDNumber(4);
    levelLcd->setSegmentStyle(QLCDNumber::Flat);
    levelLcd->setPalette(QPalette(QColor(0,0, 0, 255)));
    levelLcd->setAutoFillBackground(true);

    livesLcd = new QLCDNumber(4);
    livesLcd->setSegmentStyle(QLCDNumber::Flat);
    livesLcd->setPalette(QPalette(QColor(0, 0, 0, 255)));
    livesLcd->setAutoFillBackground(true);

    numLcd = new QLCDNumber(4);
    numLcd->setSegmentStyle(QLCDNumber::Flat);
    numLcd->setPalette(QPalette(QColor(255, 0, 0, 127)));
    numLcd->setAutoFillBackground(true);

    quitButton = new QPushButton(tr("Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);

    startButton = new QPushButton(tr("Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
 
    instruction = new QWidget();
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("instruction.png")));

    instruction->setPalette(palette);
    instruction->setAutoFillBackground(true);

    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(startButton, SIGNAL(clicked()), board, SLOT(startGame()));

    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
    connect(board, SIGNAL(livesChanged(int)), livesLcd, SLOT(display(int)));
    connect(board, SIGNAL(numberChanged(int)), numLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(instruction, 8,0,16,1);

    layout->addWidget(createLabel(tr("LEVEL")), 25, 0);
    layout->addWidget(levelLcd, 26, 0);

    layout->addWidget(board, 0, 3, 32, 3);
    layout->addWidget(createLabel(tr("SCORE")), 27, 0);
    layout->addWidget(scoreLcd, 28, 0);

    layout->addWidget(createLabel(tr("LIVES")), 29, 0);
    layout->addWidget(livesLcd, 30, 0);

    layout->addWidget(createLabel(tr("NUMBER")),0,0);
    layout->addWidget(numLcd,1,0,7,1);

    layout->addWidget(quitButton, 32, 0); 
    layout->addWidget(startButton, 31, 0);  
    setLayout(layout);

    setWindowTitle(tr("Catch the factors!"));
    resize(640, 500);
}


void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 400;
  int HEIGHT = 600;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

QLabel *BreakoutWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}
