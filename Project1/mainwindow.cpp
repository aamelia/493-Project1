#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QScopedPointer<QWidget> window(new QWidget);
    QScopedPointer<QHBoxLayout> listMainImage(new QHBoxLayout);
    QScopedPointer<QHBoxLayout> previewArea(new QHBoxLayout);
    QScopedPointer<QVBoxLayout> combine (new QVBoxLayout);

    QLabel *hello = new QLabel("Hello World");

    QLabel *mainImage = new QLabel;
    mainImage->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
    listMainImage->addWidget(hello);
    listMainImage->addWidget(mainImage);

    //*bottomScroll = new QScrollArea;
    //*previewArea = new QHBoxLayout;
    //bottomScroll->setWidget(previewArea);
    //layout->addWidget(bottomScroll);

    QLabel *previewImage = new QLabel;
    previewImage->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
    previewArea->addWidget(previewImage);

    combine.addWidget(listMainImage);
    combine.addWidget(previewArea);
    window->setLayout(combine.data());
    combine.take(); // ownership transferred

    setCentralWidget(window.data());
    QWidget *const windowPtr = window.take(); // ownership transferred
    windowPtr->show();
 }

MainWindow::~MainWindow()
{
    
}


