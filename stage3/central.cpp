#include "central.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones())); //Editado
    timer->start(200);
}

void Central::addNewSensor(Sensor *ps) {
    zones.push_back(ps);
}

void Central::checkZones() {
    bool closeZones[2];
    checkCloseZones(closeZones);
    if (!(closeZones[0] && closeZones[1])){}
       //std::cout << "Alguna zona está abierta." << std::endl;
}

void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;
    for (unsigned int i = 0; i < zones.size(); i++){
        if(zones[i]->isClose()){
            std::cout << "Alguna zona está cerrada." << std::endl;
            std::cout << zones[i] << std::endl;
        }
        closeZones[zones[i]->getZone()] = zones[i]->isClose(); //Editado
    }
}

Central::~Central() {
    delete timer;
}
