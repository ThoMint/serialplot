/*
  Copyright © 2017 Hasan Yavuz Özderya

  This file is part of serialplot.

  serialplot is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  serialplot is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with serialplot.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PLOTMENU_H
#define PLOTMENU_H

#include <QMenu>
#include <QAction>
#include <QSettings>

#include "plot.h"

/// Used to quickly transfer view options between different menus
struct PlotViewSettings
{
    bool showGrid;
    bool showMinorGrid;
    bool darkBackground;
    bool showLegend;
    bool showMulti;
    Plot::ShowSymbols showSymbols;
};

class PlotMenu : public QMenu
{
    Q_OBJECT

public:
    PlotMenu(QWidget* parent = 0);
    PlotMenu(PlotViewSettings s, QWidget* parent = 0);

    QAction showGridAction;
    QAction showMinorGridAction;
    QAction unzoomAction;
    QAction darkBackgroundAction;
    QAction showLegendAction;
    QAction showMultiAction;
    QAction setSymbolsAction;
    QMenu setSymbolsMenu;
    QAction setSymbolsAutoAct;
    QAction setSymbolsShowAct;
    QAction setSymbolsHideAct;
    QAction setLineWidthAction;
    QMenu setLineWidthMenu;
    QAction setLineWidth0Act;
    QAction setLineWidth1Act;
    QAction setLineWidth2Act;

    /// Returns a bundle of current view settings (menu selections)
    PlotViewSettings viewSettings() const;
    /// Selected "show symbol" option
    Plot::ShowSymbols showSymbols() const;
    /// Stores plot settings into a `QSettings`.
    void saveSettings(QSettings* settings);
    /// Loads plot settings from a `QSettings`.
    void loadSettings(QSettings* settings);

signals:
    void symbolShowChanged(Plot::ShowSymbols shown);
    void lineWidthChanged(Plot::LineWidths lw);
};

#endif // PLOTMENU_H
