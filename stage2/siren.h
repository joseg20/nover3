#ifndef SIREN_H
#define SIREN_H
#include <string>
using namespace std;
#include "sensor.h"
#include "magnetic_sensor.h"
#include "central.h"

class Siren {
public: Siren();
    void on();
    void off();
    int getState();
    string getHeader();
private: 
    int state;
};

#endif
