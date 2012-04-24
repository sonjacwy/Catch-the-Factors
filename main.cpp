#include "breakoutwindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <string>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  BreakoutWindow window;


  //window.setWindowTitle("Catch the factors!");
  window.show();

  return app.exec();

}
