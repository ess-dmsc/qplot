#include "GradientSelector.h"
#include <QBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QTableView>

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
    QCPRange r(0, 1.0);
    for (double i = 0; i < 1.0; i+=0.002)
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
    return;
  }

  QStyledItemDelegate::paint(painter, option, index);
  return;
}


GradientsModel::GradientsModel(Gradients& gradients, QObject *parent)
    : QAbstractTableModel(parent)
    , gradients_(gradients)
{}

int GradientsModel::rowCount(const QModelIndex& /*parent*/) const
{
  return gradients_.size();
}

int GradientsModel::columnCount(const QModelIndex& /*parent*/) const
{
  return 2;
}

QVariant GradientsModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
      return QVariant();

  if (index.row() >= gradients_.size() || index.row() < 0)
      return QVariant();

  if (index.column() > 1 || index.column() < 0)
      return QVariant();

  if (role == Qt::DisplayRole)
  {
    if (index.column() == 0)
      return gradients_.names()[index.row()];
    else if (index.column() == 1)
      return QVariant::fromValue(gradients_.get(index.row()));
  }
//  else if (role == Qt::BackgroundRole) {
//      int batch = (index.row() / 100) % 2;
//      if (batch == 0)
//          return qApp->palette().base();
//      else
//          return qApp->palette().alternateBase();
//  }
  return QVariant();
}

GradientSelector::GradientSelector(Gradients gradients, QWidget *parent)
  : QDialog(parent)
  , gradients_(gradients)
  , model_(gradients_, this)
{
  QTableView* tview = new QTableView();
  tview->setModel(&model_);
  tview->setItemDelegate(&delegate_);
  tview->verticalHeader()->hide();
  tview->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  tview->horizontalHeader()->hide();
  tview->horizontalHeader()->setStretchLastSection(true);
  tview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  tview->setSelectionBehavior(QAbstractItemView::SelectRows);
  tview->setSelectionMode(QAbstractItemView::SingleSelection);

  QVBoxLayout *total    = new QVBoxLayout();
  total->addWidget(tview);

  QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept_selection()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
  total->addWidget(buttonBox);

  setLayout(total);

  QRect myrect = this->geometry();
  myrect.setWidth(350);
  myrect.setHeight(gradients_.size() * 25);
  setGeometry(myrect);

  setFixedSize(size());
}

void GradientSelector::accept_selection()
{

}

}
