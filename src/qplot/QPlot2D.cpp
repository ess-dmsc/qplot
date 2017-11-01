#include "QPlot2D.h"

namespace QPlot
{

Plot2D::Plot2D(QWidget *parent)
  : GenericPlot(parent)
{
  initializeGradients();

  colorMap->setTightBoundary(false);
  axisRect()->setupFullAxesBox();
  setInteractions(static_cast<QCP::Interactions>(QCP::iRangeDrag | QCP::iRangeZoom));
  setNoAntialiasingOnDrag(true);

  setGradient("Greys");
  setGridStyle("Grid + subgrid");
  setScaleType("Linear");
  setAlwaysSquare(true);
  setAntialiased(false);

  setInteraction(QCP::iMultiSelect, true);

  setVisibleOptions(ShowOption::zoom | ShowOption::save | ShowOption::grid |
                    ShowOption::scale | ShowOption::gradients);
}

void Plot2D::initializeGradients()
{
  addStandardGradients();

  addCustomGradient("Blues", {"#ffffff","#deebf7","#9ecae1","#3182bd"});
  addCustomGradient("Greens", {"#ffffff","#e5f5e0","#a1d99b","#31a354"});
  addCustomGradient("Oranges", {"#ffffff",
                                "#fee6ce",
                                "#fdae6b",
                                "#e6550d"});
  addCustomGradient("Purples", {"#ffffff","#efedf5","#bcbddc","#756bb1"});
  addCustomGradient("Reds", {"#ffffff","#fee0d2","#fc9272","#de2d26"});
  addCustomGradient("Greys", {"#ffffff","#f0f0f0","#bdbdbd","#636363"});

  addCustomGradient("GnBu5", {"#ffffff","#f0f9e8","#bae4bc","#7bccc4","#43a2ca","#0868ac"});
  addCustomGradient("PuRd5", {"#ffffff","#f1eef6","#d7b5d8","#df65b0","#dd1c77","#980043"});
  addCustomGradient("RdPu5", {"#ffffff","#feebe2","#fbb4b9","#f768a1","#c51b8a","#7a0177"});
  addCustomGradient("YlGn5", {"#ffffff","#ffffcc","#c2e699","#78c679","#31a354","#006837"});
  addCustomGradient("YlGnBu5", {"#ffffff","#ffffcc","#a1dab4","#41b6c4","#2c7fb8","#253494"});

  addCustomGradient("Spectrum2", {"#ffffff","#0000ff","#00ffff","#00ff00","#ffff00","#ff0000","#000000"});
}

void Plot2D::setOrientation(Qt::Orientation o)
{
  yAxis->axisRect()->setRangeDrag(o);
  yAxis->axisRect()->setRangeZoom(o);
}

void Plot2D::setBoxes(const QList<MarkerBox2D>& boxes)
{
  boxes_ = boxes;
}

void Plot2D::addBoxes(const QList<MarkerBox2D> &boxes)
{
  boxes_.append(boxes);
}

void Plot2D::setLabels(const QList<Label2D>& labels)
{
  labels_ = labels;
}

void Plot2D::addLabels(const QList<Label2D>& labels)
{
  labels_.append(labels);
}

QList<MarkerBox2D> Plot2D::selectedBoxes() const
{
  QList<MarkerBox2D> selection;
  for (auto &q : selectedItems())
    if (QCPItemRect *b = qobject_cast<QCPItemRect*>(q))
    {
      MarkerBox2D box;
      box.id = b->property("id").toDouble();
      selection.push_back(box);
    }
  return selection;
}

QList<Label2D> Plot2D::selectedLabels() const
{
  QList<Label2D> selection;
  for (auto &q : selectedItems())
    if (QCPItemText *b = qobject_cast<QCPItemText*>(q))
    {
      Label2D label;
      label.id = b->property("id").toDouble();
      selection.push_back(label);
    }
  return selection;
}

void Plot2D::clearPrimary()
{
  colorMap->data()->clear();
}

void Plot2D::clearExtras()
{
  boxes_.clear();
  labels_.clear();
}

void Plot2D::replotExtras()
{
  clearItems();
  plotBoxes();
  plotLabels();
  plotButtons();
  replot();
}

void Plot2D::plotBoxes()
{
  int selectables = 0;
  for (auto &q : boxes_)
  {
    if (!q.visible)
      continue;
    QCPItemRect *box = new QCPItemRect(this);
    box->setSelectable(q.selectable);
    QPen borderpen(q.border);
    borderpen.setWidth(1);
    box->setPen(borderpen);
//    box->setSelectedPen(pen);
    box->setBrush(QBrush(q.fill));
    box->setSelected(q.selected);
    QColor sel = box->selectedPen().color();
    sel = QColor::fromHsv(sel.hsvHue(), sel.saturation(), sel.value(), sel.alpha() * 0.15);
    box->setSelectedBrush(QBrush(sel));

    box->setProperty("id", QVariant::fromValue(q.id));
    box->topLeft->setCoords(q.x1, q.y1);
    box->bottomRight->setCoords(q.x2, q.y2);

    if (q.selectable)
      selectables++;

    if (q.mark_center)
    {
      QCPItemLine *linev = new QCPItemLine(this);
      QCPItemLine *lineh = new QCPItemLine(this);
      lineh->setPen(q.border);
      linev->setPen(q.border);
      //      linev->setSelectedPen(QPen(QColor::fromHsv(sel.hsvHue(), sel.saturation(), sel.value(), 48)));
      //      lineh->setSelectedPen(QPen(QColor::fromHsv(sel.hsvHue(), sel.saturation(), sel.value(), 48)));
      linev->setSelected(q.selected);
      lineh->setSelected(q.selected);
      lineh->setTail(QCPLineEnding::esBar);
      lineh->setHead(QCPLineEnding::esBar);
      linev->setTail(QCPLineEnding::esBar);
      linev->setHead(QCPLineEnding::esBar);
      lineh->start->setCoords(q.x1, q.yc);
      lineh->end->setCoords(q.x2, q.yc);
      linev->start->setCoords(q.xc, q.y1);
      linev->end->setCoords(q.xc, q.y2);
      //      DBG << "mark center xc yc " << xc << " " << yc;
    }
  }

  if (selectables)
  {
    setInteraction(QCP::iSelectItems, true);
    setInteraction(QCP::iMultiSelect, false);
  }
  else
  {
    setInteraction(QCP::iSelectItems, false);
    setInteraction(QCP::iMultiSelect, false);
  }
}

void Plot2D::plotLabels()
{
  if (!showMarkerLabels())
    return;
  for (auto &q : labels_)
  {
    if (q.text.isEmpty())
      continue;

    QCPItemText *labelItem = new QCPItemText(this);
    //    labelItem->setClipToAxisRect(false);
    labelItem->setText(q.text);
    labelItem->setProperty("id", QVariant::fromValue(q.id));

    labelItem->position->setType(QCPItemPosition::ptPlotCoords);

    double x = q.x, y = q.y;

    if (q.hfloat)
    {
      labelItem->position->setTypeX(QCPItemPosition::ptAxisRectRatio);
      x = 0.90;
    }

    if (q.vfloat)
    {
      labelItem->position->setTypeY(QCPItemPosition::ptAxisRectRatio);
      y = 0.10;
    }

    labelItem->position->setCoords(x, y);

    if (q.vertical)
    {
      labelItem->setRotation(90);
      labelItem->setPositionAlignment(Qt::AlignmentFlag(Qt::AlignTop|Qt::AlignRight));
    } else
      labelItem->setPositionAlignment(Qt::AlignmentFlag(Qt::AlignTop|Qt::AlignLeft));

    labelItem->setFont(QFont("Helvetica", 10));
    labelItem->setSelectable(q.selectable);
    labelItem->setSelected(q.selected);

    labelItem->setColor(Qt::black);
    labelItem->setPen(QPen(Qt::black));
    labelItem->setBrush(QBrush(Qt::white));

    QColor sel = labelItem->selectedColor();
    QPen selpen(QColor::fromHsv(sel.hsvHue(), sel.saturation(), sel.value(), 255));
    selpen.setWidth(3);
    labelItem->setSelectedPen(selpen);
    labelItem->setSelectedBrush(QBrush(Qt::white));

    labelItem->setPadding(QMargins(1, 1, 1, 1));
  }
}


void Plot2D::updatePlot(int sizex, int sizey,
                        const HistMap2D &spectrum_data)
{
  bool have_data = ((sizex > 0) && (sizey > 0) && (spectrum_data.size()));
  if (!have_data)
    return;

  bool square = (sizex == sizey);
  setAlwaysSquare(square);
  if (square)
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
  else
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

  bool changed_dims = ((colorMap->data()->keySize() != sizex) ||
                       (colorMap->data()->valueSize() != sizey));
  if (changed_dims)
    colorMap->data()->setSize(sizex, sizey);

  for (auto it : spectrum_data)
    colorMap->data()->setCell(it.first.x, it.first.y, it.second);

  setScaleType(scaleType());
  setGradient(gradient());
  if (changed_dims)
    rescaleAxes();
  updateGeometry();
  replotExtras();
}

void Plot2D::clearData() const
{
  colorMap->data()->fill(0);
}

void Plot2D::updatePlot(int sizex, int sizey,
                        const HistList2D &spectrum_data)
{
  bool have_data = ((sizex > 0) && (sizey > 0) && (spectrum_data.size()));
  if (!have_data)
    return;

  bool square = (sizex == sizey);
  setAlwaysSquare(square);
  if (square)
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
  else
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

  bool changed_dims = ((colorMap->data()->keySize() != sizex) ||
                       (colorMap->data()->valueSize() != sizey));
  if (changed_dims)
    colorMap->data()->setSize(sizex, sizey);

  for (auto it : spectrum_data)
    colorMap->data()->setCell(it.x, it.y, it.v);

  setScaleType(scaleType());
  setGradient(gradient());
  if (changed_dims)
    rescaleAxes();
  updateGeometry();
  replotExtras();
}

void Plot2D::setAxes(QString xlabel, double x1, double x2,
                     QString ylabel, double y1, double y2,
                     QString zlabel)
{
  for (int i=0; i < plotLayout()->elementCount(); i++)
    if (QCPColorScale *le = qobject_cast<QCPColorScale*>(plotLayout()->elementAt(i)))
      le->axis()->setLabel(zlabel);

  colorMap->keyAxis()->setLabel(xlabel);
  colorMap->valueAxis()->setLabel(ylabel);
  colorMap->data()->setRange(QCPRange(x1, x2),
                             QCPRange(y1, y2));

  colorMap->keyAxis()->setNumberFormat("f");
  colorMap->keyAxis()->setNumberPrecision(0);
  colorMap->valueAxis()->setNumberFormat("f");
  colorMap->valueAxis()->setNumberPrecision(0);
  colorMap->setProperty("z_label", zlabel);

//  rescaleAxes();
}

bool Plot2D::inRange(double x1, double x2,
                     double y1, double y2) const
{
  return(
      (x1 > xAxis->range().lower) &&
      (x2 < xAxis->range().upper) &&
      (y1 > yAxis->range().lower) &&
      (y2 < yAxis->range().upper));
}

void Plot2D::zoomOut(double x1, double x2,
                     double y1, double y2)
{
  if (x1 < colorMap->data()->keyRange().lower)
    x1 = colorMap->data()->keyRange().lower;
  if (x2 > colorMap->data()->keyRange().upper)
    x2 = colorMap->data()->keyRange().upper;
  if (y1 < colorMap->data()->valueRange().lower)
    y1 = colorMap->data()->valueRange().lower;
  if (y2 > colorMap->data()->valueRange().upper)
    y2 = colorMap->data()->valueRange().upper;

  xAxis->setRange(x1, x2);
  yAxis->setRange(y1, y2);
}


void Plot2D::mouseClicked(double x, double y, QMouseEvent *event)
{
  emit clickedPlot(x, y, event->button());
}


void Plot2D::zoomOut()
{
  rescaleAxes();
//  replot();

  double margin = 0.5;
  double x_lower = xAxis->range().lower;
  double x_upper = xAxis->range().upper;
  double y_lower = yAxis->range().lower;
  double y_upper = yAxis->range().upper;
  xAxis->setRange(x_lower - margin, x_upper + margin);
  yAxis->setRange(y_lower - margin, y_upper + margin);

//  replot();
}



}
