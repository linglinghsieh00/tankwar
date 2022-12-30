#include "EnemyTank.h"
#include "config.h"
EnemyTank::EnemyTank(){
        m_tank_up.load(ENEMYTANK_UP_PATH);
        m_tank_down.load(ENEMYTANK_DOWN_PATH);
        m_tank_left.load(ENEMYTANK_LEFT_PATH);
        m_tank_right.load(ENEMYTANK_RIGHT_PATH);
        m_strongertank_up.load(STRONGERENEMYTANK_UP_PATH);
        m_strongertank_down.load(STRONGERENEMYTANK_DOWN_PATH);
        m_strongertank_left.load(STRONGERENEMYTANK_LEFT_PATH);
        m_strongertank_right.load(STRONGERENEMYTANK_RIGHT_PATH);
        buff_1_Pix.load(BUFF1_PATH);
        buff_2_Pix.load(BUFF2_PATH);
        buff_3_Pix.load(BUFF3_PATH);
        setFree(true);
        setIsDead(false);
        setDirection(4);
        setFireReady(true);
        m_Rect.setWidth(m_tank_up.width());
        m_Rect.setHeight(m_tank_up.height());
        m_Rect.moveTo(m_X,m_Y);
        space.setWidth(20);
        space.setHeight(20);
        m_tank_wall_up_Rect.setWidth(m_tank_up.width());
        m_tank_wall_up_Rect.setHeight(m_tank_up.height());
        m_tank_wall_left_Rect.setWidth(m_tank_up.width());
        m_tank_wall_left_Rect.setHeight(m_tank_up.height());
        m_tank_wall_right_Rect.setWidth(m_tank_up.width());
        m_tank_wall_right_Rect.setHeight(m_tank_up.height());
        m_tank_wall_down_Rect.setWidth(m_tank_up.width());
        m_tank_wall_down_Rect.setHeight(m_tank_up.height());
        m_tank_bulletdetect_forward_Rect.setWidth(ENEMY_BULLETDETECT_FORWARD_WIDTH);
        m_tank_bulletdetect_forward_Rect.setHeight(ENEMY_BULLETDETECT_FORWARD_HEIGHT);
        m_tank_bulletdetect_left_Rect.setWidth(ENEMY_BULLETDETECT_SIDE_WIDTH);
        m_tank_bulletdetect_left_Rect.setHeight(ENEMY_BULLETDETECT_SIDE_HEIGHT);
        m_tank_bulletdetect_right_Rect.setWidth(ENEMY_BULLETDETECT_SIDE_WIDTH);
        m_tank_bulletdetect_right_Rect.setHeight(ENEMY_BULLETDETECT_SIDE_HEIGHT);
        m_tank_bulletdetect_down_Rect.setWidth(ENEMY_BULLETDETECT_FORWARD_WIDTH);
        m_tank_bulletdetect_down_Rect.setHeight(ENEMY_BULLETDETECT_FORWARD_HEIGHT);
        m_tank_attact_left_Rect.setWidth(ATTACT_SIDE_WIDTH);
        m_tank_attact_left_Rect.setHeight(ATTACT_SIDE_HEIGHT);
        m_tank_attact_right_Rect.setWidth(ATTACT_SIDE_WIDTH);
        m_tank_attact_right_Rect.setHeight(ATTACT_SIDE_HEIGHT);
        m_tank_attact_down_Rect.setWidth(ATTACT_UP_DOWN_WIDTH);
        m_tank_attact_down_Rect.setHeight(ATTACT_UP_DOWN_HEIGHT);
        test.setWidth(60);
        test.setHeight(500);
	buff_1_Rect.setWidth(70);
        buff_1_Rect.setHeight(70);
        buff_2_Rect.setWidth(70);
        buff_2_Rect.setHeight(70);
        buff_3_Rect.setWidth(70);
        buff_3_Rect.setHeight(70);
	buff_1_Rect.moveTo(-1000,-1000);
	buff_2_Rect.moveTo(-1000,-1000);
	buff_3_Rect.moveTo(-1000,-1000);
	tankboom_Pix.load(TANKBOOM_PATH);
}
int EnemyTank::getType(){
	return m_type;
}
bool EnemyTank::getIsOut(){
	return m_out;
}
void EnemyTank::shoot(int r,bool i){
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
                                break;
                        }
                }
        }
}
void EnemyTank::updateBlood(float b){
        m_blood += b;
        if(m_blood <= 0){
                setIsDead(true);
        }
}
void EnemyTank::FireRateTimer(){
        if(!getFireReady()){
                m_fireratecounter = m_fireratecounter +1;
                if(m_fireratecounter >= getFireRate()){
                        setFireReady(true);
                        m_fireratecounter =0;
                }
        }
}
void EnemyTank::updateFireNumber(){
        if(m_firenumber ==1){
                setFireRate(100);
                m_firenumber=0;
        }
        m_firenumber++;
}
void EnemyTank::updateTankPosition(){
        if(m_stop == false && m_isdead == false){
        if(getDirection() == 1){
                setPosition(getX(),getY()-ENEMY_TANKSPEED);
        }
        if(getDirection() == 2){
                setPosition(getX()-ENEMY_TANKSPEED,getY());
        }
        if(getDirection() == 3){
                setPosition(getX()+ENEMY_TANKSPEED,getY());
        }
        if(getDirection() == 4){
                setPosition(getX(),getY()+ENEMY_TANKSPEED);
        }
        }
}
void EnemyTank::setFireReady(bool i){
        fireReady = i;
}
bool EnemyTank::getFireReady(){
        return fireReady;
}
void EnemyTank::reload(){
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
void EnemyTank::setRecorder(int c){
        m_recorder = c;
}
void EnemyTank::setPosition(float x,float y){
        m_X = x;
        m_Y = y;
        m_Rect.moveTo(m_X,m_Y);

        m_tank_wall_up_Rect.moveTo(m_X,m_Y-ENEMY_TANKSPEED);
        m_tank_wall_left_Rect.moveTo(m_X-ENEMY_TANKSPEED,m_Y);
        m_tank_wall_right_Rect.moveTo(m_X+ENEMY_TANKSPEED,m_Y);
        m_tank_wall_down_Rect.moveTo(m_X,m_Y+ENEMY_TANKSPEED);

        m_tank_bulletdetect_forward_Rect.moveTo(m_X,m_Y-ENEMY_BULLETDETECT_FORWARD_HEIGHT); //待優化
        m_tank_bulletdetect_left_Rect.moveTo(m_X-ENEMY_BULLETDETECT_SIDE_WIDTH+60,m_Y);
        m_tank_bulletdetect_right_Rect.moveTo(m_X,m_Y);
        m_tank_bulletdetect_down_Rect.moveTo(m_X,m_Y+60);

        m_tank_attact_left_Rect.moveTo(m_X-ATTACT_SIDE_WIDTH,m_Y);
        m_tank_attact_right_Rect.moveTo(m_X+60,m_Y);
        m_tank_attact_down_Rect.moveTo(m_X,m_Y+60);
        test.moveTo(m_X,m_Y-ATTACT_UP_DOWN_HEIGHT);
}

void EnemyTank::setDirection(int r){
        m_direction = r;
}
void EnemyTank::setIsDead(bool i){
        m_isdead = i;
	DropBuff();
        if(m_isdead == true){
	QSound::play("./sounds/tankboom.wav");
        }	
}
void EnemyTank::setBlood(int b){
        m_blood = b;
}
void EnemyTank::setFree(bool f){
        m_free = f;
}
QPixmap EnemyTank::getPix(){
        if(m_type == 1){
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
        else{
        if(m_direction==1){
                return m_strongertank_up;
        }
        else if(m_direction==2){
                return m_strongertank_left;
        }
        else if(m_direction==3){
                return m_strongertank_right;
        }
        else if(m_direction==4){
                return m_strongertank_down;
        }
        }
}
QRect EnemyTank::getRec(){
        return m_Rect;
}
QRect EnemyTank::getRec_up(){
        return m_tank_wall_up_Rect;
}
QRect EnemyTank::getRec_left(){
        return m_tank_wall_left_Rect;
}
QRect EnemyTank::getRec_right(){
        return m_tank_wall_right_Rect;
}
QRect EnemyTank::getRec_down(){
        return m_tank_wall_down_Rect;
}
QRect EnemyTank::getRec_BulletDetector_Forward(){
        return m_tank_bulletdetect_forward_Rect;
}
QRect EnemyTank::getRec_BulletDetector_Left(){
        return m_tank_bulletdetect_left_Rect;
}
QRect EnemyTank::getRec_BulletDetector_Right(){
        return m_tank_bulletdetect_right_Rect;
}
QRect EnemyTank::getRec_BulletDetector_Down(){
        return m_tank_bulletdetect_down_Rect;
}
float EnemyTank::getX(){
        return m_X;
}
float EnemyTank::getY(){
        return m_Y;
}
bool EnemyTank::getFree(){
        return m_free;
}
int EnemyTank::getDirection(){
        return m_direction;
}
bool EnemyTank::getIsDead(){
        return m_isdead;
}
int EnemyTank::getBlood(){
        return m_blood;
}
void EnemyTank::BulletReloadTimer(){
        for(unsigned int i=0;i<BULLET_NUM;i++){
                if(m_bullets[i].getIsDead() == true){
                        bulletreloadtime[i] = bulletreloadtime[i] + 1;
                        if(bulletreloadtime[i] >= 600){
                                reload();
                        }
                }
        }
}
void EnemyTank::setFireRate(int i){
        m_firerate=i;
}
int EnemyTank::getFireRate(){
        return m_firerate;
}
void EnemyTank::setStop(bool s){
        m_stop = s;
}
bool EnemyTank::getStop(){
        return m_stop;
}
void EnemyTank::StopTimer(){
        if(m_stop == true){
                m_stoptime++;
        }
        if(m_stoptime >= 2000){
                m_stoptime = 0;
                setStop(false);
        }
}
void EnemyTank::SelfDestruct(){
        if(m_free == false && m_isdead == false){
                setIsDead(true);
        }
}
void EnemyTank::DropBuff(){
        if(m_type == 2){
        if(m_isdead == true){
                srand(time(NULL));
                m_buffchoose = rand() % 3;
                if(m_buffchoose == 0){
                        m_buff1 = true;
                        buff_1_Rect.moveTo(m_X,m_Y);
                }
                else if(m_buffchoose == 1){
                        m_buff2 = true;
                        buff_2_Rect.moveTo(m_X,m_Y);
                }
                else if(m_buffchoose == 2){
                        m_buff3 = true;
                        buff_3_Rect.moveTo(m_X,m_Y);
                }
        }
        }
}
void EnemyTank::setIsDrop(int i,bool j){
        if(i == 1){
                m_buff1 = j;
        }
        else if(i == 2){
                m_buff2 = j;
        }
        else if(i == 3){
                m_buff3 = j;
        }
}
int EnemyTank::getIsDrop(){
        if(m_buff1 == true){
                return 1;
        }
        else if(m_buff2 == true){
                return 2;
        }
        else if(m_buff3 == true){
                return 3;
        }
        else{
                return 4;
        }
}
void EnemyTank::setType(int t){
        m_type = t;
}
void EnemyTank::TankBoomTimer(){
	if(m_out == false && m_isdead == true){
		TankBoom();
		m_tankboomtime++;
	}
}
void EnemyTank::TankBoom(){
	if(m_isdead == true && m_out == false && m_tankboomtime <= 20){
		m_tankboom = true;
	}
	else{
		m_out = true;
		m_tankboomtime = 0;
		m_tankboom = false;
	}
}
QPixmap EnemyTank::getPix_TankBoom(){
	return tankboom_Pix;
}
bool EnemyTank::getTankBoom(){
	return m_tankboom;
}
void EnemyTank::setIsOut(bool o){
        m_out = o;
}
void EnemyTank::Cannon(){
        int a;
        srand(time(NULL));
        a = rand() % 100;
        if(a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 10){
                shoot(m_direction,fireReady);
        }
}


