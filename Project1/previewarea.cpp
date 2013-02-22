#include "previewarea.h"

#include "mainwindow.h"
#include <QtGui>

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

QPixmap PreviewArea::previewItemt(int)
{
}

PreviewArea::setPreviewItemAt(int, QPixmap)
{

}

PreviewArea::setPreviewItemEnabledAt(int, bool)
{

}

PreviewArea::deletePreviewItemAt(int)
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
void animationChanged(int location)
{

}

void previewItemChanged(int location)
{

}

void previewItemSelected(int location)
{

}
