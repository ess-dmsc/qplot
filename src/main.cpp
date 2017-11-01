#include "TestApp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QCoreApplication::setOrganizationName("ESS");
  QCoreApplication::setApplicationName("qplot");

  TestApp w;
  w.show();

  return a.exec();
}
