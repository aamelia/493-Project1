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
    startAnimation(2000);

    container = new QWidget;
    layout = new QHBoxLayout();

    QLabel *item1 = new QLabel();
    item1->setFixedSize(100,100);
    QLabel *item2 = new QLabel();
    item2->setFixedSize(100,100);
    QLabel *item3 = new QLabel();
    item3->setFixedSize(100,100);
    QLabel *item4 = new QLabel();
    item4->setFixedSize(100,100);
    QLabel *item5 = new QLabel();
    item5->setFixedSize(100,100);
    QLabel *item6 = new QLabel();
    item6->setFixedSize(100,100);
    QLabel *item7 = new QLabel();
    item7->setFixedSize(100,100);
    QLabel *item8 = new QLabel();
    item8->setFixedSize(100,100);
    QLabel *item9 = new QLabel();
    item9->setFixedSize(100,100);
    QLabel *item10 = new QLabel();
    item10->setFixedSize(100,100);

    QPixmap michigan;
    michigan = QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg");
    michigan.scaled(100, 100, Qt::KeepAspectRatio);

    item1->setScaledContents(true);
    item2->setScaledContents(true);
    item3->setScaledContents(true);
    item4->setScaledContents(true);
    item5->setScaledContents(true);
    item6->setScaledContents(true);
    item7->setScaledContents(true);
    item8->setScaledContents(true);
    item9->setScaledContents(true);
    item10->setScaledContents(true);

    layout->addWidget(item1);
    layout->addWidget(item2);
    layout->addWidget(item3);
    layout->addWidget(item4);
    layout->addWidget(item5);
    layout->addWidget(item6);
    layout->addWidget(item7);
    layout->addWidget(item8);
    layout->addWidget(item9);
    layout->addWidget(item10);

    container->setLayout(layout);
    container->setMaximumHeight(110);
    this->setWidget(container);
}

PreviewArea::~PreviewArea()
{
}

QPixmap PreviewArea::previewItemAt(int location)
{
    QWidget *temp = layout->itemAt(location)->widget();
    QLabel *temp2 = qobject_cast<QLabel *>(temp);
    QPixmap temp3 = QPixmap(*temp2->pixmap());
    setPreviewItemEnabledAt(location, true);
    return temp3;

}

void PreviewArea::setPreviewItemAt(int location, QPixmap temp)
{
    temp.scaled(100, 100, Qt::KeepAspectRatio);
    QWidget *tempW = layout->itemAt(location)->widget();
    QLabel *temp2 = qobject_cast<QLabel *>(tempW);
    temp2->setScaledContents(true);
    temp2->setPixmap(temp);
    layout->insertWidget(location, temp2);
}

void PreviewArea::setPreviewItemEnabledAt(int location, bool enabled)
{
    /*
    cout << "Setting enabled at " << location << endl;
    enabled=true;

    QWidget *temp = layout->takeAt(location)->widget();
    QLabel *temp2 = qobject_cast<QLabel *>(temp);
    temp2->setFrameShape(QFrame::Box);
    QWidget *temp3 = new QWidget(temp2);
    layout->insertWidget(location, temp3);

    QWidget *uno = layout->takeAt(location-1)->widget();
    QLabel *dos = qobject_cast<QLabel *>(uno);
    //dos->setFrameShape(QFrame::Box);
    QWidget *tres = new QWidget(dos);
    layout->insertWidget(location-1, tres);
    cout << "disabling border of " << location-1 << endl;
    */

}

void PreviewArea::deletePreviewItemAt(int location)
{
    location=5;
    /* Does not need to be implemented for this project */
}

//Public slots
void PreviewArea :: startAnimation(int timerInterval)
{

    timer->start(2000);
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
