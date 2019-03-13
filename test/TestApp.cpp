#include "TestApp.h"
#include "ui_TestApp.h"
#include <QCloseEvent>
#include <QSettings>
#include <QPlot/QHist.h>

#include "TestPlot2D.h"
#include "TestScalar.h"

#include <QPlot/QPlot1D.h>

//#include "CustomLogger.h"

TestApp::TestApp(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::TestApp)
{
  //  CustomLogger::initLogger();
  ui->setupUi(this);

  auto scalar = new TestScalar(this);
  ui->tabs->addTab(scalar, "Scalar");

  ui->tabs->addTab(new QPlot::Multi1D(this), "Multi1D");

  auto plot2d = new TestPlot2D(this);
  plot2d->init(200,200);
  ui->tabs->addTab(plot2d, "Plot2D");

  plot2d->refresh();
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
