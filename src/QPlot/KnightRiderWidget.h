#pragma once

#include <QObject>
#include <QWidget>
#include <QPlot/qcustomplot/qcustomplot.h>

namespace QPlot {

class KnightRiderWidget : public QWidget
{
  Q_OBJECT
public:
  KnightRiderWidget(QWidget *parent = 0);

//  QSize sizeHint() const Q_DECL_OVERRIDE;

  void setDarkBlockVisibility(double dbv);

  void setPrefix(const QString&);
  void setSuffix(const QString&);
  void setRange(double, double);
  void setValue(double);
  double value() const;

  QCPColorGradient gradient_ {QCPColorGradient::gpHot};
  bool override_background_ {false};
  QColor background_ {Qt::black};

 protected:
  QString prefix_;
  QString suffix_;
  QFont font_ {"SF Fedora Titles", 16, 2};
  QString compose_text() const;
  int text_height() const;
  void paint_text(QPainter *painter, const QRect &rect, int flags) const;

  QCPRange range_;
  double val_ {50};

  double dark_block_visibility_ {0.1};

  size_t block_height_ {10};
  size_t block_margin_ {2};
  int block_height_with_margin() const;
  QRect block() const;

  QColor color_at(double) const;
  QColor min_color() const;
  QColor max_color() const;
  QColor on_color(size_t block, size_t total_blocks) const;
  QColor off_color(size_t block, size_t total_blocks) const;
  QColor frac_color(size_t block, size_t total_blocks, double frac) const;
  QColor block_color(size_t block, size_t total_blocks, double block_val) const;

  void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
  void paint(QPainter *painter, const QRect &rect) const;
};

}
