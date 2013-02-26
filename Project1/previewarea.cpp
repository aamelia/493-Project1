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
    : QWidget(parent)
{
    scrollArea = new QScrollArea;
    container = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(this);
    imgList = new QListWidget;

    //imgList->addItem(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
    layout->addWidget(imgList);
    container->setLayout(layout);
    scrollArea->setWidget(container);
}

PreviewArea::~PreviewArea()
{
}

QPixmap PreviewArea::previewItemAt(int location)
{

}

void PreviewArea::setPreviewItemAt(int location, QPixmap temp)
{

}

void PreviewArea::setPreviewItemEnabledAt(int location, bool enabled)
{

}

void PreviewArea::deletePreviewItemAt(int)
{

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
