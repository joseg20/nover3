#ifndef CENTRALVIEW_H
#define CENTRALVIEW_H

#include "sirenview.h"
#include <QGraphicsWidget>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class CentralView : public QGraphicsWidget
{
public:
    CentralView();

    void addButtons();
    void addSiren();

private:
    QPushButton *armButton;
    QPushButton *disarmButton;
    QGraphicsProxyWidget *armButtonProxy;
    QGraphicsProxyWidget *disarmButtonProxy;
    SirenView* sirenView;
};

#endif // CENTRALVIEW_H
