#include "TestScalar.h"
#include "ui_TestScalar.h"
#include <QPlot/GradientSelector.h>

TestScalar::TestScalar(QWidget* parent)
    : QWidget(parent)
      , ui(new Ui::TestScalar)
{
  ui->setupUi(this);

  connect(ui->doubleMin, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->doubleMax, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->doubleVal, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->doubleDark, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->checkOverrideBackground, SIGNAL(stateChanged(int)), this, SLOT(update()));

  update();
}

void TestScalar::update()
{
  ui->knight1->override_background_ = ui->checkOverrideBackground->isChecked();
  ui->knight1->setDarkBlockVisibility(ui->doubleDark->value() * 0.01);
  ui->knight1->setRange(ui->doubleMin->value(), ui->doubleMax->value());
  ui->knight1->setValue(ui->doubleVal->value());
  ui->knight1->repaint();
}

void TestScalar::on_pushGradientSelector_clicked()
{
  QPlot::Gradients g;
  g.addStandardGradients();
  g.set("RedOnly", {"#ff0000", "#ff0000"});

  auto gs = new QPlot::GradientSelector(g,
                                        "",
                                        qobject_cast<QWidget*>(parent()));
  gs->setModal(true);
  gs->exec();
  ui->knight1->gradient_ = g.get(gs->selected_gradient());
  update();
}
