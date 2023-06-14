#include "sirenview.h"

SirenView::SirenView(QWidget* parent)
    : QWidget(parent),
    sirenLabel(new QLabel(this)),
    timer(new QTimer(this)),
    isRed(false)
{
    connect(timer, &QTimer::timeout, this, &SirenView::changeColor);

    // Definimos el color inicial
    sirenLabel->setStyleSheet("background-color: green;");
    sirenLabel->setFixedSize(80, 80); // Tamaño de QLabel

    // Alineamos QLabel en el centro
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(sirenLabel, 0, Qt::AlignCenter);
}

void SirenView::startBlinking()
{
    timer->start(200);
}

void SirenView::stopBlinking()
{
    timer->stop();
    isRed = false;
    sirenLabel->setStyleSheet("background-color: green;");
}

void SirenView::changeColor()
{
    isRed = !isRed;
    if (isRed) {
        sirenLabel->setStyleSheet("background-color: red;");
    } else {
        sirenLabel->setStyleSheet("background-color: green;");
    }
}
