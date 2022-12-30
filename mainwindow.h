#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include <unistd.h>
#include <config.h>
#include "Algorithm.h"
#include "tipwindow.h"
#include "you_pass_the_game.h"
#include "you_lose.h"
#include "map_editor.h"

using namespace std;
class Mainwindow : public QMainWindow{
        Q_OBJECT
        public:
                Mainwindow(QWidget *parent = 0);
	protected:
                void mouseMoveEvent(QMouseEvent *event);
                void mousePressEvent(QMouseEvent *event);
                void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
                void paintEvent(QPaintEvent *event);
                void timerEvent(QTimerEvent *event);
		void updateMapPosition();
		void initscene();
		void on_pushButton_clicked();
		void on_pushButton_2_clicked();
		void on_pushButton_continue_clicked();
		void on_pushButton_map_editor_clicked();
		void backHomePage();
		void quit();
		void pause();
		void homePage();
		void isDftOrScs();
		void playGame();
		void saveGame();
		void map1Edit();
		void map2Edit();
		void map3Edit();
		void mapBackHome();
		void StageSave();
		void ModeSave();
        private:
		bool startflag;
		bool resume;
		int mode;
		int stage;
		int players_num;
		float map_x;
		float map_y;
                float m_mouseX =0;
                float m_mouseY =0;
                int timerID;
	       	QPushButton *p1;
		QPushButton *p2;
		QPushButton *p3;
		QPushButton *p4;
		QPushButton *a1;
		QPushButton *a2;
		QPushButton *a3;
		QPushButton *b1;
		QPushButton *b2;
		QPushButton *b3;
		QPushButton *b4;
		QPushButton *title;	
                QString key;
		Algorithm algorithm;
		QPixmap m_tipback;
		tipwindow tip;
		you_pass_the_game passit;
		you_lose loseit;
		MapEditor mapeditor;
};
#endif

