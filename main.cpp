#include <QApplication>
#include <QResource>
#include "config.h"
#include "mainwindow.h"

int main(int argc,char *argv[]){
        QApplication a(argc,argv);
        //QResource::registerResource(GAME_RES_PATH); 註冊外部的二進制資源文件

        Mainwindow w;
        w.show();
        return a.exec();
}

