
#ifndef BULLET_F
#define BULLET_F
#include "config.h"
#include <QPixmap>
#include <QRect>
#include <QObject>

class Bullet:public QObject{
	Q_OBJECT	
        public:
                Bullet();
                void updatePosition();
		QPixmap getPix();
		QPixmap getPix_BulletBoom();
                QRect getRect();
                void setPosition(int x,int y);
                void setDirection(int r);
                void setSpeed(int s);
                void setFree(bool f);
                int getX();
                int getY();
                int getDirection();
                int getSpeed();
                bool getFree();
                QRect m_Rect;	
		bool getIsDead();
		void setIsDead(bool d);
		void setDisPlayBulletBoom(bool d);
		bool getDisPlayBulletBoom();
		void BulletBoomTimer();
		void setBulletBoomTimer(int i);
		void updateDamage(float d);
		void setDamage(float d);
		float getDamage();
		bool compareWhoCollision(int i,int j);
		int getWhoCollision();
        private:
                QPixmap m_bullet_up;
                QPixmap m_bullet_down;
                QPixmap m_bullet_left;
                QPixmap m_bullet_right;
		QPixmap m_bulletboom;
                int m_Direction;
                int m_X;
                int m_Y;
		float m_damage;
                int m_Speed;
                bool m_free;
		bool m_isdead;
		bool m_displaybulletboom;
		int bulletboomtime;
		int whoCollision_i;
		int whoCollision_j;
};
#endif


