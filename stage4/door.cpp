#include "door.h"
#include "doorview.h"

Door::Door()
{

}
Door::Door(MagneticSensor * sensor, DoorView * v): magneticSensor(sensor), view(v) { //Editado por gabriel
    isClose=true;
    view->setDoorModel(this);
}
void Door::changeState() {
    if (isClose) {
        isClose = false;
        view->setOpen(); //editado
        magneticSensor->setClose(false);
    } else {
        isClose = true;
        view->setClose(); //editado
        magneticSensor->setClose(true);
    }
}

