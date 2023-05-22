#ifndef MAPRENDER_H
#define MAPRENDER_H

#include "pattern.h"
#include "geoData.h"
#include "mainwindow.h"
#include <QDebug>

class MapRender : public Observer {
public:
    MapRender(GeoData& geoData, MainWindow& window) : geoDataObj(geoData), windowObj(window) {}
    void update(string& status) {
        qDebug() << status << "\n";
        windowObj.updateLCDNumber(geoDataObj.getGeoData());
        windowObj.updateStatusBar(status);
    }
private:
    GeoData& geoDataObj;
    MainWindow& windowObj;
};

#endif // MAPRENDER_H
