#ifndef PREVIEWAREA_H
#define PREVIEWAREA_H
#include <QtGui>
#include <QMainWindow>
class PreviewArea
{
public:
    PreviewArea(int size, QWidget *parent=0);
    ~PreviewArea();
    QPixmap PreviewArea::previewItemAt(int);
    PreviewArea::setPreviewItemAt(int, QPixmap);
    PreviewArea::setPreviewItemEnabledAt(int, bool);
    PreviewArea::deletePreviewItemAt(int);

public slots:
    void startAnimation(int timerInterval);
    void stopAnimation();
    void timerTick(void);

//public signals:
    void animationChanged(int location);
    void previewItemChanged(int location);
    void previewItemSelected(int location);

};

#endif // PREVIEWAREA_H
