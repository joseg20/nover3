#ifndef DOOR_H
#define DOOR_H
#include "magnetic_sensor.h"
class Door
{
private:
    Door(); 
public:
    Door(MagneticSensor sensor);
    void changeState();
    MagneticSensor* getSensor();
private:
    MagneticSensor magneticSensor;
};

#endif // DOOR_H
