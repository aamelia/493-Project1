#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *topHalf = new QHBoxLayout;

    QLabel *left = new QLabel("Left Side");
    QLabel *bottom = new QLabel("Bottom");
    bottom->setAlignment(Qt::AlignCenter);
    QLabel *mainImage = new QLabel;
    mainImage->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
    mainImage->setFixedSize(900,600);

    topHalf->addWidget(left);
    topHalf->addWidget(mainImage);
    layout->addLayout(topHalf);
    layout->addWidget(bottom);

    window->setLayout(layout);
    this->setCentralWidget(window);
 }

MainWindow::~MainWindow()
{
    
}


