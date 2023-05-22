#ifndef GEODATA_H
#define GEODATA_H

#include "pattern.h"

enum DataStatus {
    NEW_DATA_AVAILABLE = 0,
    ERR_IN_CHECKING,
};

struct GeoData_t {
    struct point_t {int pIndex;}pointObj;
    struct line_t {int lIndex;}lineObj;
    struct area_t {int aIndex;}areaObj;
};

class GeoData : public Observable {
public:
    GeoData() {}
    GeoData_t& getGeoData(void) {return this->geoData;}
    void checkGeoData(void) {
        if(isNewDataAvailable(geoData) == NEW_DATA_AVAILABLE) {
            string status = "Hey listeners! New Data was Received!";
            notify(status);
        }
    }
    DataStatus isNewDataAvailable(GeoData_t& newData) {
        newData.pointObj.pIndex = rand();
        newData.lineObj.lIndex = rand();
        newData.areaObj.aIndex = rand();
        return NEW_DATA_AVAILABLE;
    }
private:
    GeoData_t geoData;
};

#endif // GEODATA_H
