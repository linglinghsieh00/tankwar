#include"mainwindow.h"
#include"config.h"


Mainwindow::Mainwindow(QWidget *parent) : QMainWindow(parent){  //Constructor
	m_tipback.load(TIPBACK);
        setMouseTracking(true);
	title=new QPushButton;
	title->setParent(this);
	title->setText("BATTLE\nCITY");
	title->move(50,100);
        title->setStyleSheet("QPushButton{font-family:'Book Antiqua';font-size:60px;color:white;}""QPushButton{background-color:black;}""QPushButton:hover{font-color:red;}");
        p1=new QPushButton;
        p1->setParent(this);
        p1->setText("1 player");
        p1->move(200,600);
        p1->setStyleSheet("QPushButton{font:20px;}");
        p1->resize(100,75);
        p2=new QPushButton;
        p2->setParent(this);
        p2->setText("2 players");
        p2->setStyleSheet("QPushButton{font:20px}");
        p2->move(300,600);
        p2->resize(100,75);
        p3=new QPushButton;
        p3->setParent(this);
        p3->setText("continue");
        p3->setStyleSheet("QPushButton{font:20px}");
        p3->move(400,600);
        p3->resize(100,75);
        p4=new QPushButton;
        p4->setParent(this);
        p4->setText("map_editor");
        p4->setStyleSheet("QPushButton{font:20px}");
        p4->move(500,600);
        p4->resize(100,75);
        a1=new QPushButton;
        a1->setParent(this);
        a1->setText("homepage");
        a1->setStyleSheet("QPushButton{font:20px}");
        a1->move(960,200);
        a1->resize(100,75);
        a2=new QPushButton;
        a2->setParent(this);
        a2->setText("start");
        a2->setStyleSheet("QPushButton{font:20px}");
        a2->move(960,300);
        a2->resize(100,75);
        a3=new QPushButton;
        a3->setParent(this);
        a3->setText("quit");
        a3->setStyleSheet("QPushButton{font:20px}");
        a3->move(960,400);
        a3->resize(100,75);
        b4=new QPushButton;
        b4->setParent(this);
        b4->setText("homepage");
        b4->setStyleSheet("QPushButton{font:20px}");
        b4->move(960,500);
        b4->resize(100,75);
        b1=new QPushButton;
        b1->setParent(this);
        b1->setText("Map1");
        b1->setStyleSheet("QPushButton{font:20px}");
        b1->move(960,200);
        b1->resize(100,75);
        b2=new QPushButton;
        b2->setParent(this);
        b2->setText("Map2");
        b2->setStyleSheet("QPushButton{font:20px}");
        b2->move(960,300);
        b2->resize(100,75);
        b3=new QPushButton;
        b3->setParent(this);
        b3->setText("Map3");
        b3->setStyleSheet("QPushButton{font:20px}");
        b3->move(960,400);
        b3->resize(100,75);
	connect(p1,&QPushButton::clicked,this,&Mainwindow::on_pushButton_clicked);
        connect(p2,&QPushButton::clicked,this,&Mainwindow::on_pushButton_2_clicked);
        connect(p3,&QPushButton::clicked,this,&Mainwindow::on_pushButton_continue_clicked);
        connect(p4,&QPushButton::clicked,this,&Mainwindow::on_pushButton_map_editor_clicked);
        connect(a1,&QPushButton::clicked,this,&Mainwindow::backHomePage);
        connect(a2,&QPushButton::clicked,this,&Mainwindow::pause);
        connect(a3,&QPushButton::clicked,this,&Mainwindow::quit);
        connect(b1,&QPushButton::clicked,this,&Mainwindow::map1Edit);
        connect(b2,&QPushButton::clicked,this,&Mainwindow::map2Edit);
        connect(b3,&QPushButton::clicked,this,&Mainwindow::map3Edit);
        connect(b4,&QPushButton::clicked,this,&Mainwindow::mapBackHome);
	startflag = false;
	mode = 0;
	stage = 0;
	resume = false;
	homePage();
}
void Mainwindow::homePage(){
	setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
        QPalette palette;
	mode = 0;
	stage =0;
        palette.setColor(QPalette::Background, Qt::black);
        setPalette(palette);	
	title->show();
	p1->show();
	p2->show();
	p3->show();
	p4->show();
	a1->hide();
	a2->hide();
	a3->hide();
	b1->hide();
	b2->hide();
	b3->hide();
	b4->hide();
	if(startflag==true){
		pause();
	}
}
void Mainwindow::initscene(){
        setFixedSize(WINDOW_WIDTH+400,WINDOW_HEIGHT);//设置窗口尺寸
        setWindowIcon(QIcon(GAME_ICON));//加载图标
        //m_Timer.setInterval(GAME_RATE);//帧率设置
	timerID =startTimer(UPDATE_RATE);

}
void Mainwindow::playGame(){
	algorithm.setGame(resume,mode,stage);
	map_x = algorithm.ourtank[0].getX()-300;
	map_y = algorithm.ourtank[0].getY()-300;
	algorithm.base.setIsDead(false);
	algorithm.base.setBase(748,1470);
	startflag=true;
	pause();

}
void Mainwindow::saveGame(){
	algorithm.GameSave();
	ModeSave();
	StageSave();
}
void Mainwindow::isDftOrScs(){
	if(algorithm.enemyKilled()==true){
		if(stage!=3){
			startflag = false;
			tip.show();
			stage++;
			algorithm.RemoveBuff();
			playGame();
		}
		else if(stage==3){
			passit.show();
			startflag = false;
			algorithm.RemoveBuff();
		}
	}
	else if(algorithm.ourtankKilled()==true || algorithm.baseKilled()==true){
			loseit.show();
			startflag = false;
	}

}

