#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flickrcollector.h"
#include "imagecollector.h"
#include "previewarea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void quit(void);
  void flickrCallback(void);
  void createFlickr();
  void createMenus();
  void processDownloadedPics(QPixmap);
  void resetMainImage(int);
  void replacingBottom();

private:
  FlickrCollector *collector;
  QStringList urlList;
  QListWidget *leftPanel;
  QMenuBar *menuBar;
  QWidget *imageWidget;
  QWidget *leftPanelContainer;
  QWidget *bottomContainer;
  PreviewArea *bottom;
  PreviewArea *tempBottom;
  QLabel *mainImage;
  ImageCollector *image;
  int numCollections;
  int photoCounter;

  vector<FlickrCollector> *allCollections;

signals:
  void replaceBottom();
};

#endif // MAINWINDOW_H
