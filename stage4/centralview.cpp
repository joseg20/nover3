#include "centralview.h"
#include "qgraphicsgridlayout.h"
#include "qgraphicsproxywidget.h"
#include "qgraphicsscene.h"
#include <QPushButton>
#include <QGraphicsLinearLayout>

CentralView::CentralView() : armButton(new QPushButton("Arm")), disarmButton(new QPushButton("Disarm")),
    armButtonProxy(new QGraphicsProxyWidget), disarmButtonProxy(new QGraphicsProxyWidget)
{
    addButtons();
    addSiren();
}
void CentralView::addButtons()
{
    QPushButton *armButton = new QPushButton("Arm");
    QPushButton *disarmButton = new QPushButton("Disarm");

    QGraphicsGridLayout *layout = new QGraphicsGridLayout;
    QGraphicsProxyWidget *armButtonProxy = new QGraphicsProxyWidget;
    QGraphicsProxyWidget *disarmButtonProxy = new QGraphicsProxyWidget;

    armButtonProxy->setWidget(armButton);
    disarmButtonProxy->setWidget(disarmButton);

    layout->addItem(armButtonProxy, 1, 0);
    layout->addItem(disarmButtonProxy, 1, 1);

    this->setLayout(layout);
}

void CentralView::addSiren()
{
    sirenView = new SirenView();
    QGraphicsProxyWidget *sirenViewProxy = new QGraphicsProxyWidget;
    sirenViewProxy->setWidget(sirenView);

    QGraphicsGridLayout *layout = static_cast<QGraphicsGridLayout*>(this->layout());
    layout->addItem(sirenViewProxy, 0, 0, 1, 2); // Agrega la sirena en la segunda fila, ocupando dos columnas

    layout->setRowStretchFactor(0, 1); // Expande la primera fila verticalmente
}


