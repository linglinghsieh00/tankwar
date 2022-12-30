#include"Algorithm.h"
#include"config.h"
Algorithm::Algorithm(){
}
int Algorithm::getEnemyLeft(){
	int counter = 0;
	for(unsigned int i=0;i<ENEMY_NUM;i++){
		if(enemy[i].getIsDead()==false){
			counter++;
		}
	}
	return counter;
}
bool Algorithm::enemyKilled(){

        for(unsigned int i=0;i<ENEMY_NUM;i++){
                if(enemy[i].getIsDead()==false || enemy[i].getFree()==true){
                        return false;
                }
        }
        return true;
}
bool Algorithm::ourtankKilled(){
	for(unsigned int i=0;i<OURTANK_NUM;i++){
		if(ourtank[i].getIsDead()==false && ourtank[i].getFree()==false){
			return false;
		}
	}
	return true;
			
}
bool Algorithm::baseKilled(){
	if(base.getIsDead()==true){
		return true;
	}
	else{
		return false;
	}
}
void Algorithm::collisionDetector(){
        bullet_brick();
        ourBullet_enemy();
        ourBullet_enemyBullet();
        enemyBullet_ourtank();
        tank_brick();
        tank_tank();
	enemy_base();
}
void Algorithm::enemy_base(){
	for(unsigned int e=0;e<ENEMY_NUM;e++){
		if(enemy[e].getIsDead()==true || enemy[e].getFree()==true){
			continue;
		}
		if(enemy[e].m_Rect.intersects(base.m_Rect)){
			base.setIsDead(true);
		}
		for(unsigned int i=0;i<BULLET_NUM;i++){
			if(enemy[e].m_bullets[i].getFree()==true){
				continue;
			}
			if(enemy[e].m_bullets[i].m_Rect.intersects(base.m_Rect)){
				base.setIsDead(true);
			}
		}
	}
}
void Algorithm::RemoveBuff(){
	for(unsigned int i =0;i < OURTANK_NUM;i++){
		ourtank[i].RemoveBuff();
	}
}
void Algorithm::setOurTank(bool resume,int mode){
        float x,y,blood;
	int counter=0,number,buff;
        bool isfree,isdead;
        if(resume == false){
                if(mode == 1){
                        ifstream inOurTank1("OurTank1.txt",ios::in);
                        if(!inOurTank1){
                                cerr << "Failed opening" << endl;
                                exit(1);
                        }
                        while(inOurTank1 >> number >> x >> y >> blood >> buff >> isfree >> isdead){
                                ourtank[counter].setPosition(x,y);
                                ourtank[counter].setBlood(blood);
				ourtank[counter].setBuff(buff);
                                ourtank[counter].setFree(isfree);
                                ourtank[counter].setIsDead(isdead);
                                counter++;
                        }
			LoadBuff();
                        counter = 0;
                }
                else if(mode == 2){
                        ifstream inOurTank2("OurTank2.txt",ios::in);
                        if(!inOurTank2){
                                cerr << "Failed opening" << endl;
                                exit(1);
                        }
                        while(inOurTank2 >> number >> x >> y >> blood >> buff >> isfree >> isdead){
                                ourtank[counter].setPosition(x,y);
                                ourtank[counter].setBlood(blood);
				ourtank[counter].setBuff(buff);
                                ourtank[counter].setFree(isfree);
                                ourtank[counter].setIsDead(isdead);
                                counter++;
                        }
			LoadBuff();
                        counter = 0;
                }
        }
        else if(resume == true){
                ifstream inOurTank3("OurTank3.txt",ios::in);
                if(!inOurTank3){
                        cerr << "Failed opening" << endl;
                        exit(1);
                }
                while(inOurTank3 >> number >> x >> y >> blood >> buff >> isfree >> isdead){
                        ourtank[counter].setPosition(x,y);
                        ourtank[counter].setBlood(blood);
			ourtank[counter].setBuff(buff);
                        ourtank[counter].setFree(isfree);
                        ourtank[counter].setIsDead(isdead);
                        counter++;
		}
		LoadBuff();
		CleanBuffRect();
                counter = 0;
        }
}
void Algorithm::setEnemyTank(bool resume,int stage){
        string name,HEADLINE;
        float x,y,blood;
	int type,counter=0;
        bool isfree,isdead,isout;
        if(resume == false){
        if(stage == 1){
                ifstream stage1_enemytank("Enemytank1.txt",ios::in);
                if(!stage1_enemytank){
                        cerr << "Failed opening" << endl;
                        exit(1);
                }
                while(stage1_enemytank >> x >> y >> type >> blood >> isfree >> isdead >> isout){
                        enemy[counter].setPosition(x,y);
                        enemy[counter].setType(type);
                        enemy[counter].setBlood(blood);
                        enemy[counter].setFree(isfree);
                        enemy[counter].setIsDead(isdead);
                        enemy[counter].setIsOut(isout);
                        counter++;
                }
                counter = 0;
        }
        else if(stage == 2){
                ifstream stage2_enemytank("Enemytank2.txt",ios::in);
                if(!stage2_enemytank){
                        cerr << "Failed opening" << endl;
                        exit(1);
                }
                while(stage2_enemytank >> x >> y >> type >> blood >> isfree >> isdead >> isout){
                        enemy[counter].setPosition(x,y);
                        enemy[counter].setType(type);
                        enemy[counter].setBlood(blood);
                        enemy[counter].setFree(isfree);
                        enemy[counter].setIsDead(isdead);
                        enemy[counter].setIsOut(isout);
                        counter++;
                }
                counter = 0;
        }
        else if(stage == 3){
                ifstream stage3_enemytank("Enemytank3.txt",ios::in);
                if(!stage3_enemytank){
                        cerr << "Failed opening" << endl;
                        exit(1);
                }
                while(stage3_enemytank >> x >> y >> type >> blood >> isfree >> isdead >> isout){
                        enemy[counter].setPosition(x,y);
                        enemy[counter].setType(type);
                        enemy[counter].setBlood(blood);
                        enemy[counter].setFree(isfree);
                        enemy[counter].setIsDead(isdead);
                        enemy[counter].setIsOut(isout);
                        counter++;
                }
                counter = 0;
        }
        }
        else if(resume == true){
                ifstream stage4_enemytank("Enemytank4.txt",ios::in);
                if(!stage4_enemytank){
                        cerr << "Failed opening" << endl;
                        exit(1);
                }
                while(stage4_enemytank >> x >> y >> type >> blood >> isfree >> isdead >> isout){
                        enemy[counter].setPosition(x,y);
                        enemy[counter].setType(type);
                        enemy[counter].setBlood(blood);
                        enemy[counter].setFree(isfree);
                        enemy[counter].setIsDead(isdead);
                        enemy[counter].setIsOut(isout);
                        counter++;
                }
                counter = 0;
        }
}
void Algorithm::setGame(bool resume,int mode,int stage){
        setEnemyTank(resume,stage);
        terrain.setTerrain(resume,stage);
        setOurTank(resume,mode);
}
void Algorithm::SaveTerrain(){
	int type;
	ofstream SaveTerrain("Map4.txt",ios::out);
	if(!SaveTerrain){
		cerr << "Failed opening" << endl;
		exit(1);
	}
       	for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
            for (unsigned int j = 0; j < TERRAIN_WIDTH; j++) {
                type = terrain.brick[i][j].getType();
                SaveTerrain << type << " ";
            }
			SaveTerrain << endl;			
        }
}
void Algorithm::SaveEnemyTank(){
	float x,y,blood;
	int type;
	int isfree,isdead,isout;
	ofstream SaveEnemyTank("EnemyTank4.txt",ios::out);
	if(!SaveEnemyTank){
		cerr << "Failed opening" << endl;
		exit(1);
	}
	for(unsigned int i = 0;i < ENEMY_NUM;i++){
		x = enemy[i].getX();
		y = enemy[i].getY();
		blood = enemy[i].getBlood();
		type = enemy[i].getType();
		isfree = enemy[i].getFree();
		isdead = enemy[i].getIsDead();
		isout = enemy[i].getIsOut();
		SaveEnemyTank << x << "\t" << y << "\t" << type << "\t" << blood << "\t" << isfree << "\t" << isdead << "\t" << isout << endl;
	}
}
void Algorithm::SaveOurTank(){
	float x,y,blood;
	int number,buff;
	int isfree,isdead;
	ofstream SaveOurTank("OurTank3.txt",ios::out);
	if(!SaveOurTank){
		cerr << "Failed opening" << endl;
		exit(1);
	}
	for(unsigned int i = 0;i < OURTANK_NUM;i++){
		number = i;
		x = ourtank[i].getX();
		y = ourtank[i].getY();
		blood = ourtank[i].getBlood();
		buff = ourtank[i].getBuffCounter();
		isfree = ourtank[i].getFree();
		isdead = ourtank[i].getIsDead();
		SaveOurTank << number << "\t" << x << "\t" << y << "\t" << blood << "\t" << buff << "\t" << isfree << "\t" << isdead << endl;
	}
}
void Algorithm::GameSave(){
	SaveTerrain();
	SaveEnemyTank();
	SaveOurTank();
}
void Algorithm::update(){
	updateBulletDamage();
	for(unsigned int j=0;j<OURTANK_NUM;j++){
        	if(ourtank[j].getFree()==true){
                	continue;
                }
                ourtank[j].updateTankPosition();
		ourtank[j].BulletReloadTimer();
		ourtank[j].FireRateTimer();
		for(unsigned int i=0;i<BULLET_NUM;i++){
                        if(!ourtank[j].m_bullets[i].getFree()){
                                ourtank[j].m_bullets[i].updatePosition();
				continue;
                        }
			if(ourtank[j].m_bullets[i].getIsDead()){
				ourtank[j].m_bullets[i].BulletBoomTimer();
			}
                }
	}
	for(unsigned int k=0;k<ENEMY_NUM;k++){
                if(enemy[k].getFree() == true){
                         continue;
		}
		enemy[k].updateTankPosition();
		enemy[k].BulletReloadTimer();
		enemy[k].FireRateTimer();
		enemy[k].StopTimer();
		enemy[k].TankBoomTimer();
		for(unsigned int i=0;i<BULLET_NUM;i++){
                        if(!enemy[k].m_bullets[i].getFree()){
                                enemy[k].m_bullets[i].updatePosition();
				continue;
			}
			if(enemy[k].m_bullets[i].getIsDead()){
				enemy[k].m_bullets[i].BulletBoomTimer();
                        }
                }
        }
}
void Algorithm::bullet_brick(){
        for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
                for(unsigned int z=0;z<TERRAIN_WIDTH;z++){
                        if(terrain.brick[i][z].getIsDead() == true || terrain.brick[i][z].getType()==0){
                                continue;
                        }
                        if(terrain.brick[i][z].getType() == 4 || terrain.brick[i][z].getType()== 3){
                                continue;
                        }
                        for(unsigned int p=0;p<OURTANK_NUM;p++){
                                for(unsigned int j=0;j<BULLET_NUM;j++){
                                        if(ourtank[p].m_bullets[j].getFree()==true){
                                                continue;
                                        }
                                                if(terrain.brick[i][z].m_Rect.intersects(ourtank[p].m_bullets[j].m_Rect)){
                                                        ourtank[p].m_bullets[j].setIsDead(true);
							QSound::play("./sounds/bulletboom.wav");
                                                        if(terrain.brick[i][z].getType()==1){
                                                                terrain.brick[i][z].setIsDead(true);
                                                                continue;
                                                        }
                                                        if(terrain.brick[i][z].getType()==2 && ourtank[p].getEnforceBullet() == true){  //強化子彈可擊穿鐵牆
								terrain.brick[i][z].setIsDead(true);
                                                                continue;
                                                        }
							else if(terrain.brick[i][z].getType() == 2){
								continue;
							}
                                                }
                                }
                        }
                        for(unsigned int k=0;k<ENEMY_NUM;k++){
                                if(enemy[k].getFree()==true){
                                        continue;
                                }
                                for(unsigned int l=0;l<BULLET_NUM;l++){
                                        if(enemy[k].m_bullets[l].getFree()==true){
                                                continue;
                                        }
                                        if(terrain.brick[i][z].m_Rect.intersects(enemy[k].m_bullets[l].m_Rect)){
                                                enemy[k].m_bullets[l].setIsDead(true);
                                                if(terrain.brick[i][z].getType()==1){
                                                        terrain.brick[i][z].setIsDead(true);
                                                        continue;
                                                }
                                                if(terrain.brick[i][z].getType()==2){
                                                        continue;
                                                }

                                        }
                                }
                        }
                }
        }
}
void Algorithm::updateBulletDamage(){
	for(unsigned int i=0;i<BULLET_NUM;i++){
		for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
			for(unsigned int k=0;k<TERRAIN_HEIGHT;k++){
				for(unsigned int o=0;o<OURTANK_NUM;o++){
					if(ourtank[o].getFree()==true){
						continue;
					}
					if(ourtank[o].m_bullets[i].getFree()==true){
						continue;
					}
					if(ourtank[o].m_bullets[i].m_Rect.intersects(terrain.brick[j][k].m_Rect)){
						if(ourtank[o].m_bullets[i].compareWhoCollision(k,j)){
							ourtank[o].m_bullets[i].updateDamage(2.5);
							if(terrain.brick[j][k].getType()==3){
								ourtank[o].m_bullets[i].updateDamage(5.0);
							}
							if(terrain.brick[j][k].getType()==4){
								ourtank[o].m_bullets[i].updateDamage(-5.0);
							}
						}
					}
				}
		                for(unsigned int e=0;e<ENEMY_NUM;e++){
                                        if(enemy[e].getFree()==true || enemy[e].getIsDead()==true){
                                                continue;
                                        }
					if(enemy[e].m_bullets[i].getFree()==true){
						continue;
					}
                                        if(enemy[e].m_bullets[i].m_Rect.intersects(terrain.brick[j][k].m_Rect)){
                                                if(enemy[e].m_bullets[i].compareWhoCollision(k,j)){
                                                        enemy[e].m_bullets[i].updateDamage(2.5);
                                                        if(terrain.brick[j][k].getType()==3){
                                                                enemy[e].m_bullets[i].updateDamage(5.0);
                                                        }
                                                        if(terrain.brick[j][k].getType()==4){
                                                                enemy[e].m_bullets[i].updateDamage(-5.0);
                                                        }
                                                }
                                        }
                                }
			
			}
		}
	}
}
void Algorithm::ourBullet_enemy(){
        for(unsigned int l=0;l<OURTANK_NUM;l++){
                for(unsigned int i=0;i<ENEMY_NUM;i++){
                        if(enemy[i].getIsDead() == true){
                                continue;
                        }
                        for(unsigned int j=0;j<BULLET_NUM;j++){
                                if(ourtank[l].m_bullets[j].getFree()==true){
                                        continue;
                                }
                                if(enemy[i].m_Rect.intersects(ourtank[l].m_bullets[j].m_Rect)){
                                        ourtank[l].m_bullets[j].setIsDead(true);
					QSound::play("./sounds/bulletboom.wav");
                                        enemy[i].updateBlood(ourtank[l].m_bullets[j].getDamage());
                                }
                        }
                }
        }
}
void Algorithm::enemyBullet_ourtank(){
        for(unsigned int h=0;h<OURTANK_NUM;h++){
                if(ourtank[h].getIsDead() == false){
                        for(unsigned int i=0;i<ENEMY_NUM;i++){
                                for(unsigned int j=0;j<BULLET_NUM;j++){
                                        if(enemy[i].m_bullets[j].getFree()==true){
                                                continue;
                                        }
                                        if(ourtank[h].m_Rect.intersects(enemy[i].m_bullets[j].m_Rect)){
                                                ourtank[h].updateBlood(enemy[i].m_bullets[j].getDamage());
                                                enemy[i].m_bullets[j].setIsDead(true);
                                        }
                                }
                        }
                }
        }
}
void Algorithm::ourBullet_enemyBullet(){
        for(unsigned int n=0;n<OURTANK_NUM;n++){
                if(ourtank[n].getIsDead() == true){
                        continue;
                }
                for(unsigned int i=0;i<ENEMY_NUM;i++){
                        if(enemy[i].getFree() == true){
                                continue;
                        }
                        for(unsigned int k=0;k<BULLET_NUM;k++){
                                for(unsigned int j=0;j<BULLET_NUM;j++){
					if(ourtank[n].m_bullets[k].getFree() == false){
						if(enemy[i].m_bullets[j].getFree() == false && ourtank[n].m_bullets[k].m_Rect.intersects(enemy[i].m_bullets[j].m_Rect)){
							ourtank[n].m_bullets[k].setIsDead(true);
							QSound::play("./sounds/bulletboom.wav");
							enemy[i].m_bullets[j].setIsDead(true);
							continue;
						}
						for(unsigned int q=0;q<OURTANK_NUM;q++){
							if(ourtank[q].getIsDead()==true ||ourtank[q].getFree()==true){
								continue;
							}
							if(ourtank[n].m_bullets[k].m_Rect.intersects(ourtank[q].m_Rect) && n != q){
								ourtank[n].m_bullets[k].setIsDead(true);
								QSound::play("./sounds/bulletboom.wav");
								continue;
							}
						}
					}
					if(enemy[i].m_bullets[k].getFree() == false){
						
                                                for(unsigned int s=0;s<ENEMY_NUM;s++){
                                                        if(enemy[i].m_bullets[k].m_Rect.intersects(enemy[s].m_Rect) && i != s){
                                                                enemy[i].m_bullets[k].setIsDead(true);
                                                                continue;
                                                        }
                                                }

                                        }
                                }
                        }
                }
        }
}

