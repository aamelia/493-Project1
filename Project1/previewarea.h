#ifndef PREVIEWAREA_H
#define PREVIEWAREA_H
#include <QtGui>
#include <QMainWindow>
class PreviewArea
{
    QList<QLabel> imgList;

public:
    PreviewArea(int size, QWidget *parent=0);
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
    void animationChanged(int location);
    void previewItemChanged(int location);
    void previewItemSelected(int location);

};

#endif // PREVIEWAREA_H
