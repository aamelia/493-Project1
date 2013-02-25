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
    size=10;
    parent=0;
}

PreviewArea::~PreviewArea()
{

}

QPixmap PreviewArea::previewItemAt(int location)
{

}

void PreviewArea::setPreviewItemAt(int, QPixmap)
{

}

void PreviewArea::setPreviewItemEnabledAt(int, bool)
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

