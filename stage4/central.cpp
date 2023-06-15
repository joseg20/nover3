#include "central.h"
#include "central.h"
#include "sirenview.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    timer->start(200);
    alarmAlert = false;
}

void Central::addNewSensor(Sensor *ps) {
    zones.push_back(ps);
}

void Central::checkZones()
{
        int closeZones[2];
        checkCloseZones(closeZones);
        if ((closeZones[0]+closeZones[1])){
            std::cout << "Alguna zona esta abierta." << std::endl;
            if(alarmArmed){
                sirenView->startBlinking();
            }
            alarmAlert = true;
        } else if (closeZones[0] && closeZones[1]){
            alarmAlert= false;
        }
}

void Central::checkCloseZones(int closeZones[]) {
        closeZones[0] = 0;
        closeZones[1] = 0;

        for (unsigned int i = 0; i < zones.size(); i++){
            if (!zones[i]->isClose()) {
                closeZones[zones[i]->getZone()] +=1;
            }
        }
}

void Central::armSystem()
{
    if(!alarmAlert) {
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


