#pragma once

#include <QDialog>
#include <QAbstractTableModel>
#include <QStyledItemDelegate>
#include "Gradients.h"

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
  GradientDelegate(QObject *parent = 0)
    : QStyledItemDelegate(parent) {}

  void paint(QPainter *painter,
             const QStyleOptionViewItem &option,
             const QModelIndex &index) const Q_DECL_OVERRIDE;

//  QSize sizeHint(const QStyleOptionViewItem &option,
//                 const QModelIndex &index) const Q_DECL_OVERRIDE;

//  void updateEditorGeometry(QWidget *editor,
//                            const QStyleOptionViewItem &option,
//                            const QModelIndex &index) const Q_DECL_OVERRIDE;


};

class GradientsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    GradientsModel(Gradients& gradients, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  private:
    Gradients& gradients_;
};

class GradientSelector : public QDialog
{
    Q_OBJECT

  public:
    explicit GradientSelector(Gradients gradients, QWidget *parent = 0);

  private slots:
    void accept_selection();

  private:
    Gradients gradients_;
    GradientsModel model_;
    GradientDelegate delegate_;
};

}
