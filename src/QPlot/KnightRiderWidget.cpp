#include <QtWidgets>

#include <QPlot/KnightRiderWidget.h>

namespace QPlot
{

KnightRiderWidget::KnightRiderWidget(QWidget* parent)
    : QWidget(parent)
{
  QFontDatabase fdb;

  int id1 = fdb.addApplicationFont(":/fonts/SF_Fedora_Titles.ttf");
  int id2 = fdb.addApplicationFont(":/fonts/Ruben.ttf");

//  if (id1 == -1)
//    INFO (":/fonts/SF_Fedora_Titles.ttf could not be loaded");
//  if (id2 == -1)
//    INFO (":/fonts/Ruben.ttf could not be loaded");
//
//  auto f = fdb.applicationFontFamilies(id1);
//  for (const auto& ff : f)
//    INFO ("Family: {}", ff.toStdString());
//
//  f = fdb.applicationFontFamilies(id2);
//  for (const auto& ff : f)
//    INFO ("Family2: {}", ff.toStdString());

//  setMouseTracking(true);
  setAutoFillBackground(true);
}

QColor KnightRiderWidget::color_at(double at) const
{
  // because .color() is not const for some reason :(
  auto gradient = gradient_;
  return gradient.color(at, range_);
}

QColor KnightRiderWidget::min_color() const
{
  if (override_background_)
    return background_;
  else
    return color_at(range_.lower);
}

QColor KnightRiderWidget::max_color() const
{
  return color_at(range_.upper);
}

QColor interpolateHSV(const QColor& a, const QColor& b,
                      double hfrac, double sfrac, double vfrac)
{
  double hue = 0;
  double hueDiff = b.hueF() - a.hueF();
  if (hueDiff > 0.5)
    hue = a.hueF() - hfrac * (1.0 - hueDiff);
  else if (hueDiff < -0.5)
    hue = a.hueF() + hfrac * (1.0 + hueDiff);
  else
    hue = a.hueF() + hfrac * hueDiff;
  if (hue < 0)
    hue += 1.0;
  else if (hue >= 1.0)
    hue -= 1.0;

  QColor ret;
  ret.setHsvF(hue,
              (1.0 - sfrac) * a.hsvSaturationF() + b.hsvSaturationF() * sfrac,
              (1.0 - vfrac) * a.valueF() + b.valueF() * vfrac);
  return ret;
}

QColor KnightRiderWidget::on_color(size_t block, size_t total_blocks) const
{
  double rel_pos = double(block + 1u) / double(total_blocks);
  return color_at(range_.lower + rel_pos * range_.size());
}

QColor KnightRiderWidget::off_color(size_t block, size_t total_blocks) const
{
  return interpolateHSV(min_color(), on_color(block, total_blocks),
      1.0 - dark_block_visibility_,
      dark_block_visibility_,
      dark_block_visibility_);
}

QColor KnightRiderWidget::frac_color(size_t block, size_t total_blocks, double frac) const
{
  return interpolateHSV(off_color(block, total_blocks),
                        on_color(block, total_blocks), 1.0, frac, frac);
}

QColor KnightRiderWidget::block_color(size_t block, size_t total_blocks, double block_val) const
{
  QColor current_color;
  if (static_cast<double>(block) == std::floor(block_val))
    current_color = frac_color(block, total_blocks,
                               block_val - std::floor(block_val));
  else if (static_cast<double>(block) < block_val)
    current_color = on_color(block, total_blocks);
  else
    current_color = off_color(block, total_blocks);
  return current_color;
}

QString KnightRiderWidget::compose_text() const
{
  return prefix_ + " " + QString::number(val_) + " " + suffix_;
}

int KnightRiderWidget::text_height() const
{
  QRect r = QFontMetrics(font_).boundingRect(compose_text());
  return r.height();
}

void KnightRiderWidget::paint_text(QPainter *painter, const QRect &rect, int flags) const
{
  painter->setPen(max_color());
  painter->setFont(font_);
  painter->drawText(rect, flags, compose_text());
}

void KnightRiderWidget::paintEvent(QPaintEvent*)
{
  QPalette pal = palette();
  pal.setColor(QPalette::Background, min_color());
  setPalette(pal);

  QPainter painter(this);
  paint(&painter, rect());
}

int KnightRiderWidget::block_height_with_margin() const
{
  return block_height_ + 2 * block_margin_;
}

QRect KnightRiderWidget::block() const
{
  int block_width = block_height_with_margin() * 2;
  return QRect(width() / 2 - (block_width / 2), block_margin_, block_width, block_height_);
}

void KnightRiderWidget::paint(QPainter* painter, const QRect& rect) const
{
  painter->save();

//  painter->setRenderHint(QPainter::Antialiasing, true);
//  painter->setRenderHint(QPainter::TextAntialiasing, true);

  int height = rect.height() - 20 - 2 * block_margin_ - text_height();
  int total_blocks = height / block_height_with_margin();

  double block_weight = 0;
  if (total_blocks > 0)
    block_weight = range_.size() / static_cast<double>(total_blocks);

  double block_val = 0;
  if (block_weight > 0)
    block_val = (val_ - range_.lower) / block_weight;

  auto box = block();

  painter->translate(0, this->height() - 2 * block_margin_ - text_height());
  paint_text(painter, rect, Qt::AlignTop | Qt::AlignHCenter);
  painter->translate(0, -20);

  painter->setPen(Qt::NoPen);
  for (int i = 0; i < total_blocks; ++i)
  {
    painter->translate(0, -block_height_with_margin());

    QColor current_color = block_color(i, total_blocks, block_val);

    //pen.setColor(current_color);
    //painter->setPen(pen);
    painter->setBrush(current_color);
    painter->drawRect(box);
  }
  painter->restore();
}

void KnightRiderWidget::setDarkBlockVisibility(double dbv)
{
  dark_block_visibility_ = dbv;
}

void KnightRiderWidget::setSuffix(const QString& s)
{
  suffix_ = s;
}

void KnightRiderWidget::setRange(double a, double b)
{
  range_ = QCPRange(std::min(a, b), std::max(a, b));
}

void KnightRiderWidget::setValue(double val)
{
  val_ = val;
}

double KnightRiderWidget::value() const
{
  return val_;
}

//QSize KnightRiderWidget::sizeHint() const
//{
//  return QSize(40, 12);
//}

}
