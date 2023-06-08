#include "central.h"
#include "siren.h"
#include <iostream>


Central::Central() {
    isArmed = false;
    siren = nullptr;
}

void Central::arm() {
    isArmed = true;
}

void Central::disarm() {
    isArmed = false;
}

void Central::setSiren(Siren* s) {
    siren = s;
}

void Central::addNewSensorZone0(Sensor* s) { 
    zone0.push_back(s);
}

void Central::addNewSensorZone1(Sensor* s) { 
    zone1.push_back(s);
}

void Central::checkZone() {
    bool alarma = false;

    for (Sensor* sensor : zone0) {
        if (sensor->isClose() == false) {
            alarma = true; // l
        }
    }

    for (Sensor* sensor : zone1) {
        if (sensor->isClose() == false) {
            alarma = true;
        }
    }

    if (!isArmed) {
        siren->off();
    } else if (isArmed && !alarma) {
        siren->off();
    } else if (alarma && isArmed && siren->getState() == 0) {
        siren->on();
    }
}

std::string Central::getHeader() {
    return "Central";
}

int Central::getState() {
    return isArmed ? 1 : 0;
}
