#include "window.h"
#include "windowview.h"

Window::Window()
{

}
Window::Window(MagneticSensor * sensor, WindowView * v): magneticSensor(sensor), view(v) { //Editado por gabriel
    isClose=true;
    view->setWindowModel(this);
}
void Window::changeState() {
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
