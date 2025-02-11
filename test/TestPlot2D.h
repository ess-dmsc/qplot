#pragma once

#include <QWidget>
#include <QPlot/QPlot2D.h>

namespace Ui {
class TestPlot2D;
}

class TestPlot2D : public QWidget
{
    Q_OBJECT

  public:
    TestPlot2D(QWidget *parent = 0);

    void init(uint32_t nx, uint32_t ny);
    void refresh();

  private slots:
    void mouseWheel (QWheelEvent *event);
    void zoomedOut();

    void updateShowOptions();

    void on_pushGradientSelector_clicked();

    void changedFlipY(bool);

    void clickedPlot(double x, double y);

private:
    Ui::TestPlot2D *ui;

    bool user_zoomed_ {false};

    void updateShowOptions(QPlot::ShowOptions opts);
};
