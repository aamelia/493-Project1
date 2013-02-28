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
    collector = new FlickrCollector(this);
    connect(collector, SIGNAL(ready()), this, SLOT(flickrCallback()));

    //collectionItem = new QListWidgetItem();
    //collectionItem->setFlags(collectionItem->flags() | Qt::ItemIsEditable);
    //collectionItem->setText(collector->collectionName());

    createMenus();
    this->setMenuBar(menuBar);

    QHBoxLayout *imgLayout = new QHBoxLayout;
    mainImage = new QLabel;

    imgLayout->addWidget(mainImage);
    imageWidget->setLayout(imgLayout);

    QVBoxLayout *leftPanelLayout = new QVBoxLayout();
    leftPanelLayout->addWidget(leftPanel);
    leftPanelContainer = new QWidget();
    leftPanelContainer->setLayout(leftPanelLayout);

    //Set up the bottom PreviewArea
    bottom = new PreviewArea(10, this);
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
    splitter2->addWidget(splitter1);
    splitter2->addWidget(bottomContainer);
    setCentralWidget(splitter2);

    createFlickr();
    //createFlickr();
 }

MainWindow::~MainWindow(){}

void MainWindow::quit()
{
  QApplication::quit();
}

void MainWindow::flickrCallback(void)
{
    urlList = collector->list();
    if(urlList.size()==0)
    {
        createFlickr();
    }
    else
    {
        Collection *newCollection = new Collection();
        newCollection->collectionName = collector->collectionName();
        newCollection->collectionURLs = urlList;

        QListWidgetItem *collectionItem = new QListWidgetItem();
        collectionItem->setFlags(collectionItem->flags() | Qt::ItemIsEditable);
        collectionItem->setText(collector->collectionName());
        leftPanel->addItem(collectionItem);

        ImageCollector *image = new ImageCollector();
        connect(image, SIGNAL(pixmapAvailable(QPixmap)), this, SLOT(processDownloadedPics(QPixmap)));
        QString url;
        connect(bottom, SIGNAL(animationChanged(int)), this, SLOT(resetMainImage(int)));
        int size = urlList.size();
        for(int i=0; i<size; i++)
        {
            url = urlList.at(i);
            image->loadImage(url);
        }
    }
}
void MainWindow::resetMainImage(int location)
{
    mainImage->setPixmap(bottom->previewItemAt(location));
    //mainImage->setPixmap(QPixmap("/Users/MiaAtkinson/493Proj1/Project1/Chicago.jpg"));
}

void MainWindow::processDownloadedPics(QPixmap temp)
{
    bottom->setPreviewItemAt(0, temp);
}

void MainWindow::createFlickr(void)
{
    cout<< "Created Instance" << endl;
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


