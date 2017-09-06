#pragma once

#include "QPlot.h"
#include "QHist.h"

namespace QPlot
{

struct Label2D
{
  int64_t id {-1};
  double x {0}, y {0};
  QString text;
  bool selected {false};
  bool selectable {false};
  bool vertical {false};
  bool vfloat {false}, hfloat {false};
};

struct MarkerBox2D
{
  bool operator== (const MarkerBox2D& other) const
  {
    if (x1 != other.x1) return false;
    if (x2 != other.x2) return false;
    if (y1 != other.y1) return false;
    if (y2 != other.y2) return false;
    if (xc != other.xc) return false;
    if (yc != other.yc) return false;
    return true;
  }

  bool operator!= (const MarkerBox2D& other) const
    { return !operator==(other); }

  bool visible {true};
  bool selected {false};
  bool selectable {false};
  bool mark_center {false};

  double x1, x2, y1, y2, xc, yc;
  int64_t id {-1};
  QString label;
  QColor border;
  QColor fill;
};


class Plot2D : public GenericPlot
{
  Q_OBJECT

public:
  explicit Plot2D(QWidget *parent = 0);

  void clearPrimary() override;
  void clearExtras() override;
  void replotExtras() override;

  void updatePlot(int sizex, int sizey,
                  const HistMap2D &spectrum_data);
  void updatePlot(int sizex, int sizey,
                  const HistList2D &spectrum_data);

  void setAxes(QString xlabel, double x1, double x2,
                QString ylabel, double y1, double y2,
                QString zlabel);

  bool inRange(double x1, double x2,
               double y1, double y2) const;
  void zoomOut(double x1, double x2,
               double y1, double y2);
  void setOrientation(Qt::Orientation);

  void setBoxes(const QList<MarkerBox2D>& boxes);
  void addBoxes(const QList<MarkerBox2D>& boxes);
  QList<MarkerBox2D> selectedBoxes() const;

  void setLabels(const QList<Label2D>& labels);
  void addLabels(const QList<Label2D>& labels);
  QList<Label2D> selectedLabels() const;

public slots:
  void zoomOut() Q_DECL_OVERRIDE;

signals:
  void clickedPlot(double x, double y, Qt::MouseButton button);

protected:
  void mouseClicked(double x, double y, QMouseEvent* event) override;

  QCPColorMap *colorMap {new QCPColorMap(xAxis, yAxis)};
  QList<MarkerBox2D> boxes_;
  QList<Label2D> labels_;

  void initializeGradients();
  void plotBoxes();
  void plotLabels();
};

}

