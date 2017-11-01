#include "TestApp.h"
#include "ui_TestApp.h"
#include <QCloseEvent>
#include <QSettings>
#include <QHist.h>

//#include "CustomLogger.h"

TestApp::TestApp(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::TestApp)
{
  //  CustomLogger::initLogger();
  ui->setupUi(this);

  init2d(200, 200);

  ui->plot2d->replot(QCustomPlot::rpQueuedRefresh);
}

void TestApp::init2d(uint32_t nx, uint32_t ny)
{
  ui->plot2d->setSizePolicy(QSizePolicy::Preferred,
                            QSizePolicy::MinimumExpanding);
  ui->plot2d->setVisibleOptions(QPlot::ShowOptions::zoom | QPlot::ShowOptions::save| QPlot::ShowOptions::grid |
                                QPlot::ShowOptions::scale | QPlot::ShowOptions::gradients);
  ui->plot2d->setGradient("Spectrum2");
  ui->plot2d->setScaleType("Linear");
  ui->plot2d->setShowGradientLegend(true);
  ui->plot2d->yAxis->setRangeReversed(true);

  QPlot::HistList2D hist;

  for (uint32_t x=0; x<nx; ++x)
  {
    double xx = double(x) / double(nx);
    for (uint32_t y=0; y<ny; ++y)
    {
      double yy = double(y) / double(ny);
      double r = 3*qSqrt(xx*xx+yy*yy)+1e-2;
      // the B field strength of dipole radiation (modulo physical constants)
      double z = 2*x*(qCos(r+2)/r-qSin(r+2)/r);
      hist.push_back(QPlot::p2d(x, y, z));
    }
  }

  uint32_t res_x = nx - 1;
  uint32_t res_y = ny - 1;

  ui->plot2d->clearExtras();
  ui->plot2d->clearData();
  ui->plot2d->setAxes(
        "x", 0, res_x,
        "y", 0, res_y,
        "count");
  ui->plot2d->updatePlot(res_x + 1, res_y + 1, hist);
  ui->plot2d->replotExtras();
  ui->plot2d->zoomOut();
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
