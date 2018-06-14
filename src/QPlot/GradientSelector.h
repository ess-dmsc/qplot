#pragma once

#include <QDialog>
#include <QAbstractTableModel>
#include <QStyledItemDelegate>
#include <QPlot/Gradients.h>

Q_DECLARE_METATYPE(QCPColorGradient)

namespace QPlot
{

void paintGradient(QPainter* painter,
                   const QRect& rect,
                   QLinearGradient colors,
                   QString text = "");

void paintGradient(QPainter* painter,
                   const QRect& rect,
                   QCPColorGradient colors,
                   QString text = "");

class GradientDelegate : public QStyledItemDelegate
{
    Q_OBJECT
  public:
    GradientDelegate(QObject *parent = 0,
                     uint16_t hl_thickness = 1)
      : QStyledItemDelegate(parent)
      , hl_thickness_(hl_thickness)
    {}

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const Q_DECL_OVERRIDE;

  private:
    uint16_t hl_thickness_;
};

class GradientsModel : public QAbstractListModel
{
    Q_OBJECT

  public:
    GradientsModel(Gradients& gradients, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  private:
    Gradients& gradients_;
};

class GradientSelector : public QDialog
{
    Q_OBJECT

  public:
    explicit GradientSelector(Gradients gradients,
                              QString selected_gradient,
                              QWidget *parent = 0);

    QString selected_gradient() const;

  private slots:
    void itemDoubleClicked(QModelIndex);

  private:
    Gradients gradients_;
    QString selected_gradient_;

    GradientsModel model_;
    GradientDelegate delegate_;

    QItemSelectionModel* selection_;
};

}
