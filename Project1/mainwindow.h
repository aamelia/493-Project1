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
  void setMainImage(QLabel*);
  void resetMainImage(int);

private:
  FlickrCollector *collector;
  QStringList urlList;
  QListWidget *leftPanel;
  QMenuBar *menuBar;
  QWidget *imageWidget;
  QWidget *leftPanelContainer;
  QWidget *bottomContainer;
  PreviewArea *bottom;
  QLabel *mainImage;

  struct Collection {
  QString collectionName;
  QStringList collectionUrls;
  };
};

#endif // MAINWINDOW_H