void Algorithm::tank_brick(){
         for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
		 for(unsigned int z=0;z<TERRAIN_WIDTH;z++){
			if(terrain.brick[i][z].getIsDead() == true || terrain.brick[i][z].getType()==0){
                	        continue;
                	}
                	if(terrain.brick[i][z].getBlock() == false){
                	        continue;
                	}
                	for(unsigned int v=0;v<OURTANK_NUM;v++){
                	        if(ourtank[v].getIsDead()==true){
                	                continue;
                	        }
                	        if(ourtank[v].m_Rect.intersects(terrain.brick[i][z].m_Rect)){
                	                if(ourtank[v].getDirection()==2){
                	                        ourtank[v].setPosition(ourtank[v].getX()+OURTANK_TANKSPEED,ourtank[v].getY());
                	                }
                	                else if(ourtank[v].getDirection()==3){
                	                        ourtank[v].setPosition(ourtank[v].getX()-OURTANK_TANKSPEED,ourtank[v].getY());
                	                }
                	                else if(ourtank[v].getDirection()==1){
                	                        ourtank[v].setPosition(ourtank[v].getX(),ourtank[v].getY()+OURTANK_TANKSPEED);
                	                }
                	                else if(ourtank[v].getDirection()==4){
                	                        ourtank[v].setPosition(ourtank[v].getX(),ourtank[v].getY()-OURTANK_TANKSPEED);
                	                }
                	        }
                	}
                	for(unsigned int j=0;j<ENEMY_NUM;j++){
                	        if(enemy[j].getFree() == true){
                	                continue;
                	        }
                        if(enemy[j].m_Rect.intersects(terrain.brick[i][z].m_Rect)){
                                if(enemy[j].getDirection()==2){
                                        enemy[j].setPosition(enemy[j].getX()+5,enemy[j].getY());
                                        choose = 1 + rand() % 4;
                                        if(choose == 1){
                                                enemy[j].setDirection(1);
                                        }
                                        else if(choose == 3){
                                                enemy[j].setDirection(3);
                                        }
                                        else if(choose == 4){
                                                enemy[j].setDirection(4);
                                        }
                                }
                                else if(enemy[j].getDirection()==3){
                                        enemy[j].setPosition(enemy[j].getX()-5,enemy[j].getY());
                                        choose = 1 + rand() % 4;
                                        if(choose == 1){
                                                enemy[j].setDirection(1);
                                        }
                                        else if(choose == 2){
                                                enemy[j].setDirection(2);
                                        }
                                        else if(choose == 4){
                                                enemy[j].setDirection(4);
                                        }
                                }
                                else if(enemy[j].getDirection()==1){
                                        enemy[j].setPosition(enemy[j].getX(),enemy[j].getY()+5);
                                        choose = 1 + rand() % 4;
                                        if(choose == 2){
                                                enemy[j].setDirection(2);
                                        }
                                        else if(choose == 3){
                                                enemy[j].setDirection(3);
                                        }
                                        else if(choose == 4){
                                                enemy[j].setDirection(4);
                                        }
                                }
				else if(enemy[j].getDirection()==4){
                                        enemy[j].setPosition(enemy[j].getX(),enemy[j].getY()-5);
                                        choose = 1 + rand() % 4;
                                        if(choose == 2){
                                                enemy[j].setDirection(2);
                                        }
                                        else if(choose == 3){
                                                enemy[j].setDirection(3);
                                        }
                                        else if(choose == 1){
                                                enemy[j].setDirection(1);
                                        }
                                }

                	}
		}

         }
	 }
}
void Algorithm::tank_tank(){
        for(unsigned int a=0;a<OURTANK_NUM;a++){
                if(ourtank[a].getIsDead() == false && ourtank[a].getFree()==false){
                       for(unsigned int j=0;j<ENEMY_NUM;j++){
                               if(enemy[j].getFree()==true || enemy[j].getIsDead()==true){
                                       continue;
                               }
                                if(enemy[j].m_Rect.intersects(ourtank[a].m_Rect)){
                                        if(enemy[j].getDirection()==2){
                                                enemy[j].setPosition(enemy[j].getX()+ENEMY_TANKSPEED,enemy[j].getY());
                                        }
                                        else if(enemy[j].getDirection()==3){
                                                enemy[j].setPosition(enemy[j].getX()-ENEMY_TANKSPEED,enemy[j].getY());
                                        }
                                        else if(enemy[j].getDirection()==1){
                                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY()+ENEMY_TANKSPEED);
                                        }
                                        else if(enemy[j].getDirection()==4){
                                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY()-ENEMY_TANKSPEED);
                                        }
                                        if(ourtank[a].getIsMove()==true){
					if(ourtank[a].getDirection() == 5-enemy[j].getDirection()){
                        	                if(ourtank[a].getDirection()==2){
                                                	ourtank[a].setPosition(ourtank[a].getX()+OURTANK_TANKSPEED,ourtank[a].getY());
                                                }
                                                else if(ourtank[a].getDirection()==3){
                                                        ourtank[a].setPosition(ourtank[a].getX()-OURTANK_TANKSPEED,ourtank[a].getY());
                                                }
                                                else if(ourtank[a].getDirection()==1){
                                                        ourtank[a].setPosition(ourtank[a].getX(),ourtank[a].getY()+OURTANK_TANKSPEED);
                                                }
                                                else if(ourtank[a].getDirection()==4){
                                                        ourtank[a].setPosition(ourtank[a].getX(),ourtank[a].getY()-OURTANK_TANKSPEED);
                                                }
                                         }}
                                 }
                        }
                       for(unsigned int k=0;k<OURTANK_NUM;k++){
                               if(k==a){continue;}
                               if(ourtank[k].getIsDead() == true || ourtank[k].getFree()==true){continue;}
                               if(ourtank[a].m_Rect.intersects(ourtank[k].m_Rect)){
                                               if(ourtank[a].getIsMove()==true){			
                                       			if(ourtank[a].getDirection()==2){
                                        		        ourtank[a].setPosition(ourtank[a].getX()+OURTANK_TANKSPEED,ourtank[a].getY());
                                       			}
                                      			else if(ourtank[a].getDirection()==3){
                                       				ourtank[a].setPosition(ourtank[a].getX()-OURTANK_TANKSPEED,ourtank[a].getY());
                                      			}
                                      			else if(ourtank[a].getDirection()==1){
                                       				ourtank[a].setPosition(ourtank[a].getX(),ourtank[a].getY()+OURTANK_TANKSPEED);
                                      			}
                                       			else if(ourtank[a].getDirection()==4){
                                        			ourtank[a].setPosition(ourtank[a].getX(),ourtank[a].getY()-OURTANK_TANKSPEED);
                                        		}
						}
						if(ourtank[k].getIsMove()==true){
                                     			if(ourtank[k].getDirection()==2){
                                                		ourtank[k].setPosition(ourtank[k].getX()+OURTANK_TANKSPEED,ourtank[k].getY());
                                        		}
                                        		else if(ourtank[k].getDirection()==3){
                                        		        ourtank[k].setPosition(ourtank[k].getX()-OURTANK_TANKSPEED,ourtank[k].getY());
                                        		}
                                        		else if(ourtank[k].getDirection()==1){
                                        		        ourtank[k].setPosition(ourtank[k].getX(),ourtank[k].getY()+OURTANK_TANKSPEED);
                                        		}
                                        		else if(ourtank[k].getDirection()==4){
                                        		        ourtank[k].setPosition(ourtank[k].getX(),ourtank[k].getY()-OURTANK_TANKSPEED);
                                        		}
						}
				}
			}


                }
        }
	/*for(unsigned int i = 0;i < ENEMY_NUM;i++){//////舊版本
		for(unsigned int j = 0;j < ENEMY_NUM;j++){
			if(i == j){
				continue;
			}
			if(enemy[i].getFree() == true || enemy[j].getFree() == true){
				continue;
			}
			if(enemy[i].getIsDead() == true || enemy[j].getIsDead() == true){
				continue;
			}
			if(enemy[i].getDirection() == 1 && enemy[i].m_tank_wall_up_Rect.intersects(enemy[j].m_tank_wall_down_Rect)){
				enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
				enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());
                                choose = 1 + rand() % 4;
                                if(choose == 2){
                                        enemy[i].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[i].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[i].setDirection(4);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
                        }
                        if(enemy[i].getDirection() == 2 && enemy[i].m_tank_wall_left_Rect.intersects(enemy[j].m_tank_wall_right_Rect)){
                                enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
				enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());
                                choose = 1 + rand() % 4;
                                if(choose == 2){
                                        enemy[i].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[i].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[i].setDirection(4);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
			}
                        if(enemy[i].getDirection() == 3 && enemy[i].m_tank_wall_right_Rect.intersects(enemy[j].m_tank_wall_left_Rect)){
                                enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());
                                choose = 1 + rand() % 4;
                                if(choose == 2){
                                        enemy[i].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[i].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[i].setDirection(4);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
			}
                        if(enemy[i].getDirection() == 4 && enemy[i].m_tank_wall_down_Rect.intersects(enemy[j].m_tank_wall_up_Rect)){
                                enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());				
                                choose = 1 + rand() % 4;
                                if(choose == 2){
                                        enemy[i].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[i].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[i].setDirection(4);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
			}
		}*/
        for(unsigned int i = 0;i < ENEMY_NUM;i++){
                for(unsigned int j = 0;j < ENEMY_NUM;j++){
                        if(i == j){
                                continue;
                        }
                        if(enemy[i].getFree() == true || enemy[j].getFree() == true){
                                continue;
                        }
                        if(enemy[i].getIsDead() == true || enemy[j].getIsDead() == true){
                                continue;
                        }
                        if(enemy[i].getDirection() == 1 && enemy[i].m_tank_wall_up_Rect.intersects(enemy[j].m_tank_wall_down_Rect)){
                                enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());
                                choose = 1 + rand() % 4;
                                if(choose == 2 || choose == 1){
                                        enemy[i].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[i].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[i].setDirection(4);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 2){
                                        enemy[j].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
                        }
                        if(enemy[i].getDirection() == 2 && enemy[i].m_tank_wall_left_Rect.intersects(enemy[j].m_tank_wall_right_Rect)){
                                enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[i].setDirection(1);
                                }
                                else if(choose == 3 || choose == 2){
                                        enemy[i].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[i].setDirection(4);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 2){
                                        enemy[j].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
                        }
                        if(enemy[i].getDirection() == 3 && enemy[i].m_tank_wall_right_Rect.intersects(enemy[j].m_tank_wall_left_Rect)){
                                enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());
                                choose = 1 + rand() % 4;
                                if(choose == 2){
                                        enemy[i].setDirection(2);
                                }
                                else if(choose == 1){
                                        enemy[i].setDirection(1);
                                }
                                else if(choose == 4 || choose == 3){
                                        enemy[i].setDirection(4);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 2){
                                        enemy[j].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
                        }
                        if(enemy[i].getDirection() == 4 && enemy[i].m_tank_wall_down_Rect.intersects(enemy[j].m_tank_wall_up_Rect)){
                                enemy[i].setPosition(enemy[i].getX(),enemy[i].getY());
                                enemy[j].setPosition(enemy[j].getX(),enemy[j].getY());
                                choose = 1 + rand() % 4;
                                if(choose == 2){
                                        enemy[i].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[i].setDirection(3);
                                }
                                else if(choose == 1){
                                        enemy[i].setDirection(1);
                                }
                                choose = 1 + rand() % 4;
                                if(choose == 1){
                                        enemy[j].setDirection(1);
                                }
                                else if(choose == 2){
                                        enemy[j].setDirection(2);
                                }
                                else if(choose == 3){
                                        enemy[j].setDirection(3);
                                }
                                else if(choose == 4){
                                        enemy[j].setDirection(4);
                                }
                        }
		}
	}
}
void Algorithm::Dodge(){
        for(unsigned int i=0;i<ENEMY_NUM;i++){
                for(unsigned int j=0;j<BULLET_NUM;j++){
                        for(unsigned int k=0;k<TERRAIN_HEIGHT;k++){
				for(unsigned int l = 0;l < TERRAIN_WIDTH;l++){
					for(unsigned int m = 0;m < OURTANK_NUM;m++){
						if(ourtank[m].getIsDead() == true){
							continue;
						}
						if(terrain.brick[k][l].getIsDead() == true){
							continue;
						}
						if(ourtank[m].m_bullets[j].getFree() == true){
							continue;
						}
                                else if(ourtank[m].m_bullets[j].getFree() == false){
                                        if(enemy[i].getDirection() == 1){
                                                if(enemy[i].getRec_BulletDetector_Left().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_up().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(2);
                                                        }
                                                        else if(enemy[i].getRec_down().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(2);
                                                        }
                                                        else {
                                                                if(ourtank[m].m_bullets[j].getY()+15 < enemy[i].getY()+30){
                                                                        enemy[i].setDirection(4);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getY()+15 > enemy[i].getY()+30){
                                                                        enemy[i].setDirection(1);
                                                                }

                                                        }
                                                }
                                                if(enemy[i].getRec_BulletDetector_Right().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_up().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(3);
                                                        }
                                                        else if(enemy[i].getRec_down().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(3);
                                                        }
                                                        else {
                                                                if(ourtank[m].m_bullets[j].getY()+15 < enemy[i].getY()+30){
                                                                        enemy[i].setDirection(4);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getY()+15 > enemy[i].getY()+30){
                                                                        enemy[i].setDirection(1);
                                                                }
                                                        }
                                                }
                                        }
                                        if(enemy[i].getDirection() == 2){
                                                if(enemy[i].getRec_BulletDetector_Forward().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_left().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(1);
                                                        }
                                                        else if(enemy[i].getRec_right().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(1);
                                                        }
                                                        else {
                                                                if(ourtank[m].m_bullets[j].getX()+15 < enemy[i].getX()+30){
                                                                        enemy[i].setDirection(3);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getX()+15 > enemy[i].getX()+30){
                                                                        enemy[i].setDirection(2);
                                                                }
                                                        }
                                                }
                                                if(enemy[i].getRec_BulletDetector_Down().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_left().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(4);
                                                        }
                                                        else if(enemy[i].getRec_right().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(4);
                                                        }
                                                        else {
                                                                if(ourtank[m].m_bullets[j].getX()+30 < enemy[i].getX()){
                                                                        enemy[i].setDirection(3);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getX()+30 > enemy[i].getX()){
                                                                        enemy[i].setDirection(2);
                                                                }
                                                        }
                                                }
                                        }
                                        if(enemy[i].getDirection() == 3){
                                                if(enemy[i].getRec_BulletDetector_Forward().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_right().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(2);
                                                        }
                                                        else if(enemy[i].getRec_left().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(3);
                                                        }
                                                        else{
                                                                if(ourtank[m].m_bullets[j].getX()-15 < enemy[i].getX()+30){
                                                                        enemy[i].setDirection(3);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getX()-15 > enemy[i].getX()+30){
                                                                        enemy[i].setDirection(2);
                                                                }
                                                        }
                                                }
                                                if(enemy[i].getRec_BulletDetector_Down().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_right().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(2);
                                                        }
                                                        else if(enemy[i].getRec_left().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(3);
                                                        }
                                                        else{
                                                                if(ourtank[m].m_bullets[j].getX()-15 < enemy[i].getX()+30){
                                                                        enemy[i].setDirection(3);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getX()-15 > enemy[i].getX()+30){
                                                                        enemy[i].setDirection(2);
                                                                }
                                                        }
                                                }
                                        }
                                        if(enemy[i].getDirection() == 4){
                                                if(enemy[i].getRec_BulletDetector_Left().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_up().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(2);
							}
                                                        else if(enemy[i].getRec_down().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(2);
                                                        }
                                                        else{
                                                                if(ourtank[m].m_bullets[j].getY()+15 < enemy[i].getY()+30){
                                                                        enemy[i].setDirection(4);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getY()+15 > enemy[i].getY()+30){
                                                                        enemy[i].setDirection(1);
                                                                }
                                                        }
                                                }
                                                if(enemy[i].getRec_BulletDetector_Right().intersects(ourtank[m].m_bullets[j].m_Rect)){
                                                        if(enemy[i].getRec_up().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(3);
                                                        }
                                                        else if(enemy[i].getRec_down().intersects(terrain.brick[k][l].m_Rect) && terrain.brick[k][l].getIsDead() == false && terrain.brick[k][l].getBlock() == true){
                                                                enemy[i].setDirection(3);
                                                        }
                                                        else {
                                                                if(ourtank[m].m_bullets[j].getY()+15 < enemy[i].getY()+30){
                                                                        enemy[i].setDirection(4);
                                                                }
                                                                if(ourtank[m].m_bullets[j].getY()+15 > enemy[i].getY()+30){
                                                                        enemy[i].setDirection(1);
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }

                }
        }
}
}
}
void Algorithm::EnemyShoot(){
        for(unsigned int i = 0;i < ENEMY_NUM;i++){
		for(unsigned int j = 0;j < OURTANK_NUM;j++){
                if(enemy[i].getFree() == true || enemy[i].getIsDead() == true){
                        continue;
                }
                if(enemy[i].getDirection() == 1){
                        if(enemy[i].test.intersects(ourtank[j].m_Rect)){
                                enemy[i].shoot(1,enemy[i].getFireReady());
                        }
                }
                else if(enemy[i].getDirection() == 2){
                        if(enemy[i].m_tank_attact_left_Rect.intersects(ourtank[j].m_Rect)){
                                enemy[i].shoot(2,enemy[i].getFireReady());
                        }
                }
                else if(enemy[i].getDirection() == 3){
                        if(enemy[i].m_tank_attact_right_Rect.intersects(ourtank[j].m_Rect)){
                                enemy[i].shoot(3,enemy[i].getFireReady());
                        }
                }
                else if(enemy[i].getDirection() == 4){
                        if(enemy[i].m_tank_attact_down_Rect.intersects(ourtank[j].m_Rect)){
                                enemy[i].shoot(4,enemy[i].getFireReady());
                        }
                }
		}
        }
}
void Algorithm::SpawnTime(){
	m_spawn_time = m_spawn_time + 1;
}
void Algorithm::SpawnEnemy(int stage){
        srand(time(NULL));
        for(unsigned int i = 0;i < ENEMY_NUM;i++){
                if(enemy[i].getFree() == false){
                        m_born_number++;
                }
                if(enemy[i].getFree() == false && enemy[i].getIsDead() == false){
                        m_enemy_number++;
                }
        }
	if(stage == 1){
        	if(m_enemy_number < 3 || m_spawn_time >= SPAWN_TIME){
                        for(unsigned int i = 0;i < ENEMY_NUM;i++){
                                if(enemy[i].getFree() == true && enemy[i].getIsDead() == false){
                                        spawn_point = rand() % 4;
                                        if(spawn_point == 0){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(30.0,30.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 1){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(1470.0,30.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 2){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(30.0,1470.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 3){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(1470.0,1470.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                }
                        }      
        	}
	}
	if(stage == 2){
		if(m_enemy_number < 5 || m_spawn_time >= SPAWN_TIME){
                        for(unsigned int i = 0;i < ENEMY_NUM;i++){
                                if(enemy[i].getFree() == true && enemy[i].getIsDead() == false){
                                        spawn_point = rand() % 4;
                                        if(spawn_point == 0){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(30.0,30.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 1){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(1470.0,30.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 2){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(30.0,1470.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 3){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(1470.0,1470.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                }
                        }
                }
	}
	if(stage == 3){
		if(m_enemy_number < 10 || m_spawn_time >= SPAWN_TIME){
                        for(unsigned int i = 0;i < ENEMY_NUM;i++){
                                if(enemy[i].getFree() == true && enemy[i].getIsDead() == false){
                                        spawn_point = rand() % 4;
                                        if(spawn_point == 0){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(30.0,30.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 1){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(1470.0,30.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 2){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(30.0,1470.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                        else if(spawn_point == 3){
                                                enemy[i].setFree(false);
                                                enemy[i].setPosition(1470.0,1470.0);
                                                m_spawn_time = 0;
                                                break;
                                        }
                                }
                        }
                }		
	}
        m_born_number = 0;
        m_enemy_number = 0;
}
void Algorithm::Buff(){
        for(unsigned int i = 0;i < OURTANK_NUM;i++){
                for(unsigned int j = 0;j < ENEMY_NUM;j++){
                        if(!ourtank[i].m_Rect.intersects(enemy[j].buff_1_Rect) && !ourtank[i].m_Rect.intersects(enemy[j].buff_2_Rect) && !ourtank[i].m_Rect.intersects(enemy[j].buff_3_Rect)){
                                continue;
                        }
                        if(ourtank[i].m_Rect.intersects(enemy[j].buff_1_Rect)){
                                enemy[j].setIsDrop(1,false);
                                enemy[j].m_Rect.moveTo(-1000,-1000);
                                enemy[j].buff_1_Rect.moveTo(-1000,-1000);
				QSound::play("./sounds/buff.wav");				
                                for(unsigned int k = 0;k < ENEMY_NUM;k++){
                                        enemy[k].setStop(true);
                                }
                        }
                        else if(ourtank[i].m_Rect.intersects(enemy[j].buff_2_Rect)){
                                enemy[j].setIsDrop(2,false);
                                enemy[j].m_Rect.moveTo(-1000,-1000);
                                enemy[j].buff_2_Rect.moveTo(-1000,-1000);
                                ourtank[i].setBuffCounter();
				QSound::play("./sounds/buff.wav");				
                                if(ourtank[i].getBuffCounter() == 1){
                                        for(unsigned int n = 0;n < BULLET_NUM;n++){
                                                ourtank[i].m_bullets[n].setSpeed(2*BULLET_SPEED);
                                        }
                                }
                                else if(ourtank[i].getBuffCounter() == 2){
                                        ourtank[i].setContinuous(2);
                                }
                                else if(ourtank[i].getBuffCounter() == 3){
                                        ourtank[i].setEnforceBullet(true);
				}
			}
                        else if(ourtank[i].m_Rect.intersects(enemy[j].buff_3_Rect)){
                                enemy[j].setIsDrop(3,false);
                                enemy[j].m_Rect.moveTo(-1000,-1000);
                                enemy[j].buff_3_Rect.moveTo(-1000,-1000);
                                for(unsigned int o = 0;o < ENEMY_NUM;o++){
                                        if(enemy[o].getFree() == false && enemy[o].getIsDead() == false){
                                                enemy[o].SelfDestruct();
                                	}
                        	}
                	}
		}
        }
}
void Algorithm::LoadBuff(){
	for(unsigned int i = 0;i < OURTANK_NUM;i++){
		for(unsigned int j = 0; j < BULLET_NUM;j++){
			if(ourtank[i].getBuffCounter() == 0){
				ourtank[i].RemoveBuff();
				ourtank[i].m_bullets[j].setSpeed(BULLET_SPEED);
				ourtank[i].setContinuous(1);
				ourtank[i].setEnforceBullet(false);
			}
			if(ourtank[i].getBuffCounter() == 1){
				ourtank[i].m_bullets[j].setSpeed(2*BULLET_SPEED);
			}
			else if(ourtank[i].getBuffCounter() == 2){
                                ourtank[i].m_bullets[j].setSpeed(2*BULLET_SPEED);
				ourtank[i].setContinuous(2);
			}
			else if(ourtank[i].getBuffCounter() >= 3){
                                ourtank[i].m_bullets[j].setSpeed(2*BULLET_SPEED);
                                ourtank[i].setContinuous(2);
				ourtank[i].setEnforceBullet(true);
                        }
		}
	}
}
void Algorithm::CleanBuffRect(){
	for(unsigned int i = 0;i < ENEMY_NUM;i++){
		for(unsigned int j = 1;j <= 3;j++){
			enemy[i].setIsDrop(j,false);
		}
		enemy[i].buff_1_Rect.moveTo(-1000,-1000);
		enemy[i].buff_2_Rect.moveTo(-1000,-1000);
		enemy[i].buff_3_Rect.moveTo(-1000,-1000);
	}
}
