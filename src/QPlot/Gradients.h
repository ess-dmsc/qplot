#pragma once

#include <QPlot/qcustomplot/qcustomplot.h>

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
    bool contains(const QString &name) const;
    QCPColorGradient get(const QString &name) const;
    QCPColorGradient get(int idx) const;

    void remove(const QString &name);
    void addStandardGradients();
    void set(const QString &name, QCPColorGradient gr);
    void set(const QString &name, std::initializer_list<std::string> colors);

  private:
    QMap<QString, QCPColorGradient> gradients_;
};

}

