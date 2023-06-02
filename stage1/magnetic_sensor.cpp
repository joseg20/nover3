#include "magnetic_sensor.h"

MagneticSensor::MagneticSensor(int z) : Sensor(z, false) {
}
void MagneticSensor::setSensorOpen() {
    Sensor::setClose(false);
}
void MagneticSensor::setSensorClose() {
    Sensor::setClose(true);
}
