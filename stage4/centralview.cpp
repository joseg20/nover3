#include "centralview.h"
#include "qgraphicsgridlayout.h"
#include "qgraphicsproxywidget.h"
#include <QPushButton>
#include <QGraphicsLinearLayout>

CentralView::CentralView(Central* central) : central(central), armButton(new QPushButton("Arm")), disarmButton(new QPushButton("Disarm")),
    armButtonProxy(new QGraphicsProxyWidget), disarmButtonProxy(new QGraphicsProxyWidget)
{
    addButtons();
    addSiren();
    addLabel();
    addSeparator(1);
}
void CentralView::addButtons()
{
    armButton = new QPushButton("Arm");
    disarmButton = new QPushButton("Disarm");

    QGraphicsGridLayout *layout = new QGraphicsGridLayout;

    armButtonProxy->setWidget(armButton);
    disarmButtonProxy->setWidget(disarmButton);

    layout->addItem(armButtonProxy, 3, 0);
    layout->addItem(disarmButtonProxy, 3, 1);

    this->setLayout(layout);

    // connect buttons to arm and disarm functions
    connect(armButton, &QPushButton::clicked, this, [this]() {
        central->armSystem();
        statusLabel->setText("System status: Armed");
    });
    connect(disarmButton, &QPushButton::clicked, this, [this]() {
        central->disarmSystem();
        statusLabel->setText("System status: Disarmed");
    });

}



void CentralView::addLabel()
{
    statusLabel = new QLabel("System status: Unknown");
    statusLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    statusLabel->setAlignment(Qt::AlignCenter);

    QGraphicsProxyWidget *labelProxy = new QGraphicsProxyWidget;
    labelProxy->setWidget(statusLabel);

    QGraphicsGridLayout *layout = static_cast<QGraphicsGridLayout*>(this->layout());
    layout->addItem(labelProxy, 2, 0, 1, 2);
    layout->setAlignment(labelProxy, Qt::AlignCenter);
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

void CentralView::addSeparator(int row)
{
    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame::HLine);
    frame->setFrameShadow(QFrame::Sunken);
    frame->setMaximumHeight(2);  // Set a maximum height
    frame->setMaximumWidth(200);

    QGraphicsProxyWidget *frameProxy = new QGraphicsProxyWidget;
    frameProxy->setWidget(frame);

    QGraphicsGridLayout *layout = static_cast<QGraphicsGridLayout*>(this->layout());
    layout->addItem(frameProxy, row, 0, 1, 2);  // Agrega la línea de separación en la fila especificada, extendiéndose a lo largo de ambas columnas

}


