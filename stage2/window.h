#ifndef WINDOW_H
#define WINDOW_H
#include "magnetic_sensor.h"

class Window
{
private:
    Window();
public:
    Window(MagneticSensor sensor);
    void changeState();
    MagneticSensor* getSensor();
private:
    MagneticSensor magneticSensor;
};

#endif // WINDOW_H
