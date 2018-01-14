#include "TestPlot2D.h"
#include "GradientSelector.h"
#include "ui_TestPlot2D.h"

TestPlot2D::TestPlot2D(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::TestPlot2D)
{
  ui->setupUi(this);

  //  ui->plot->setOpenGl(true);

  ui->plot->setSizePolicy(QSizePolicy::Preferred,
                       QSizePolicy::MinimumExpanding);
  updateShowOptions(ui->plot->visibleOptions());
  ui->plot->setGradient("Spectrum2");
  ui->plot->setScaleType("Linear");
  ui->plot->setShowGradientLegend(true);
  connect(ui->plot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel(QWheelEvent*)));
  connect(ui->plot, SIGNAL(zoomedOut()), this, SLOT(zoomedOut()));

  connect(ui->checkStyle, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkScale, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkLabels, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkThemes, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkThickness, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkGrid, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkTitle, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkZoom, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkSave, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkGradients, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkDither, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
  connect(ui->checkFlipY, SIGNAL(clicked()), this, SLOT(updateShowOptions()));
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

void TestPlot2D::updateShowOptions()
{
  QPlot::ShowOptions opts;
  if (ui->checkStyle->isChecked())
    opts |= QPlot::style;
  if (ui->checkScale->isChecked())
    opts |= QPlot::scale;
  if (ui->checkLabels->isChecked())
    opts |= QPlot::labels;
  if (ui->checkThemes->isChecked())
    opts |= QPlot::themes;
  if (ui->checkThickness->isChecked())
    opts |= QPlot::thickness;
  if (ui->checkGrid->isChecked())
    opts |= QPlot::grid;
  if (ui->checkTitle->isChecked())
    opts |= QPlot::title;
  if (ui->checkZoom->isChecked())
    opts |= QPlot::zoom;
  if (ui->checkSave->isChecked())
    opts |= QPlot::save;
  if (ui->checkGradients->isChecked())
    opts |= QPlot::gradients;
  if (ui->checkDither->isChecked())
    opts |= QPlot::dither;
  if (ui->checkFlipY->isChecked())
    opts |= QPlot::flip_y;

  ui->plot->setVisibleOptions(opts);
}

void TestPlot2D::updateShowOptions(QPlot::ShowOptions opts)
{
  ui->checkStyle->setChecked(opts.testFlag(QPlot::style));
  ui->checkScale->setChecked(opts.testFlag(QPlot::scale));
  ui->checkLabels->setChecked(opts.testFlag(QPlot::labels));
  ui->checkThemes->setChecked(opts.testFlag(QPlot::themes));
  ui->checkThickness->setChecked(opts.testFlag(QPlot::thickness));
  ui->checkGrid->setChecked(opts.testFlag(QPlot::grid));
  ui->checkTitle->setChecked(opts.testFlag(QPlot::title));
  ui->checkZoom->setChecked(opts.testFlag(QPlot::zoom));
  ui->checkSave->setChecked(opts.testFlag(QPlot::save));
  ui->checkGradients->setChecked(opts.testFlag(QPlot::gradients));
  ui->checkDither->setChecked(opts.testFlag(QPlot::dither));
  ui->checkFlipY->setChecked(opts.testFlag(QPlot::flip_y));
}


void TestPlot2D::on_pushGradientSelector_clicked()
{
  auto gs = new QPlot::GradientSelector(QPlot::Gradients::defaultGradients(),
                                        qobject_cast<QWidget*> (parent()));
  gs->setModal(true);
  gs->exec();
}
