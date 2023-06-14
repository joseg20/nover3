#include "windowview.h"
#include <QBrush>
#include <QPen>
#include <iostream>
WindowView::WindowView(int x, int y, int angle, MagneticSensorView * mv) {
    makeWindowView();
    mv->setParentItem(this);
    installMagneticSensor(*mv);
    magnet = &(mv->getMagnetView());
    QTransform transform;
    transform.translate(x,y);
    transform.rotate(angle);
    setTransform(transform);
}
void WindowView::makeWindowView(){
    QPolygonF rectPoly;
    rectPoly << QPointF(0, 0) << QPointF(20, 0) << QPointF(20, 20) << QPointF(0, 20);

    switchPillar = new QGraphicsPolygonItem(rectPoly, this);
    switchPillar->setPos(180, 0);
    switchPillar->setBrush(Qt::blue);

    origenPillar = new QGraphicsPolygonItem(rectPoly, this);
    origenPillar->setPos(0, 0);
    origenPillar->setBrush(Qt::blue);

    windowPanel = new QGraphicsRectItem(21, 4, 82, 6, this); //Editado
    windowPanel->setBrush(Qt::blue);

    slidingPanel = new QGraphicsRectItem(97, 11, 82, 6, this);
    slidingPanel->setBrush(Qt::blue);
    slidingPanel->setAcceptHoverEvents(true);
    slidingPanel->setPen(QPen(Qt::black));

    addToGroup(origenPillar);
    addToGroup(switchPillar);
    addToGroup(windowPanel);
}
void WindowView::setWindowModel(Window * m){
    model=m;
}
void WindowView::installMagneticSensor(MagneticSensorView & mv){
    sensorView = &mv;
    mv.getMagnetView().setRect(slidingPanel->rect().right()-mv.getMagnetView().rect().width(),
                               slidingPanel->rect().bottom(),
                               mv.getMagnetView().rect().width(),
                               mv.getMagnetView().rect().height());
    mv.getSwitchView().setRect(switchPillar->x(),
                               switchPillar->boundingRect().bottom()-1,
                               mv.getSwitchView().rect().width(),
                               mv.getSwitchView().rect().height());
    mv.getMagnetView().setTransformOriginPoint(slidingPanel->rect().left(), slidingPanel->rect().bottom());
    addToGroup(&mv.getMagnetView());
    addToGroup(&mv.getSwitchView());
}
void WindowView::setOpen() {
    sensorView->getSwitchView().setBrush(Qt::red);
    slidingPanel->setPos(slidingPanel->pos().x()- windowPanel->rect().width() - 5 + switchPillar->boundingRect().width()/2, slidingPanel->y());
    magnet->setRect(slidingPanel->rect().right() - magnet->rect().width(),
                    slidingPanel->rect().bottom(),
                    magnet->rect().width(),
                    magnet->rect().height());
    magnet->setPos(slidingPanel->pos().x() - 10 + switchPillar->boundingRect().width() / 2, slidingPanel->y());
}
void WindowView::setClose() {
    sensorView->getSwitchView().setBrush(Qt::green);
    slidingPanel->setPos(0, slidingPanel->y());
    magnet->setRect(slidingPanel->rect().right() - magnet->rect().width(),
                    slidingPanel->rect().bottom(),
                    magnet->rect().width(),
                    magnet->rect().height());
    magnet->setPos(slidingPanel->pos().x(), slidingPanel->y());
}
void WindowView::mousePressEvent(QGraphicsSceneMouseEvent * event){
    if (model!= NULL && event->button()==Qt::LeftButton)
        model->changeState();
}
WindowView::~WindowView(){
    delete windowPanel;
    delete switchPillar;
}
