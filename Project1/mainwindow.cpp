#include "mainwindow.h"
#include <QtGui>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Amelia Atkinson - Project 1");
    //Set up the menu bar
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

    /*
    Create an instance of FlickrCollector.

    3.  Call execute().  It will emit a ready() signal when it's finished
        downloading.

    4.  Get the list of urls as a QStringList by calling list().
    */
    FlickrCollector *collector = new FlickrCollector(this);

    connect(collector, SIGNAL(ready()), collector, SLOT(list()));
    collector->execute();
    //QStringList *tempList = collector->execute();
    //QStringList

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

    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *topHalf = new QHBoxLayout;
    QListWidget *leftPanel = new QListWidget;
    leftPanel->addItem(new QListWidgetItem("Item 1"));
    leftPanel->addItem(new QListWidgetItem("Item 2"));
    leftPanel->addItem(new QListWidgetItem("Item 3"));
    leftPanel->addItem(new QListWidgetItem("Item 4"));

    QLabel *mainImage = new QLabel;
    mainImage->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
    mainImage->setFixedSize(900,600);

    QUrl imageUrl("http://www.flickr.com/photos/mocoobaby/8505098497/");
    //m_pImgCtrl = new FileDownloader(imageUrl, this);

    //connect(m_pImgCtrl, SIGNAL(downloaded()), SLOT(loadImage()));

    //QPixmap buttonImage;
    //buttonImage.loadFromData(m_pImgCtrl->downloadedData());

    //This will later be a "PreviewArea"
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


