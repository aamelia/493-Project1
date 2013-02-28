#include "previewarea.h"
#include <QtGui>
#include <QWidget>
#include <QLayout>
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>


//Public
PreviewArea::PreviewArea (int size, QWidget *parent)
    : QScrollArea(parent)
{
    size = 5;
    itemNum = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    startAnimation(1000);

    container = new QWidget;
    layout = new QHBoxLayout();


    for(int i=0; i<1; i++)
    {
        QLabel *temp = new QLabel();
        temp->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
        temp->setFixedSize(100,100);
        temp->setScaledContents(true);
        layout->addWidget(temp);
    }


    container->setLayout(layout);
    this->setWidget(container);
}

PreviewArea::~PreviewArea()
{
}

QPixmap PreviewArea::previewItemAt(int location)
{
    QWidget *temp = layout->itemAt(location)->widget();
    //return *QLabel(layout->itemAt(location)->widget()).pixmap();
    QLabel *temp2 = qobject_cast<QLabel *>(temp);
    QPixmap temp3 = QPixmap(*temp2->pixmap());
    return temp3;

}

void PreviewArea::setPreviewItemAt(int location, QPixmap temp)
{
    location=0;
    QLabel *tempLabel = new QLabel();
    tempLabel->setPixmap(temp);
    tempLabel->setFixedSize(100,100);
    tempLabel->setScaledContents(true);
    layout->addWidget(tempLabel);
}

void PreviewArea::setPreviewItemEnabledAt(int location, bool enabled)
{
    location=5;
    enabled=true;
    /* Does not need to be implemented for this project */
}

void PreviewArea::deletePreviewItemAt(int location)
{
    location=5;
    /* Does not need to be implemented for this project */
}

//Public slots
void PreviewArea :: startAnimation(int timerInterval)
{
    timer->start(timerInterval);
}

void PreviewArea :: stopAnimation()
{
    timer->stop();
}

void PreviewArea :: timerTick(void)
{
    itemNum++;
    itemNum = itemNum % 10;
    emit(animationChanged(itemNum));
}
