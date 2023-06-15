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

void Central::checkZones()
{
    if(alarmArmed) { // only check zones if the alarm is armed
        bool closeZones[2];
        checkCloseZones(closeZones);
        if (!(closeZones[0] && closeZones[1])){
            std::cout << "Alguna zona esta abierta." << std::endl;
        }
    }
}


void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0] = closeZones[1] = true;
    for (unsigned int i = 0; i < zones.size(); i++){
        closeZones[zones[i]->getZone()] = zones[i]->isClose(); //Editado
    }
}

void Central::armSystem()
{
    if(!alarmArmed) {  // check if the alarm is not already armed
        alarmArmed = true;
    }
}

void Central::disarmSystem()
{
    if(alarmArmed) {  // check if the alarm is armed
        alarmArmed = false;
    }
}

bool Central::isArmed()
{
    return alarmArmed;
}

Central::~Central() {
    delete timer;
}
