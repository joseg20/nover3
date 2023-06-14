#ifndef HOUSEWINDOW_H
#define HOUSEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class HouseWindow; }
QT_END_NAMESPACE

class HouseWindow : public QMainWindow
{
    Q_OBJECT

public:
    HouseWindow(QWidget *parent = nullptr);
    void addHouseHollow(QGraphicsItemGroup * ); // doors and windows
    void addCentralHollow(QGraphicsWidget *widget);

    ~HouseWindow();

private:
    Ui::HouseWindow *ui; //Apunta a un objeto Widget HouseWindow
    QGraphicsScene interiorScene;
    QGraphicsScene interiorSceneCentral;
};
#endif // HOUSEWINDOW_H
