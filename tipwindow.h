#ifndef TIPWIDOW_H
#define TIPWIDOW_H

#include <QWidget>

class tipwindow : public QWidget
{
    Q_OBJECT
public:
    QPixmap loveforpass;
    QFont tip_font;//字体
    bool isclose;
    tipwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void setTip();
    int timerID;
    ~tipwindow();
};

#endif // TIPWIDOW_H
