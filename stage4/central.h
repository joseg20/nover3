#ifndef CENTRAL_H
#define CENTRAL_H

#include <QObject>
#include <vector>
#include <QTimer>
#include "sensor.h"
#include "door.h"
#include "doorview.h"
#include "magneticsensor.h"

class Central : public QObject
{
    Q_OBJECT
public:
    explicit Central(QObject *parent = nullptr);
    void addNewSensor(Sensor *ps);
    ~Central();

    void arm();
    void disarm();

private slots:
    void checkZones();


private:
    void checkCloseZones(bool closeZones[]);
    std::vector<Sensor *> zones;  // keep references to all sensors already installed in doors and windows.
    QTimer *timer;
};

#endif // CENTRAL_H
