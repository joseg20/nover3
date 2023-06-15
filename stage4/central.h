#ifndef CENTRAL_H
#define CENTRAL_H

#include <QObject>
#include <vector>
#include <QTimer>
#include "sensor.h"

class CentralView;
class SirenView;


class Central : public QObject
{
    Q_OBJECT
public:
    explicit Central(QObject *parent = nullptr);
    void addNewSensor(Sensor *ps);
    bool isAlarmOn();
    void setSirenView(SirenView *sirenView);

    ~Central();

public slots:
    void armSystem();
    void disarmSystem();

private slots:
    void checkZones();


private:
    bool alarmArmed;
    bool alarmAlert;
    void checkCloseZones(bool closeZones[]);
    std::vector<Sensor *> zones;  // keep references to all sensors already installed in doors and windows.
    QTimer *timer;
    SirenView* sirenView;
};

#endif // CENTRAL_H
