
#include "OurTank.h"
#include "config.h"
OurTank::OurTank(){
        m_tank_up.load(OURTANK_PATH);
        m_tank_down.load(OURTANK_DOWN_PATH);
        m_tank_left.load(OURTANK_LEFT_PATH);
        m_tank_right.load(OURTANK_RIGHT_PATH);
        setPosition(700,700);
	setIsDead(false);
	//setBlood(1000000);
        setDirection(1);
        setFireReady(true);
        m_Rect.setWidth(m_tank_up.width());
        m_Rect.setHeight(m_tank_up.height());
        m_Rect.moveTo(m_X,m_Y);
	setIsMove(false);
	setFree(false);
}
void OurTank::shoot(int r,bool i){
        if(i == true && getIsDead() == false){
        	for(unsigned int i = 0;i< BULLET_NUM;i++){
                	if(m_bullets[i].getFree() && !m_bullets[i].getIsDead()){
				updateFireNumber();
                        	m_bullets[i].setFree(false);
                        	m_bullets[i].setPosition(getX()+MIDDLE_X_OFFSET,getY()+MIDDLE_Y_OFFSET);
				m_bullets[i].setDirection(r);
				m_bullets[i].setDamage(-100.0);
				setFireReady(false);
				m_bullets[i].setDisPlayBulletBoom(true);
				m_bullets[i].setBulletBoomTimer(0);
				QSound::play("./sounds/bulletshoot.wav");
              			break;
                	}
        	}
	}
}
void OurTank::updateTankPosition(){
	if(m_ismove == true){
        	if(getDirection() == 1){
                	setPosition(getX(),getY()-OURTANK_TANKSPEED);
        	}
		else if(getDirection() == 2){
        	        setPosition(getX()-OURTANK_TANKSPEED,getY());
        	}
		else if(getDirection() == 3){
        	        setPosition(getX()+OURTANK_TANKSPEED,getY());
        	}
		else if(getDirection() == 4){
        	        setPosition(getX(),getY()+OURTANK_TANKSPEED);
        	}
	}
}
void OurTank::setFree(bool f){
	m_isfree = f;
}
bool OurTank::getFree(){
	return m_isfree;
}
void OurTank::setIsMove(bool m){
	m_ismove = m;
}
bool OurTank::getIsMove(){
	return m_ismove;
}
void OurTank::FireRateTimer(){
	if(!getFireReady()){
		m_fireratecounter = m_fireratecounter +1;
		if(m_fireratecounter >= getFireRate()){
			setFireReady(true);
			m_fireratecounter =0;
		}
	}
}
void OurTank::updateBlood(float b){
	m_blood += b;
	if(m_blood <= 0.0){
		setIsDead(true);
	}
}
void OurTank::updateFireNumber(){
	if(m_firenumber == m_continuous){
		setFireRate(50);
		m_firenumber=0;
	}
	else if(m_firenumber == 1){
		setFireRate(2);
	}
	m_firenumber++;
}
void OurTank::setContinuous(int c){
        m_continuous = c;
}
void OurTank::setFireReady(bool i){
	fireReady = i;
}
bool OurTank::getFireReady(){
	return fireReady;
}
void OurTank::reload(){
	for(unsigned int i = 0;i<BULLET_NUM;i++){
		if(m_bullets[i].getIsDead() /*&& m_bullets[i].getFree()*/){
			if(bulletreloadtime[i] >= 600){
				bulletreloadtime[i]=0;
				//m_bullets[i].setFree(true);
				m_bullets[i].setIsDead(false);
			}
		}
	}
}	
void OurTank::setRecorder(int c){
        m_recorder = c;
}
void OurTank::setPosition(float x,float y){
        m_X = x;
        m_Y = y;
        m_Rect.moveTo(m_X,m_Y);
}
void OurTank::setDirection(int r){
        m_direction = r;
}
void OurTank::setIsDead(bool i){
	m_isdead = i;
	if(m_isdead == true){
	QSound::play("./sounds/tankboom.wav");
	}
}
void OurTank::setBlood(float b){
	m_blood = b;
}
QPixmap OurTank::getPix(){
	if(m_direction==1){
		return m_tank_up;
	}
	else if(m_direction==2){
		return m_tank_left;
	}
	else if(m_direction==3){
		return m_tank_right;
	}
	else if(m_direction==4){
		return m_tank_down;
	}
}
QRect OurTank::getRec(){
        return m_Rect;
}
float OurTank::getX(){
        return m_X;
}
float OurTank::getY(){
        return m_Y;
}
int OurTank::getDirection(){
        return m_direction;
}
bool OurTank::getIsDead(){
	return m_isdead;
}
float OurTank::getBlood(){
	return m_blood;
}
void OurTank::BulletReloadTimer(){
        for(unsigned int i=0;i<BULLET_NUM;i++){
                if(m_bullets[i].getIsDead() == true){
                        bulletreloadtime[i] = bulletreloadtime[i] + 1;
			if(bulletreloadtime[i] >= 600){
				reload();
			}
                }
        }
}
void OurTank::setFireRate(int i){
	m_firerate=i;
}
int OurTank::getFireRate(){
	return m_firerate;
}
void OurTank::setBuffCounter(){
        m_buffcounter++;
}
int OurTank::getBuffCounter(){
        return m_buffcounter;
}
void OurTank::setEnforceBullet(bool e){
	m_enforcebullet = e;
}
bool OurTank::getEnforceBullet(){
	return m_enforcebullet;
}
void OurTank::RemoveBuff(){
	m_buffcounter = 0;
}
void OurTank::setBuff(int b){
	m_buffcounter = b;
}
