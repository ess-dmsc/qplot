#include "TestScalar.h"
#include "ui_TestScalar.h"
#include <QPlot/GradientSelector.h>

TestScalar::TestScalar(QWidget* parent)
    : QWidget(parent)
      , ui(new Ui::TestScalar)
      , oscillator_(this)
{
  ui->setupUi(this);

  ui->spinUpdateFrequency->setValue(50);

  g.addStandardGradients();
  g.set("RedOnly", {"#ff0000", "#ff0000"});
  g.set("GYR", {"#00ff00", "#ffff00", "#ff0000"});


  ui->knight1->gradient_ = g.get("GYR");
  ui->knight2->gradient_ = g.get("GYR");

  ui->knight2->orientation_ = Qt::Horizontal;

  connect(ui->doubleMin, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->doubleMax, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->doubleVal, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->doubleDark, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->doublePrecision, SIGNAL(valueChanged(double)), this, SLOT(update()));
  connect(ui->checkOverrideBackground, SIGNAL(stateChanged(int)), this, SLOT(update()));

  connect(&oscillator_, SIGNAL(val_update(double)), this, SLOT(val_update(double)));

  update();
}

void TestScalar::closeEvent(QCloseEvent* event)
{
  oscillator_.terminate_wait();
  event->accept();
}

void TestScalar::update()
{
  ui->knight1->val_precision_ = ui->doublePrecision->value();
  ui->knight2->val_precision_ = ui->doublePrecision->value();

  ui->knight1->override_background_ = ui->checkOverrideBackground->isChecked();
  ui->knight2->override_background_ = ui->checkOverrideBackground->isChecked();

  ui->knight1->setDarkBlockVisibility(ui->doubleDark->value() * 0.01);
  ui->knight2->setDarkBlockVisibility(ui->doubleDark->value() * 0.01);

  ui->knight1->setRange(ui->doubleMin->value(), ui->doubleMax->value());
  ui->knight2->setRange(ui->doubleMin->value(), ui->doubleMax->value());

  ui->knight1->setValue(ui->doubleVal->value());
  ui->knight2->setValue(ui->doubleVal->value());

  ui->knight1->repaint();
  ui->knight2->repaint();
}

void TestScalar::on_pushGradientSelector_clicked()
{
  auto gs = new QPlot::GradientSelector(g,
                                        "",
                                        qobject_cast<QWidget*>(parent()));
  gs->setModal(true);
  gs->exec();
  ui->knight1->gradient_ = g.get(gs->selected_gradient());
  ui->knight2->gradient_ = g.get(gs->selected_gradient());
  update();
}

void TestScalar::val_update(double val)
{
  ui->knight1->setValue(val);
  ui->knight2->setValue(val);

  ui->knight1->repaint();
  ui->knight2->repaint();
}

void TestScalar::on_pushStart_clicked()
{
  ui->doubleMin->setEnabled(false);
  ui->doubleMax->setEnabled(false);
  ui->doubleVal->setEnabled(false);
  ui->pushStart->setEnabled(false);
  ui->pushStop->setEnabled(true);
  oscillator_.set_wait_time(ui->spinUpdateFrequency->value());
  oscillator_.set_period(ui->doublePeriod->value());
  oscillator_.oscillate(ui->doubleMin->value(), ui->doubleMax->value());
}

void TestScalar::on_pushStop_clicked()
{
  oscillator_.terminate_wait();
  ui->doubleMin->setEnabled(true);
  ui->doubleMax->setEnabled(true);
  ui->doubleVal->setEnabled(true);
  ui->pushStart->setEnabled(true);
  ui->pushStop->setEnabled(false);
}

void TestScalar::on_spinUpdateFrequency_valueChanged(int)
{
  oscillator_.set_wait_time(ui->spinUpdateFrequency->value());
}

void TestScalar::on_doublePeriod_valueChanged(double)
{
  oscillator_.set_period(ui->doublePeriod->value());
}

