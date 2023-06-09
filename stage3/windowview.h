#ifndef WINDOWVIEW_H
#define WINDOWVIEW_H

class WindowView;
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include "window.h"
#include "magneticsensorview.h"

class WindowView : public QGraphicsItemGroup
{
public:
    explicit WindowView(int x, int y, int angle, MagneticSensorView * msView);
    void setWindowModel(Window * model);
    void setOpen();
    void setClose();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);
    ~WindowView();
private:
    void installMagneticSensor(MagneticSensorView & msView);
    void makeWindowView();
    Window * model;
    QGraphicsRectItem * windowPanel;
    QGraphicsRectItem * slidingPanel;
    QGraphicsPolygonItem * origenPillar;
    QGraphicsPolygonItem * switchPillar;
    QGraphicsRectItem * magnet;
    MagneticSensorView *sensorView;
};
#endif // WINDOWVIEW_H
