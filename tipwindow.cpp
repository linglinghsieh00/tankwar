#include "tipwindow.h"
#include <QLabel>
#include "config.h"
#include <QPainter>
#include <QFont>
#include <QTimer>
#include <QKeyEvent>
tipwindow::tipwindow(QWidget *parent)
    : QWidget(parent)
{
    isclose=false;
    tip_font.setFamily("MS Shell Dlg 2");
    tip_font.setPointSize(22);
    tip_font.setBold(true);
    setFixedSize(400,600);
    setStyleSheet("background-color: rgb(255,255,255)");//背景顏色
    loveforpass.load(LOVE_PASS_PATH);
    update();
    setTip();
    timerID = startTimer(2000);
}

void tipwindow::timerEvent(QTimerEvent *event)
{
	if(event ->timerId()== timerID && timerID != 0){
        	QWidget::close();
	}
}

void tipwindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
     painter.drawPixmap(0,0,loveforpass);
}

void tipwindow::setTip()
{

    QLabel *rule=new QLabel(this);
    rule->setText("恭喜通关");
    rule->setFont(tip_font);
    rule->setAlignment(Qt::AlignTop);
    rule->setGeometry(0,400,300,200);
}

tipwindow::~tipwindow()
{

}



