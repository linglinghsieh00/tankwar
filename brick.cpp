#include "Brick.h"
Brick::Brick(){
        m_pixmap_wall.load(WALL_PATH);
	m_pixmap_iron.load(IRON_PATH);
	m_pixmap_grass.load(GRASS_PATH);
	m_pixmap_river.load(RIVER_PATH);
	m_pixmap_black.load(BLACK_PATH);
        m_Rect.setHeight(m_pixmap_wall.height());
        m_Rect.setWidth(m_pixmap_wall.width());
	setBrick(0,500,500);
        setIsDead(false);
}
void Brick::setBrick(int type,int x,int y){
	m_type = type;
	if(type == 0){//black
		setShield(false);
		setBlock(false);
		setDestructible(false);
		setIsDead(true);
	}
	else if(type == 1){//wall
                setShield(false);
                setBlock(true);
                setDestructible(true);
		setIsDead(false);
        }
        else if(type == 2){//iron
                setShield(false);
                setBlock(true);
                setDestructible(false);
		setIsDead(false);
        }
        else if(type == 3){//grass
                setShield(true);
                setBlock(false);
                setDestructible(false);
		setIsDead(false);
        }
        else if(type == 4){//river
                setShield(false);
                setBlock(true);
                setDestructible(false);
		setIsDead(false);
        }
	else if(type == 5){//boundary
		setShield(false);
		setBlock(true);
		setDestructible(false);
		setIsDead(false);
	}
	m_X = x;
        m_Y = y;
        m_Rect.moveTo(m_X,m_Y);
}
int Brick::getType(){
	return m_type;
}
float Brick::getX(){
        return m_X;
}
void Brick::setShield(bool s){
        m_shield = s;
}
void Brick::setBlock(bool b){
        m_block = b;
}
void Brick::setDestructible(bool d){
        m_destructible = d;
}
bool Brick::getShield(){
        return m_shield;
}
bool Brick::getBlock(){
        return m_block;
}
bool Brick::getDestructible(){
        return m_destructible;
}
float Brick::getY(){
        return m_Y;
}
QPixmap Brick::getPix(){
	if(m_type ==0){
		return m_pixmap_black;
	}
	else if(m_type ==1){
        	return m_pixmap_wall;
	}
	else if(m_type ==2){
		return m_pixmap_iron;
	}
	else if(m_type ==3){
		return m_pixmap_grass;
	}
	else if(m_type ==4){
		return m_pixmap_river;
	}
	else if(m_type == 5){
		return m_pixmap_black;
	}

}
bool Brick::getIsDead(){
        return m_isdead;
}
void Brick::setType(int t){
	m_type =t;

}
void Brick::setIsDead(bool i){
        m_isdead = i;
	if(m_isdead == true){
		setType(0);
	}
	
}

