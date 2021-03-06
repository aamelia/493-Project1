#ifndef PREVIEWAREA_H
#define PREVIEWAREA_H
#include <QtGui>
#include <QMainWindow>
#include <QWidget>


using namespace std;

class PreviewArea : public QScrollArea
{
    Q_OBJECT

private:
    QScrollArea *scrollArea;
    QWidget *container;
    QHBoxLayout *layout;
    QTimer *timer;
    int itemNum;
    int timerInterval;
    vector<QLabel *> myLabels;

public:    
    PreviewArea(int size=10, QWidget *parent=0);
    ~PreviewArea();
    QPixmap previewItemAt(int);
    void setPreviewItemAt(int, QPixmap);
    void setPreviewItemEnabledAt(int, bool);
    void deletePreviewItemAt(int);

public slots:
    void startAnimation(int timerInterval);
    void stopAnimation();
    void timerTick(void);

signals:
    void animationChanged(int);
    void previewItemChanged(int);
    void previewItemSelected(int);

};

#endif // PREVIEWAREA_H
