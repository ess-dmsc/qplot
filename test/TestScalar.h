#pragma once

#include <QPlot/KnightRiderWidget.h>

namespace Ui
{
class TestScalar;
}

class TestScalar : public QWidget
{
 Q_OBJECT

 public:
  TestScalar(QWidget* parent = 0);

 private slots:
  void update();

  void on_pushGradientSelector_clicked();

 private:
  Ui::TestScalar* ui;
};
