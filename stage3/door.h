#ifndef DOOR_H
#define DOOR_H
class Door;
#include "magneticsensor.h"
#include "doorview.h"
class Door
{
private:
    Door(); // door creation without sensor is not allowed.
public:
    Door(MagneticSensor * sensor, DoorView * v);
    void changeState();
private:
    MagneticSensor * magneticSensor;
    DoorView * view;
    bool isClose;
};

#endif // DOOR_H
