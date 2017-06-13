#include "TestApp.h"
#include "ui_TestApp.h"
#include <QCloseEvent>
#include <QSettings>

//#include "CustomLogger.h"

TestApp::TestApp(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::TestApp)
{
//  CustomLogger::initLogger();
  ui->setupUi(this);


}

TestApp::~TestApp()
{
  delete ui;
}

void TestApp::closeEvent(QCloseEvent *event)
{
  saveSettings();
  event->accept();
}

void TestApp::loadSettings()
{
  QSettings settings;
  settings.beginGroup("Program");
  setGeometry(settings.value("position",QRect(20,20,1234,650)).toRect());
}

void TestApp::saveSettings()
{
  QSettings settings;
  settings.beginGroup("Program");
  settings.setValue("position", this->geometry());
}
