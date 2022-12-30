#ifndef OURTANK_H
#define OURTANK_H
#include <QPixmap>
#include <QRect>
#include "Bullet.h"
#include <QSound>

class OurTank{
        public:
                OurTank();
                void shoot(int r,bool i);
		void reload();
                void setPosition(float x,float y);
                void setDirection(int r);
		void setFireReady(bool i);
		QPixmap getPix();
                QRect getRec();
                float getX();
                float getY();
                int getDirection();
		bool getFireReady();
                QRect m_Rect;
                void setRecorder(int c);
                Bullet m_bullets[BULLET_NUM];
		void setIsDead(bool i);
		bool getIsDead();
		void setBlood(float b);
		float getBlood();
		void BulletReloadTimer();
		void setFireRate(int i);
		int getFireRate();
		void FireRateTimer();
		void updateFireNumber();
		void updateBlood(float b);
		void updateTankPosition();
		void setIsMove(bool m);
		bool getIsMove();
		bool getFree();
		void setFree(bool f);
                void setContinuous(int c);
                void setBuffCounter();
                int getBuffCounter();
		void setEnforceBullet(bool e);
		bool getEnforceBullet();
		void RemoveBuff();
		void setBuff(int b);		

        private:
                QPixmap m_tank_up;
                QPixmap m_tank_left;
                QPixmap m_tank_right;
                QPixmap m_tank_down;
                float m_X;
                float m_Y;
                int m_direction;
                int m_recorder;
		bool fireReady;
		bool m_isdead;
		bool m_isfree;
		float m_blood;
		int bulletreloadtime[BULLET_NUM]={0};
		int bulletboomtime[BULLET_NUM]={0};
		int m_firerate=2;
		int m_fireratecounter=0;
		int m_firenumber=1;
		bool m_ismove;
                int m_buffcounter;
                int m_continuous=1;
		bool m_enforcebullet=false;
		//QSound *bulletshoot("./sounds/bulletshoot.wav",this);

};
#endif
