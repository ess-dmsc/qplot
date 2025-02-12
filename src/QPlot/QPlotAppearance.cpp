#include <QPlot/QPlotAppearance.h>

namespace QPlot
{

QPen Appearance::getPen(const QString &theme) const
{
  if (themes.count(theme))
    return themes[theme];
  else
    return default_pen;
}

}


