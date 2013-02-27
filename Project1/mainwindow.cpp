#include "mainwindow.h"
#include <QtGui>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Amelia Atkinson - Project 1");
    collector = new FlickrCollector(this);
    leftPanel = new QListWidget;
    menuBar = new QMenuBar();
    imageWidget = new QWidget;
    createMenus();
    createFlickr();
    this->setMenuBar(menuBar);

    QHBoxLayout *imgLayout = new QHBoxLayout;
    QLabel *mainImage = new QLabel;
    mainImage->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
    imgLayout->addWidget(mainImage);
    imageWidget->setLayout(imgLayout);

    QVBoxLayout *leftPanelLayout = new QVBoxLayout();
    leftPanelLayout->addWidget(leftPanel);
    leftPanelContainer = new QWidget();
    leftPanelContainer->setLayout(leftPanelLayout);

    //Set up the bottom PreviewArea
    PreviewArea *bottom = new PreviewArea(10, this);
    QVBoxLayout *anotherLayout = new QVBoxLayout();
    anotherLayout->addWidget(bottom);
    bottomContainer = new QWidget();
    bottomContainer->setLayout(anotherLayout);


    //Building the layout of the window
    QSplitter *splitter1 = new QSplitter(Qt::Horizontal, this);
    splitter1->addWidget(leftPanelContainer);
    splitter1->addWidget(imageWidget);
    splitter1->setOpaqueResize(true);
    splitter1->setChildrenCollapsible(true);
    QSplitter *splitter2 = new QSplitter(Qt::Vertical, this);
    splitter2->setChildrenCollapsible(true);
    splitter2->addWidget(splitter1);
    splitter2->addWidget(bottomContainer);
    setCentralWidget(splitter2);
 }

MainWindow::~MainWindow(){}

void MainWindow::quit()
{
  QApplication::quit();
}

void MainWindow::flickrCallback(void)
{
    urlList = collector->list(); //this goes in the callback function
    cout << "Flickr Callback Function" << endl;
    QListWidgetItem *collectionItem = new QListWidgetItem();
    collectionItem->setFlags(collectionItem->flags() | Qt::ItemIsEditable);
    collectionItem->setText(collector->collectionName());
    leftPanel->addItem(collectionItem);
}

void MainWindow::createFlickr(void)
{
    cout<< "Created Instance" << endl;
    FlickrCollector *collector = new FlickrCollector(this);
    connect(collector, SIGNAL(ready()), this, SLOT(flickrCallback()));
    collector->execute();
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar->addMenu("File");
    QAction *temp;
    temp = fileMenu->addAction("Exit");
    connect(temp,SIGNAL(triggered()), this, SLOT(quit()));
    temp->setEnabled(true);

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
    temp->setEnabled(true);
    connect(temp,SIGNAL(triggered()), this, SLOT(createFlickr()));
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
}


