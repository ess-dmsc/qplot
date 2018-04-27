#pragma once

#include "qcustomplot.h"

namespace QPlot
{

class Gradients
{
  public:
    Gradients() {}
    static Gradients defaultGradients();

    int size() const;
    bool empty() const;
    void clear();

    QStringList names() const;
    bool contains(QString name) const;
    QCPColorGradient get(QString name) const;
    QCPColorGradient get(int idx) const;

    void remove(QString name);
    void addStandardGradients();
    void set(QString name, QCPColorGradient gr);
    void set(QString name, std::initializer_list<std::string> colors);

  private:
    QMap<QString, QCPColorGradient> gradients_;
};

}

