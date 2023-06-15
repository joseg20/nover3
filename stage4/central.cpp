#include "central.h"
#include "central.h"
#include "sirenview.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones())); //Editado
    timer->start(200);
    alarmAlert = false;
}

void Central::addNewSensor(Sensor *ps) {
    zones.push_back(ps);
}

void Central::checkZones()
{
        bool closeZones[2];
        checkCloseZones(closeZones);
        if (!(closeZones[0] && closeZones[1])){
            std::cout << "Alguna zona esta abierta." << std::endl;
            if(alarmArmed){
                sirenView->startBlinking();
            }
            alarmAlert = true;
        } else if (closeZones[0] && closeZones[1]){
            alarmAlert= false;
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
    if(!alarmAlert) {  // check if the alarm is not already armed
        alarmArmed = true;
    }
}

bool Central::isAlarmOn()
{
    return alarmAlert;
}

void Central::disarmSystem()
{
    alarmArmed = false;
    alarmAlert = false;
    sirenView->stopBlinking();
}

void Central::setSirenView(SirenView* sirenView)
{
    this->sirenView = sirenView;
}

Central::~Central() {
    delete timer;
}


