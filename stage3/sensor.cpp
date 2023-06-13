#include "sensor.h"
#include <iostream>

Sensor::Sensor(int z, bool close) {
    zone = z;
    this->close = close;
}

bool Sensor::isClose() const {
    return close;
}

int Sensor::getZone() const {
    return zone;
}

void Sensor::setClose(bool isClose) {
    close = isClose;
}

