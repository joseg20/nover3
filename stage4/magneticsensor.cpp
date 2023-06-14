#include "magneticsensor.h"

MagneticSensor::MagneticSensor(int z): Sensor(z, true) {
    view = new MagneticSensorView();
}
void MagneticSensor::setSensorOpen() {
    Sensor::setClose(false);
}
void MagneticSensor::setSensorClose() {
    Sensor::setClose(true);
}
MagneticSensorView * MagneticSensor::getView() {
    return view;
}
MagneticSensor::~MagneticSensor(){
    delete view;
}
