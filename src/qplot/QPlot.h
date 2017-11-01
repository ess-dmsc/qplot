#pragma once

#include "qcustomplot.h"
#include "QPlotDraggable.h"
#include "QPlotButton.h"
#include <set>

namespace QPlot
{

enum ShowOption : uint32_t {
  empty     = 0,
  style     = 1,
  scale     = 2,
  labels    = 4,
  themes    = 8,
  thickness = 16,
  grid      = 32,
  title     = 64,
  zoom      = 128,
  save      = 256,
  gradients = 512,
  dither    = 1024,
  flip_y    = 2048
};

Q_DECLARE_FLAGS(ShowOptions, ShowOption)

Q_DECLARE_OPERATORS_FOR_FLAGS(ShowOptions)

class GenericPlot : public QCustomPlot
{
  Q_OBJECT
public:
  explicit GenericPlot(QWidget *parent = 0);
  QSize sizeHint() const Q_DECL_OVERRIDE;

  bool containsItem(QCPAbstractItem *item) const;

  void clearAll();
  virtual void clearPrimary() {}
  virtual void clearExtras() {}

  void replotAll();
  virtual void replotPrimary() {}
  virtual void replotExtras();

  void setVisibleOptions(ShowOptions);
  ShowOptions visibleOptions() const;

  bool flipY() const;
  bool alwaysSquare() const;
  bool antialiased() const;
  bool showGradientLegend() const;
  bool showMarkerLabels() const;
  bool showTitle() const;
  uint16_t lineThickness() const;
  QString gridStyle() const;
  QString scaleType() const;
  QString plotStyle() const;
  QString gradient() const;

  void setFlipY(bool);
  void setAlwaysSquare(bool);
  void setAntialiased(bool);
  void setShowGradientLegend(bool);
  void setShowMarkerLabels(bool);
  void setShowTitle(bool);
  void setLineThickness(uint16_t);
  void setGridStyle(QString);
  virtual void setScaleType(QString);
  void setPlotStyle(QString);
  void setGradient(QString);

  void addStandardGradients();
  void addCustomGradient(QString name,
                         std::initializer_list<std::string> colors);

public slots:
  virtual void zoomOut() {}

signals:
  void mouseHover(double x, double y);
  void shiftStateChanged(bool);
  void zoomedOut();
  void scaleChanged(QString);

protected:
  virtual void executeButton(Button *);
  virtual void mouseClicked(double x, double y, QMouseEvent* e);

  void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void resizeEvent(QResizeEvent * event) Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent*) Q_DECL_OVERRIDE;
  void keyReleaseEvent(QKeyEvent*) Q_DECL_OVERRIDE;

  void plotButtons();
  void setGraphThickness(QCPGraph* graph);
  void setGraphStyle(QCPGraph* graph, QString style = "");
  void setButtonPosition(QCPItemPosition*, Button* previous);
  void addStackButton(Button* button);

protected slots:
  void exportPlot(QAction*);
  void optionsChanged(QAction*);

private:
  mutable int previous_height_ {0};

  ShowOptions visible_options_;
  QMenu options_menu_;
  QMenu export_menu_;
  Button *lastStackButton {nullptr};

  bool always_square_ {false};
  bool antialiased_ {false};
  bool show_gradient_legend_ {false};
  bool show_marker_labels_ {true};
  bool show_title_ {true};
  bool flip_y_ {false};
  uint16_t line_thickness_ {1};
  QString current_scale_type_ {"Linear"};
  QString current_grid_style_ {"Grid"};
  QString current_plot_style_ {"Lines"};
  QString current_gradient_;

  QMap<QString, QCPColorGradient> gradients_;
  QMap<QString, QCPAxis::ScaleType> scale_types_
  { {"Linear", QCPAxis::stLinear}, {"Logarithmic", QCPAxis::stLogarithmic} };
  QSet<QString> grid_styles_ {"No grid", "Grid", "Grid + subgrid"};
  QSet<QString> plot_styles_ {"Step center", "Step left", "Step right",
                              "Lines", "Scatter", "Fill"};

  //helper functions
  QFont rescaleFont(QFont font, double size_offset);
  void rescaleEverything(int fontUpscale, int plotThicken,
                         int marginUpscale, bool buttons_visible);
  void rebuildOptionsMenu();
  void checkoffOptionsMenu();
  void removeGradientLegend();
  void addGradientLegend(QCPColorMap* colorMap);

  static QString CustomSaveFileDialog(QWidget *parent,
                                      const QString &title,
                                      const QString &directory,
                                      const QString &filter);
  static bool validateFile(QWidget* parent, QString, bool);
};


}

