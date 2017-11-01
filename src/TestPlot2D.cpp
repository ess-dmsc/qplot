#include "TestPlot2D.h"
#include "ui_TestPlot2D.h"

TestPlot2D::TestPlot2D(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::TestPlot2D)
{
  ui->setupUi(this);

  //  ui->plot->setOpenGl(true);

  ui->plot->setSizePolicy(QSizePolicy::Preferred,
                       QSizePolicy::MinimumExpanding);
  ui->plot->setVisibleOptions(QPlot::zoom | QPlot::save| QPlot::grid |
                           QPlot::scale | QPlot::gradients);
  ui->plot->setGradient("Spectrum2");
  ui->plot->setScaleType("Linear");
  ui->plot->setShowGradientLegend(true);
  ui->plot->yAxis->setRangeReversed(true);
  connect(ui->plot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel(QWheelEvent*)));
  connect(ui->plot, SIGNAL(zoomedOut()), this, SLOT(zoomedOut()));
}

void TestPlot2D::init(uint32_t nx, uint32_t ny)
{
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

  ui->plot->clearExtras();
  ui->plot->clearData();
  ui->plot->setAxes("x", 0, res_x, "y", 0, res_y, "z");
  ui->plot->updatePlot(res_x + 1, res_y + 1, hist);
  ui->plot->replotExtras();

  if (!user_zoomed_)
    ui->plot->zoomOut();
}

void TestPlot2D::refresh()
{
  ui->plot->replot(QCustomPlot::rpQueuedRefresh);
}


void TestPlot2D::mouseWheel (QWheelEvent *event)
{
  user_zoomed_ = true;
}

void TestPlot2D::zoomedOut()
{
  user_zoomed_ = false;
}


