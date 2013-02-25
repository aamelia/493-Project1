#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flickrcollector.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void quit(void);
};

#endif // MAINWINDOW_H
