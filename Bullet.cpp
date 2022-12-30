#include "config.h"
#include "Bullet.h"

Bullet::Bullet(){
	m_bulletboom.load(BULLETBOOM_PATH);
        m_bullet_up.load(BULLET_UP_PATH);
        m_bullet_down.load(BULLET_DOWN_PATH);
        m_bullet_left.load(BULLET_LEFT_PATH);
        m_bullet_right.load(BULLET_RIGHT_PATH);
        setDirection(1);
        setPosition(100,100);
        setSpeed(BULLET_SPEED);
        setFree(true);
        m_Rect.setHeight(m_bullet_up.height());
        m_Rect.setWidth(m_bullet_up.width());
//        m_Rect.moveTo(m_X,m_Y);
	setIsDead(false);
	m_displaybulletboom=true;
	bulletboomtime=0;
	setDamage(-100.0);
	whoCollision_i = -1;
	whoCollision_j = -1;
}

bool Bullet::compareWhoCollision(int i,int j){
	if(whoCollision_i == -1 && whoCollision_j == -1){
		whoCollision_i =i;
		whoCollision_j =j;
	}
	if(getDirection() == 2){
	        if(i<whoCollision_i){
		       whoCollision_i = i;
		       return true;
		}
		return false;
	}
	else if(getDirection()==3){
		if(i>whoCollision_i){
			whoCollision_i = i;
			return true;
		}
		return false;
	}
	else if(getDirection() == 1){
		if(j<whoCollision_j){
			whoCollision_j = j;
			return true;
		}
		return false;
	}
	else if(getDirection() == 4){
		if(j>whoCollision_j){
			whoCollision_j = j;
			return true;
		}
		return false;
	}

}
int Bullet::getWhoCollision(){
	return whoCollision_j;
}
void Bullet::updatePosition(){
        if(m_free){
                return;
        }
        else{
                if(getDirection() == 1){
                        setPosition(getX(),getY()-m_Speed);
                }else if(getDirection() == 2){
                        setPosition(getX()-m_Speed,getY());
                }else if(getDirection() == 3){
                        setPosition(getX()+m_Speed,getY());
                }else if(getDirection() == 4){
                        setPosition(getX(),getY()+m_Speed);
                }
                m_Rect.moveTo(m_X,m_Y);
        }
}
void Bullet::setDamage(float d){
	m_damage = d;
}
float Bullet::getDamage(){
	return m_damage;
}
void Bullet::updateDamage(float d){
	m_damage += d;
	if(m_damage >= 0){
		setDamage(0);
	}
}
void Bullet::setIsDead(bool d){
	m_isdead = d;
	if(m_isdead == true){
		setFree(true);
		whoCollision_i=-1;
		whoCollision_j=-1;
	}
}
bool Bullet::getIsDead(){
	return m_isdead;
}
QPixmap Bullet::getPix(){
	if(getDirection() == 1){
		return m_bullet_up;
	}
	if(getDirection() == 2){
		return m_bullet_left;		
	}
	if(getDirection() == 3){
		return m_bullet_right;
	}
	if(getDirection() == 4){
		return m_bullet_down;
	}
}
QRect Bullet::getRect(){
        return m_Rect;
}
void Bullet::setPosition(int x,int y){
        m_X = x;
        m_Y = y;
	m_Rect.moveTo(m_X,m_Y);
}
void Bullet::setDirection(int r){
        m_Direction = r;
	if(r==1){
		m_Rect.setHeight(BULLET_HIGHT);
		m_Rect.setWidth(BULLET_WIDTH);
	}
	else if(r==2){
		m_Rect.setHeight(BULLET_HIGHT);
		m_Rect.setWidth(BULLET_WIDTH);
	}
 	else if(r==3){
                m_Rect.setHeight(BULLET_HIGHT);
                m_Rect.setWidth(BULLET_WIDTH);
        }
 	else if(r==4){
                m_Rect.setHeight(BULLET_HIGHT);
                m_Rect.setWidth(BULLET_WIDTH);
        }

}
void Bullet::setSpeed(int s){
        m_Speed = s;
}
void Bullet::setFree(bool f){
        m_free = f;
}
int Bullet::getX(){
        return m_X;
}
int Bullet::getY(){
        return m_Y;
}
int Bullet::getDirection(){
        return m_Direction;
}
int Bullet::getSpeed(){
        return m_Speed;
}
bool Bullet::getFree(){
        return m_free;
}
QPixmap Bullet::getPix_BulletBoom(){
	return m_bulletboom;
}
void Bullet::setDisPlayBulletBoom(bool d){
	m_displaybulletboom = d;
}
bool Bullet::getDisPlayBulletBoom(){
	return m_displaybulletboom;
}
void Bullet::setBulletBoomTimer(int i){
	bulletboomtime=i;
}
void Bullet::BulletBoomTimer(){
        if(getIsDead() == true){
                bulletboomtime = bulletboomtime + 1;
                if(bulletboomtime >= 20){
                        bulletboomtime = 0;
                        setDisPlayBulletBoom(false);
              	}
        }
}

