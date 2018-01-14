#include "Gradients.h"

namespace QPlot
{

Gradients Gradients::defaultGradients()
{
  Gradients ret;
  ret.addStandardGradients();
  return ret;
}

int Gradients::size() const
{
  return gradients_.size();
}

bool Gradients::empty() const
{
  return gradients_.empty();
}

void Gradients::clear()
{
  gradients_.clear();
}

QStringList Gradients::names() const
{
  return gradients_.keys();
}

bool Gradients::contains(QString name) const
{
  return (gradients_.count(name) > 0);
}

QCPColorGradient Gradients::get(QString name) const
{
  if (contains(name))
    return gradients_[name];
  return QCPColorGradient();
}

QCPColorGradient Gradients::get(int idx) const
{
  if ((idx >= 0) && (idx < size()))
    return gradients_[gradients_.keys()[idx]];
  return QCPColorGradient();
}

void Gradients::remove(QString name)
{
  if (contains(name))
    gradients_.remove(name);
}

void Gradients::addStandardGradients()
{
  gradients_["Grayscale"] = QCPColorGradient::gpGrayscale;
  gradients_["Hot"] =  QCPColorGradient::gpHot;
  gradients_["Cold"] = QCPColorGradient::gpCold;
  gradients_["Night"] = QCPColorGradient::gpNight;
  gradients_["Candy"] = QCPColorGradient::gpCandy;
  gradients_["Geography"] = QCPColorGradient::gpGeography;
  gradients_["Ion"] = QCPColorGradient::gpIon;
  gradients_["Thermal"] = QCPColorGradient::gpThermal;
  gradients_["Polar"] = QCPColorGradient::gpPolar;
  gradients_["Spectrum"] = QCPColorGradient::gpSpectrum;
  gradients_["Jet"] = QCPColorGradient::gpJet;
  gradients_["Hues"] = QCPColorGradient::gpHues;

  set("Blues", {"#ffffff","#deebf7","#9ecae1","#3182bd"});
  set("Greens", {"#ffffff","#e5f5e0","#a1d99b","#31a354"});
  set("Oranges", {"#ffffff","#fee6ce","#fdae6b","#e6550d"});
  set("Purples", {"#ffffff","#efedf5","#bcbddc","#756bb1"});
  set("Reds", {"#ffffff","#fee0d2","#fc9272","#de2d26"});
  set("Greys", {"#ffffff","#f0f0f0","#bdbdbd","#636363"});

  set("GnBu5", {"#ffffff","#f0f9e8","#bae4bc","#7bccc4","#43a2ca","#0868ac"});
  set("PuRd5", {"#ffffff","#f1eef6","#d7b5d8","#df65b0","#dd1c77","#980043"});
  set("RdPu5", {"#ffffff","#feebe2","#fbb4b9","#f768a1","#c51b8a","#7a0177"});
  set("YlGn5", {"#ffffff","#ffffcc","#c2e699","#78c679","#31a354","#006837"});
  set("YlGnBu5", {"#ffffff","#ffffcc","#a1dab4","#41b6c4","#2c7fb8","#253494"});

  set("Spectrum2", {"#ffffff","#0000ff","#00ffff","#00ff00","#ffff00","#ff0000","#000000"});
}

void Gradients::set(QString name, QCPColorGradient gr)
{
  gradients_[name] = gr;
}

void Gradients::set(QString name, std::initializer_list<std::string> colors)
{
  QVector<QColor> cols;
  for (auto &c : colors)
    cols.push_back(QColor(QString::fromStdString(c)));

  if (name.isEmpty() || (cols.size() < 2))
    return;

  QCPColorGradient gr;
  gr.clearColorStops();
  for (int i=0; i < cols.size(); ++i)
    gr.setColorStopAt(double(i) / double(cols.size() - 1), cols[i]);
  set(name, gr);
}

}