void Mainwindow::mouseMoveEvent(QMouseEvent *event){  //MouseMovement
        m_mouseX = event -> x();
        m_mouseY = event -> y();
}

void Mainwindow::mousePressEvent(QMouseEvent *event){  //MousePress
	if(mode == 1 || mode == 2){
	if(startflag == true){
	        if(event -> button() == Qt::LeftButton){//我方0號坦克射擊
			algorithm.ourtank[0].shoot(algorithm.ourtank[0].getDirection(),algorithm.ourtank[0].getFireReady());//getFireReady改掉
	        }
	}}
	if(mode == 4){
        	if(event -> button() == Qt::LeftButton){
        	        mapeditor.setBrick((int)(m_mouseX+map_x)/TERRAIN_UNIT,(int)(m_mouseY+map_y)/TERRAIN_UNIT);
        	}	
	}
}

void Mainwindow::keyPressEvent(QKeyEvent *event){  
	if(mode == 1||mode==2){
	if(startflag == true){
		if(event -> key()== Qt::Key_1){
                	algorithm.ourtank[0].setDirection(2);//我方0號坦克引擎發動
			algorithm.ourtank[0].setIsMove(true);
        	}	
        	else if(event -> key() == Qt::Key_3){
        	        algorithm.ourtank[0].setDirection(3);
        	        algorithm.ourtank[0].setIsMove(true);            
        	}
        	else if(event -> key() == Qt::Key_5){
        	        algorithm.ourtank[0].setDirection(1);
        	        algorithm.ourtank[0].setIsMove(true);               
        	}
        	else if(event -> key() == Qt::Key_2){
        	        algorithm.ourtank[0].setDirection(4);
        	        algorithm.ourtank[0].setIsMove(true);
		}
		else if(event -> key()== Qt::Key_A){
        	        algorithm.ourtank[1].setDirection(2);//我方1號坦克引擎發動
        	        algorithm.ourtank[1].setIsMove(true);   
        	}
        	else if(event -> key() == Qt::Key_D){
        	        algorithm.ourtank[1].setDirection(3);
        	        algorithm.ourtank[1].setIsMove(true);   
        	}
        	else if(event -> key() == Qt::Key_W){
        	        algorithm.ourtank[1].setDirection(1);
        	        algorithm.ourtank[1].setIsMove(true);   
        	}
        	else if(event -> key() == Qt::Key_S){
        	        algorithm.ourtank[1].setDirection(4);
        	        algorithm.ourtank[1].setIsMove(true);
        	}	
		else if(event ->key()== Qt::Key_J){//我方1號坦克射擊
			algorithm.ourtank[1].shoot(algorithm.ourtank[1].getDirection(),algorithm.ourtank[1].getFireReady());
		}
	}}
	if(mode == 4){
        	if(event -> key()== Qt::Key_A){
        	        map_x += -5;
        	}
        	else if(event -> key() == Qt::Key_D){
        	        map_x += 5;
        	}
        	else if(event -> key() == Qt::Key_W){
        	        map_y += -5;
        	}
        	else if(event -> key() == Qt::Key_S){
        	        map_y += 5;
        	}
        	else if(event -> key() == Qt::Key_0){
        	        mapeditor.setType(0);
        	}
        	else if(event -> key() == Qt::Key_1){
        	        mapeditor.setType(1);
        	}
        	else if(event -> key() == Qt::Key_2){
        	        mapeditor.setType(2);
        	}
        	else if(event -> key() == Qt::Key_3){
        	        mapeditor.setType(3);
        	}
        	else if(event -> key() == Qt::Key_4){
        	        mapeditor.setType(4);
        	}
	
	}

	
}

