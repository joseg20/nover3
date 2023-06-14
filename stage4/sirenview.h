#ifndef SIRENVIEW_H
#define SIRENVIEW_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>

class SirenView : public QWidget
{
    Q_OBJECT

public:
    explicit SirenView(QWidget* parent = nullptr);

    void startBlinking();
    void stopBlinking();

public slots:
    void changeColor();

private:
    QLabel* sirenLabel;
    QTimer* timer;
    bool isRed;
};

#endif // SIRENVIEW_H
