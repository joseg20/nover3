#include "housewindow.h"
#include "ui_housewindow.h"
#include <QPushButton>
#include <QGraphicsProxyWidget>


HouseWindow::HouseWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::HouseWindow)
{
    ui->setupUi(this);
    ui->houseRegion->setScene(&interiorScene);
    ui->alarmRegion->setScene(&interiorSceneCentral);
}

void HouseWindow::addHouseHollow(QGraphicsItemGroup * compoundItem){
    interiorScene.addItem(compoundItem);
}
void HouseWindow::addCentralHollow(QGraphicsWidget *widget)
{
    interiorSceneCentral.addItem(widget);
}

HouseWindow::~HouseWindow()
{
    delete ui;
}