void Mainwindow::keyReleaseEvent(QKeyEvent *event){
	if(mode == 1 || mode == 2){
	if(startflag == true){
		if(event -> key() == Qt::Key_J){
			return;
		}
		else if(event -> key()== Qt::Key_1){//我方0號坦克引擎關閉
        	        algorithm.ourtank[0].setIsMove(false);
        	}
       		else if(event -> key() == Qt::Key_5){
        	        algorithm.ourtank[0].setIsMove(false);
        	}
        	else if(event -> key() == Qt::Key_2){
        	        algorithm.ourtank[0].setIsMove(false);
        	}
        	else if(event -> key() == Qt::Key_3){
        	        algorithm.ourtank[0].setIsMove(false);
        	}
        	else if(event -> key()== Qt::Key_A){//我方1號坦克引擎關閉
        	        algorithm.ourtank[1].setIsMove(false);
        	}
        	else if(event -> key() == Qt::Key_D){
        	        algorithm.ourtank[1].setIsMove(false);
        	}
        	else if(event -> key() == Qt::Key_W){
        	        algorithm.ourtank[1].setIsMove(false);
        	}
        	else if(event -> key() == Qt::Key_S){
        	        algorithm.ourtank[1].setIsMove(false);
        	}
	}}
	if(mode == 4){
	}

}
	
