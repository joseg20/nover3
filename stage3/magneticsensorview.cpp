#include "magneticsensorview.h"
#include <QBrush>

MagneticSensorView::MagneticSensorView():switchView(0,0,8,6, this),magnetView(0,0,8,6, this)  {
    switchView.setBrush(QBrush(Qt::green));
    magnetView.setBrush(QBrush(Qt::black));
}

void MagneticSensorView::setCloseView(){
    switchView.setBrush(QBrush(Qt::green));  // Cambiar el color de la vista del switch a verde para indicar el estado cerrado
    magnetView.setBrush(QBrush(Qt::black));  // Cambiar el color de la vista del imán a negro para indicar el estado cerrado
}
void MagneticSensorView::setOpenView(){
    switchView.setBrush(QBrush(Qt::red));    // Cambiar el color de la vista del switch a rojo para indicar el estado abierto
    magnetView.setBrush(QBrush(Qt::white));  // Cambiar el color de la vista del imán a blanco para indicar el estado abierto
}
QGraphicsRectItem & MagneticSensorView::getSwitchView(){
    return switchView;
}
QGraphicsRectItem & MagneticSensorView::getMagnetView(){
    return magnetView;
}
