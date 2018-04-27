#include "GradientSelector.h"
#include <QBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QTableView>

#include <iostream>

namespace QPlot
{

void paintGradient(QPainter* painter,
                   const QRect& rect,
                   QLinearGradient colors,
                   QString text)
{
  painter->save();

  colors.setStart( 0.0, 0.0 );
  colors.setFinalStop( 1.0, 0.0 );
  colors.setSpread(QGradient::PadSpread);
  colors.setCoordinateMode(QGradient::ObjectBoundingMode);

  painter->setBrush(colors);
  painter->drawRect(rect);

  if (!text.isEmpty())
  {
    //    painter->setPen(QPen(inverseColor(color), 4));
    QFont f = painter->font();
    f.setBold(true);
    painter->setFont(f);
    painter->drawText(rect, Qt::AlignCenter | Qt::AlignVCenter, text);
  }

  painter->restore();
}

void paintGradient(QPainter* painter,
                   const QRect& rect,
                   QCPColorGradient colors,
                   QString text)
{
  QLinearGradient g;
  if (colors.colorInterpolation() == QCPColorGradient::ciRGB)
    for (auto s : colors.colorStops().toStdMap())
      g.setColorAt(s.first, s.second);
  else
  {
    double step = rect.width();
    if (step == 0.0)
      step = 100.0;
    step = 1.0 / step;
    QCPRange r(0, 1.0);
    for (double i = 0; i < 1.0; i+= step)
      g.setColorAt(i, colors.color(i,r,false));
  }
  paintGradient(painter, rect, g, text);
}


void GradientDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
  if (index.data().canConvert<QCPColorGradient>())
  {
    QCPColorGradient gradient = qvariant_cast<QCPColorGradient>(index.data());
    paintGradient(painter, option.rect, gradient);

    if (option.state & QStyle::State_Selected)
    {
      int offset = hl_thickness_ / 2 + 2;

      painter->setPen(QPen(Qt::black, hl_thickness_ + 2,
                           Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
      painter->drawRect(option.rect.adjusted(offset,offset,-offset,-offset));

      painter->setPen(QPen(Qt::white, hl_thickness_,
                           Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
      painter->drawRect(option.rect.adjusted(offset,offset,-offset,-offset));
    }

    return;
  }

  QStyledItemDelegate::paint(painter, option, index);
  return;
}


GradientsModel::GradientsModel(Gradients& gradients, QObject *parent)
  : QAbstractListModel(parent)
  , gradients_(gradients)
{}

int GradientsModel::rowCount(const QModelIndex& /*parent*/) const
{
  return gradients_.size();
}


QVariant GradientsModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (index.row() >= gradients_.size() || index.row() < 0)
    return QVariant();

  if (role == Qt::DisplayRole)
      return QVariant::fromValue(gradients_.get(index.row()));

  return QVariant();
}

GradientSelector::GradientSelector(Gradients gradients,
                                   QString selected_gradient,
                                   QWidget *parent)
  : QDialog(parent)
  , gradients_(gradients)
  , selected_gradient_(selected_gradient)
  , model_(gradients_, this)
{
  QListView* tview = new QListView();
  tview->setModel(&model_);
  tview->setItemDelegate(&delegate_);
  tview->setSelectionMode(QAbstractItemView::SingleSelection);

  connect(tview, SIGNAL(doubleClicked(QModelIndex)),
          this, SLOT(itemDoubleClicked(QModelIndex)));

  selection_ = tview->selectionModel();
  selection_->clearSelection();
  auto names = gradients_.names();
  for (int i=0; i < names.size(); ++i)
  {
    if (names[i] == selected_gradient_)
    {
      selection_->select(model_.index(i), QItemSelectionModel::Select);
      break;
    }
  }

  QVBoxLayout *total    = new QVBoxLayout();
  total->addWidget(tview);
  total->setContentsMargins(0,0,0,0);
  setLayout(total);

  QRect myrect = this->geometry();
  myrect.setWidth(150);
  myrect.setHeight(gradients_.size() * 18);
  setGeometry(myrect);

  setContentsMargins(0,0,0,0);

  //setFixedSize(size());
}

void GradientSelector::itemDoubleClicked(QModelIndex)
{
  QModelIndexList ixl = selection_->selectedRows();
  if (ixl.empty())
    return;
  selected_gradient_ = gradients_.names().at(ixl.front().row());
  accept();
}

QString GradientSelector::selected_gradient() const
{
  return selected_gradient_;
}


}
