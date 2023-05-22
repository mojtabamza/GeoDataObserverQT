#include "mainwindow.h"

#include <QApplication>
#include "pattern.h"
#include "geoData.h"
#include "mapRender.h"
#include "taskManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    GeoData geoDataObj;
    MapRender mapRenderObj(geoDataObj, window);

    geoDataObj.attach(mapRenderObj);

    auto SystickObj = Systick::getInstance();
    SystickObj->addTask("CheckGeodata : flag[0]", 1000);
    SystickObj->addTask("ClsStatusBar : flag[1]", 1200);

    while(1) {
        SystickObj->systickHandler();

        if(SystickObj->flags[0]) {
            geoDataObj.checkGeoData();
            QApplication::processEvents();
            SystickObj->flags[0] = false;
        }
        if(SystickObj->flags[1]) {
            window.refreshStatusBar();
            QApplication::processEvents();
            SystickObj->flags[1] = false;
        }
    }
    geoDataObj.detach(mapRenderObj);
    return a.exec();
}
