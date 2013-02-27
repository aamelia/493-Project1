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
    container = new QWidget;
    layout = new QHBoxLayout();

    for(int i=0; i<3; i++)
    {
        QLabel *temp = new QLabel();
        temp->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
        temp->setFixedSize(100,100);
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
    //QLabel tempLabel;
    //QLabel tempLabel = new QLabel(layout->itemAt(location)->widget()).pixmap();
    //QPixmap *tempPixmap = new QPixmap(*tempLabel.pixmap());
    //return *tempPixmap;
}

void PreviewArea::setPreviewItemAt(int location, QPixmap temp)
{
    QLabel *tempLabel = new QLabel();
    tempLabel->setPixmap(temp);
    layout->insertWidget(location, tempLabel);
    int height = temp.height();
    int width = temp.width();
    cout << "Height = " << height << endl;
    cout << "Width = " << width << endl;
}

void PreviewArea::setPreviewItemEnabledAt(int location, bool enabled)
{

}

void PreviewArea::deletePreviewItemAt(int location)
{
    QLayoutItem *temp;// = new QWidgetItem();
    temp=layout->itemAt(location);
    layout->removeItem(temp);
    delete temp;
}

//Public slots
void PreviewArea :: startAnimation(int timerInterval)
{

}

void PreviewArea :: stopAnimation()
{

}

void PreviewArea :: timerTick(void)
{

}
