#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *topHalf = new QHBoxLayout;
    QListView *leftPanel = new QListView;

    QLabel *left = new QLabel("Left Side");
    QLabel *mainImage = new QLabel;
    mainImage->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
    mainImage->setFixedSize(900,600);

    QScrollArea *bottom = new QScrollArea;
    QLabel *text1 = new QLabel("Text1");
    QLabel *text2 = new QLabel("Text2");

    QHBoxLayout *previewArea = new QHBoxLayout;
    previewArea->addWidget(text1);
    previewArea->addWidget(text2);
    bottom->setLayout(previewArea);

    topHalf->addWidget(leftPanel);
    topHalf->addWidget(mainImage);
    layout->addLayout(topHalf);
    layout->addWidget(bottom);

    window->setLayout(layout);
    this->setCentralWidget(window);
 }

MainWindow::~MainWindow()
{
    
}


