#ifndef CENTRALVIEW_H
#define CENTRALVIEW_H

#include "central.h"
#include "sirenview.h"
#include <QGraphicsWidget>
#include <QPushButton>
#include <QGraphicsProxyWidget>

class CentralView : public QGraphicsWidget
{

public:
    CentralView(Central* central);
    void addButtons();
    void addSiren();
    void addLabel();
    void addSeparator(int row);


private:
    Central* central;
    QPushButton *armButton;
    QPushButton *disarmButton;
    QGraphicsProxyWidget *armButtonProxy;
    QGraphicsProxyWidget *disarmButtonProxy;
    SirenView* sirenView;
    QLabel* statusLabel;
};

#endif // CENTRALVIEW_H
