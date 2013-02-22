#include "mainwindow.h"
#include <QtGui>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *menuBar = new QMenuBar();
    QMenu *fileMenu = menuBar->addMenu("File");
    QAction *temp;
    temp = fileMenu->addAction("exit");
    connect(temp,SIGNAL(triggered()), this, SLOT(quit()));
    temp = fileMenu->addAction("Open");
    temp->setEnabled(false);
    temp = fileMenu->addAction("Save");
    temp->setEnabled(false);
    temp = fileMenu->addAction("Save As");
    temp->setEnabled(false);

    QMenu *editMenu = menuBar->addMenu("Edit");
    temp = editMenu->addAction("Cut");
    temp->setEnabled(false);
    temp = editMenu->addAction("Copy");
    temp->setEnabled(false);
    temp = editMenu->addAction("Paste");
    temp->setEnabled(false);

    QMenu *collectionMenu = menuBar->addMenu("Collection");
    temp = collectionMenu->addAction("New Collection");
    temp->setEnabled(false);
    temp = collectionMenu->addAction("New Collection By Tags");
    temp->setEnabled(false);
    temp = collectionMenu->addAction("Play Collection");
    temp->setEnabled(false);
    temp = collectionMenu->addAction("Delete Collection");
    temp->setEnabled(false);
    temp = collectionMenu->addAction("Delete Items in Collection");
    temp->setEnabled(false);

    QMenu *toolsMenu = menuBar->addMenu("Tools");
    temp = toolsMenu->addAction("Play Selected Collections");
    temp->setEnabled(false);
    temp = toolsMenu->addAction("Pause Play");
    temp->setEnabled(false);
    temp = toolsMenu->addAction("Set Play Interval");
    temp->setEnabled(false);

    this->setMenuBar(menuBar);

    /*
    temp = fileMenu->addAction("this writes to cout");
    connect(temp, SIGNAL(triggered()), this, SLOT(writeMessage()));
    temp = fileMenu->addAction("this really doesn't do anything");
    temp->setEnabled(false);
    */

    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *topHalf = new QHBoxLayout;
    QListWidget *leftPanel = new QListWidget;


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


