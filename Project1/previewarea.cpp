#include "previewarea.h"
#include "mainwindow.h"
#include <QtGui>
#include <QMainWindow>


#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>


//Public
PreviewArea::PreviewArea(int size, QWidget *parent)
{
    //size=10;
    //parent=0;
    QScrollArea *scroll = new QScrollArea;

}

PreviewArea::~PreviewArea()
{
}

QPixmap PreviewArea::previewItemAt(int location)
{
    //QPixmap temp;
    //QLabel temp2;
    //temp2 = imgList[location];
    //temp = temp2->pixmap();
    //return imgList[location].pixmap();
}

void PreviewArea::setPreviewItemAt(int location, QPixmap temp)
{
    //imgList[location] = temp;
}

void PreviewArea::setPreviewItemEnabledAt(int location, bool enabled)
{

}

void PreviewArea::deletePreviewItemAt(int)
{

}

//Public slots
void startAnimation(int timerInterval)
{

}

void stopAnimation()
{

}

void timerTick(void)
{

}

//Signals
void animationChanged(int)
{

}

void previewItemChanged(int)
{

}

void previewItemSelected(int)
{

}