void Mainwindow::timerEvent(QTimerEvent *event){ //timer
	if(event ->timerId()== timerID && timerID != 0){
	        if(mode == 1 || mode == 2){
			if(startflag == true){
				algorithm.update();
				algorithm.collisionDetector();
				algorithm.Dodge();
				updateMapPosition();
				algorithm.EnemyShoot();
				algorithm.SpawnTime();
				algorithm.SpawnEnemy(stage);
	                	algorithm.Buff();
       		 		isDftOrScs();//判定是否通关
	                	for(unsigned int i = 0;i < ENEMY_NUM;i++){
	                	        algorithm.enemy[i].StopTimer();
				}
			}
		}        
		update();
	}
}
void Mainwindow::paintEvent(QPaintEvent *event){  //PaintEvent
        QPainter painter(this);
	if(mode == 1 || mode == 2){
		for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){//基底地圖
        	        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
				if(algorithm.terrain.brick[i][j].getType()==0 || algorithm.terrain.brick[i][j].getType()==4){
        	                	painter.drawPixmap(algorithm.terrain.brick[i][j].getX()-map_x,algorithm.terrain.brick[i][j].getY()-map_y,algorithm.terrain.brick[i][j].getPix());
				}
			}
        	}
	
		for(unsigned int i=0;i<BULLET_NUM;i++){//子彈&爆炸     (子彈印出待優化，使用新的RETURN FUNCTION判斷回傳圖片的X,Y)
			for(unsigned int h=0;h<ENEMY_NUM;h++){//enemy死亡時並不是閒置狀態!!!!!!!!!!!!!!!!
				if(algorithm.enemy[h].getFree()== true){
					continue;
				}
				if(!algorithm.enemy[h].m_bullets[i].getFree()){
					if(algorithm.enemy[h].m_bullets[i].getDirection() == 1 || algorithm.enemy[h].m_bullets[i].getDirection() == 4){
						painter.drawPixmap(algorithm.enemy[h].m_bullets[i].getX()-MIDDLE_X_OFFSET-map_x,algorithm.enemy[h].m_bullets[i].getY()-map_y,algorithm.enemy[h].m_bullets[i].getPix());
					}
					if(algorithm.enemy[h].m_bullets[i].getDirection() == 2 || algorithm.enemy[h].m_bullets[i].getDirection() == 3){
						painter.drawPixmap(algorithm.enemy[h].m_bullets[i].getX()-map_x,algorithm.enemy[h].m_bullets[i].getY()-MIDDLE_Y_OFFSET-map_y,algorithm.enemy[h].m_bullets[i].getPix());
					}
				}
				if(algorithm.enemy[h].m_bullets[i].getIsDead() == true){
	                                if(algorithm.enemy[h].m_bullets[i].getDisPlayBulletBoom() == true){
	                                        painter.drawPixmap(algorithm.enemy[h].m_bullets[i].getX()-map_x,algorithm.enemy[h].m_bullets[i].getY()-map_y,algorithm.enemy[h].m_bullets[i].getPix_BulletBoom());
	
	                                }
	                        }
			}
	       		for(unsigned int g=0;g<OURTANK_NUM;g++){
	                        if(!algorithm.ourtank[g].m_bullets[i].getFree()){
	                                if(algorithm.ourtank[g].m_bullets[i].getDirection() == 1 || algorithm.ourtank[g].m_bullets[i].getDirection() == 4){
	                                        painter.drawPixmap(algorithm.ourtank[g].m_bullets[i].getX()-MIDDLE_X_OFFSET-map_x,algorithm.ourtank[g].m_bullets[i].getY()-map_y,algorithm.ourtank[g].m_bullets[i].getPix());
	                                }
	                                if(algorithm.ourtank[g].m_bullets[i].getDirection() == 2 || algorithm.ourtank[g].m_bullets[i].getDirection() == 3){
	                                        painter.drawPixmap(algorithm.ourtank[g].m_bullets[i].getX()-map_x,algorithm.ourtank[g].m_bullets[i].getY()-MIDDLE_Y_OFFSET-map_y,algorithm.ourtank[g].m_bullets[i].getPix());
	                                }
	                        }
	                        if(algorithm.ourtank[g].m_bullets[i].getDisPlayBulletBoom() == true){
	                                if(algorithm.ourtank[g].m_bullets[i].getIsDead()==true){
	                                        painter.drawPixmap(algorithm.ourtank[g].m_bullets[i].getX()-map_x,algorithm.ourtank[g].m_bullets[i].getY()-map_y,algorithm.ourtank[g].m_bullets[i].getPix_BulletBoom());
	
	                                }
	                        }				
                	}
        	}

		for(unsigned int i = 0;i < ENEMY_NUM;i++){//坦克爆炸
			if(algorithm.enemy[i].getIsDead() == false){
				continue;
			}
			else if(algorithm.enemy[i].getIsDead() == true && algorithm.enemy[i].getTankBoom() == true){
				painter.drawPixmap(algorithm.enemy[i].getX()-map_x,algorithm.enemy[i].getY()-map_y,algorithm.enemy[i].getPix_TankBoom());
			}
		}
        	for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){//磚瓦地圖
        	        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
        	                if(algorithm.terrain.brick[i][j].getType()==1 || algorithm.terrain.brick[i][j].getType()==2){
        	                        painter.drawPixmap(algorithm.terrain.brick[i][j].getX()-map_x,algorithm.terrain.brick[i][j].getY()-map_y,algorithm.terrain.brick[i][j].getPix());
        	                }
        	        }
        	}
		if(algorithm.base.getIsDead() == false){//base
			painter.drawPixmap(algorithm.base.getX()-map_x,algorithm.base.getY()-map_y,algorithm.base.getPix());
		}	
	        for(unsigned int g=0;g<OURTANK_NUM;g++){//坦克
	                if(algorithm.ourtank[g].getIsDead() == false && algorithm.ourtank[g].getFree()== false){
	                        painter.drawPixmap(algorithm.ourtank[g].getX()-map_x,algorithm.ourtank[g].getY()-map_y,algorithm.ourtank[g].getPix());
	                }
	        }
	        for(unsigned int i=0;i<ENEMY_NUM;i++){//敵方坦克
	                if(algorithm.enemy[i].getFree()==false && !algorithm.enemy[i].getIsDead()){
	                        painter.drawPixmap(algorithm.enemy[i].getX()-map_x,algorithm.enemy[i].getY()-map_y,algorithm.enemy[i].getPix());
	                }
	        }
	
	
	
	        for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){//草地邊界
	                for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
	                        if(algorithm.terrain.brick[i][j].getType()==3 || algorithm.terrain.brick[i][j].getType()==5){
	                                painter.drawPixmap(algorithm.terrain.brick[i][j].getX()-map_x,algorithm.terrain.brick[i][j].getY()-map_y,algorithm.terrain.brick[i][j].getPix());
	                        }
	                }
	        }
	        for(unsigned int i = 0;i < ENEMY_NUM;i++){//BuffDisplay
	                if(algorithm.enemy[i].getIsDead() == false || algorithm.enemy[i].getFree() == true){
	                        continue;
	                }
	                if(algorithm.enemy[i].getIsDrop() == 1){
	                        painter.drawPixmap(algorithm.enemy[i].getX()-map_x,algorithm.enemy[i].getY()-map_y,algorithm.enemy[i].buff_1_Pix);
	                }
	                else if(algorithm.enemy[i].getIsDrop() == 2){
	                        painter.drawPixmap(algorithm.enemy[i].getX()-map_x,algorithm.enemy[i].getY()-map_y,algorithm.enemy[i].buff_2_Pix);
	                }
	                else if(algorithm.enemy[i].getIsDrop() == 3){
	                        painter.drawPixmap(algorithm.enemy[i].getX()-map_x,algorithm.enemy[i].getY()-map_y,algorithm.enemy[i].buff_3_Pix);
	                }
	        }

            	painter.drawPixmap(780,0,400,780,m_tipback);
            	//painter.drawPixmap(780,760,m_backmapobj.m_mylogo);
            	QFont ft;
        	ft.setPointSize(15);
        	painter.setFont(ft);
        	painter.setPen(Qt::black);
        	painter.drawText(800,50,tr("Enemies left:"));
        	painter.drawText(850,100,QString::number(algorithm.getEnemyLeft()));
        	painter.drawText(800,200,tr("Player 1"));
        	painter.drawText(850,245,tr("HP:"));
        	painter.setPen(Qt::red);
        	painter.drawText(880,290,QString::number((int)algorithm.ourtank[0].getBlood()));
        	painter.setPen(Qt::black);
        	painter.drawText(800,650,tr("stage"));
		painter.drawText(880,650,QString::number(stage));
        	if(mode==1){
        	        painter.drawText(800,500,tr("mode\t1"));
		}
        	if (mode == 2){
	       		painter.setPen(Qt::black);
			painter.drawText(800,330,tr("Player 2"));
        	    	painter.drawText(850,375,tr("HP:"));
        	    	painter.setPen(Qt::red);
        	    	painter.drawText(880,420,QString::number((int)algorithm.ourtank[1].getBlood()));
        	    	painter.setPen(Qt::black);
        	    	painter.drawText(800,500,tr("mode\t2"));
        	}
        	
	}
	if(mode == 4){	
        	for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
        	        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
        	                painter.drawPixmap(mapeditor.brick[i][j].getX()-map_x,mapeditor.brick[i][j].getY()-map_y,mapeditor.brick[i][j].getPix());
        	        }
        	}
		painter.drawPixmap(780,0,400,780,m_tipback);
	}

}
void Mainwindow::updateMapPosition(){
	if(algorithm.ourtank[0].getIsDead()==false){
	if(algorithm.ourtank[0].getX() > MAP_GAP && algorithm.ourtank[0].getX()<TERRAIN_WIDTH*TERRAIN_UNIT-MAP_GAP){
                if(algorithm.ourtank[0].getX() < map_x + MAP_GAP){
                        map_x = algorithm.ourtank[0].getX() - MAP_GAP;
                }
                else if(algorithm.ourtank[0].getX() > map_x + WINDOW_WIDTH - MAP_GAP){
                        map_x = algorithm.ourtank[0].getX() + MAP_GAP - WINDOW_WIDTH;
                }
        }
        if(algorithm.ourtank[0].getY() > MAP_GAP && algorithm.ourtank[0].getY()<TERRAIN_HEIGHT*TERRAIN_UNIT-MAP_GAP){
                if(algorithm.ourtank[0].getY() < map_y + MAP_GAP){
                        map_y = algorithm.ourtank[0].getY() - MAP_GAP;
                }
                else if(algorithm.ourtank[0].getY() > map_y + WINDOW_HEIGHT - MAP_GAP){
                        map_y = algorithm.ourtank[0].getY() + MAP_GAP - WINDOW_HEIGHT;
                }
        }}
	else{
		if(algorithm.ourtank[1].getFree()==false && algorithm.ourtank[1].getIsDead()==false){
	if(algorithm.ourtank[1].getX() > MAP_GAP && algorithm.ourtank[1].getX()<TERRAIN_WIDTH*TERRAIN_UNIT-MAP_GAP){
		if(algorithm.ourtank[1].getX() < map_x + MAP_GAP){
			map_x = algorithm.ourtank[1].getX() - MAP_GAP;
		}
		else if(algorithm.ourtank[1].getX() > map_x + WINDOW_WIDTH - MAP_GAP){
			map_x = algorithm.ourtank[1].getX() + MAP_GAP - WINDOW_WIDTH;
		}
	}
	if(algorithm.ourtank[1].getY() > MAP_GAP && algorithm.ourtank[1].getY()<TERRAIN_HEIGHT*TERRAIN_UNIT-MAP_GAP){
		if(algorithm.ourtank[1].getY() < map_y + MAP_GAP){
			map_y = algorithm.ourtank[1].getY() - MAP_GAP;
		}
		else if(algorithm.ourtank[1].getY() > map_y + WINDOW_HEIGHT - MAP_GAP){
			map_y = algorithm.ourtank[1].getY() + MAP_GAP - WINDOW_HEIGHT;
		}
	}}}
}
void Mainwindow::on_pushButton_continue_clicked(){
	p1->hide();
	p2->hide();
	p3->hide();
	p4->hide();
	title->hide();
	a1->show();
	a2->show();
	a3->show();
	resume = true;
        ifstream StageSet("StageSave.txt",ios::in);
        if(!StageSet){
                cerr << "Failed opening" << endl;
                exit(1);
        }
        StageSet >> stage;

        ifstream ModeSet("ModeSave.txt",ios::in);
        if(!ModeSet){
                cerr << "Failed opening" << endl;
                exit(1);
        }
        ModeSet >> mode;
	
	initscene();
	playGame();
}
void Mainwindow::on_pushButton_map_editor_clicked(){
	b1->show();
	b2->show();
	b3->show();
	b4->show();	
	p1->hide();
	p2->hide();
	p3->hide();
	p4->hide();
	title->hide();
	mode =4;
	initscene();
	mapeditor.setTerrain(1);
	map_x = 360;
	map_y = 360;
	map1Edit();
}
void Mainwindow::on_pushButton_clicked()
{
        a1->show();
	a2->show();
	a3->show();
	p1->hide();
        p2->hide();
	p3->hide();
	p4->hide();
        title->hide();
	stage=1;
        mode=1;
	resume =false;
        //nowMap=1;
        //tipfont.setFamily("Light");
        //tipfont.setPointSize(22);
        //tipfont.setBold(true);
        initscene();
        playGame();
	
}
void Mainwindow::on_pushButton_2_clicked()
{
	a1->show();
	a2->show();
	a3->show();
        p1->hide();
        p2->hide();
	p3->hide();
	p4->hide();
        title->hide();
	stage=1;
        mode=2;
	resume = false;
        //nowMap=1;
        //tipfont.setFamily("Light");
        //tipfont.setPointSize(22);
        //tipfont.setBold(true);
        initscene();
        playGame();//啟動遊戲
}
void Mainwindow::backHomePage(){
	saveGame();
	startflag=false;
	homePage();
}
void Mainwindow::pause(){
	saveGame();
	if(startflag==true){
		a2->setText("start");
		startflag=false;
	}else{
		a2->setText("pause");
		startflag=true;
	}
}
void Mainwindow::quit(){
	saveGame();
	exit(1);
}
void Mainwindow::map1Edit(){
	mapeditor.saveMap(stage);
	stage =1;
	mapeditor.setTerrain(stage);
}
void Mainwindow::map2Edit(){
	mapeditor.saveMap(stage);
	stage =2;
	mapeditor.setTerrain(stage);
}
void Mainwindow::map3Edit(){
	mapeditor.saveMap(stage);
	stage =3;
	mapeditor.setTerrain(stage);
}
void Mainwindow::mapBackHome(){
	mapeditor.saveMap(stage);
	homePage();
}
void Mainwindow::ModeSave(){
	ofstream ModeSave("ModeSave.txt",ios::out);
	if(!ModeSave){
		cerr << "Failed opening" << endl;
		exit(1);
	}
	ModeSave << mode;
}
void Mainwindow::StageSave(){
	ofstream StageSave("StageSave.txt",ios::out);
        if(!StageSave){
                cerr << "Failed opening" << endl;
                exit(1);
        }
        StageSave << stage;
}
