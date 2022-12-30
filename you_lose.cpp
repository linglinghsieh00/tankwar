#include "you_lose.h"
#include<QLabel>
#include<QPainter>
#include"config.h"
#include <QKeyEvent>
you_lose::you_lose(QWidget *parent)
    : QWidget(parent)
{
    isclose=false;
    tip_font.setFamily("MS Shell Dlg 2");
    tip_font.setPointSize(22);
    tip_font.setBold(true);
    setFixedSize(600,400);
    setStyleSheet("background-color: rgb(255,255,255)");
    loveforpass.load(LOSETHEGAME);
    update();
    setTip();
}
void you_lose::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_K)
    {
	    QWidget::close(); 
    }
}


void you_lose::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,loveforpass);

}
void you_lose::setTip()
{

    QLabel *rule=new QLabel(this);
    rule->setText("你输了T_T\n\n按K结束游戏");
    rule->setFont(tip_font);
    rule->setAlignment(Qt::AlignTop);
    rule->setGeometry(400,120,300,400);
}

you_lose::~you_lose()
{

}
