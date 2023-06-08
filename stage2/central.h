#ifndef CENTRAL_H
#define CENTRAL_H

#include <vector>
#include <string>
#include "magnetic_sensor.h"

class Siren;  // Declaración anticipada de Siren

class Central {
public:
    Central();
    void arm();
    void disarm();
    void setSiren(Siren* siren);
    void addNewSensorZone0(Sensor* s);
    void addNewSensorZone1(Sensor* s);
    void checkZone();
    std::string getHeader();
    int getState();

private:
    std::vector<Sensor*> zone0;
    std::vector<Sensor*> zone1;
    bool isArmed;
    Siren* siren;
};

#endif // CENTRAL_H
