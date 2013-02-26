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
    scrollArea = new QScrollArea;
    container = new QWidget;
    layout = new QHBoxLayout();
    //newLabel->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));

    imgList = new QListWidget;
    QListWidgetItem *temp = new QListWidgetItem();
    //QLabel *newLabel = new QLabel();

    temp->setText("One");
    imgList->addItem(temp);
    QListWidgetItem *temp2 = new QListWidgetItem();
    temp2->setText("Two");
    imgList->addItem(temp2);
    QListWidgetItem *temp3 = new QListWidgetItem();
    temp3->setText("Three");
    imgList->addItem(temp3);
    QListWidgetItem *temp4 = new QListWidgetItem();
    temp4->setText("four");
    imgList->addItem(temp4);
    QListWidgetItem *temp5 = new QListWidgetItem();
    temp5->setText("five");
    imgList->addItem(temp5);
    QListWidgetItem *temp6 = new QListWidgetItem();
    temp6->setText("six");
    imgList->addItem(temp6);
    QListWidgetItem *temp7 = new QListWidgetItem();
    temp7->setText("seven");
    imgList->addItem(temp7);

    layout->addWidget(imgList);
    QLabel *one = new QLabel("one");
    one->setStyleSheet("font: 50pt;");
    layout->addWidget(one);
    QLabel *two = new QLabel("two");
    two->setStyleSheet("font: 50pt;");
    layout->addWidget(two);
    QLabel *three = new QLabel("three");
    three->setStyleSheet("font: 50pt;");
    layout->addWidget(three);
    QLabel *four = new QLabel("four");
    four->setStyleSheet("font: 50pt;");
    layout->addWidget(four);
    QLabel *five = new QLabel("five");
    five->setStyleSheet("font: 50pt;");
    layout->addWidget(five);
    QLabel *six = new QLabel("six");
    six->setStyleSheet("font: 50pt;");
    layout->addWidget(six);
    QLabel *seven = new QLabel("seven");
    seven->setStyleSheet("font: 50pt;");
    layout->addWidget(seven);
    QLabel *eight = new QLabel("eight");
    eight->setStyleSheet("font: 50pt;");
    layout->addWidget(eight);

    container->setLayout(layout);
    scrollArea->setWidget(container);
    this->setLayout(layout);
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
