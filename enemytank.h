#ifndef ENEMYTANK_H
#define ENEMYTANK_H
#include <QPixmap>
#include <QRect>
#include "Bullet.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QSound>

class EnemyTank{
        public:
                EnemyTank();
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
                QRect m_tank_wall_up_Rect;
                QRect m_tank_wall_left_Rect;
                QRect m_tank_wall_down_Rect;
                QRect m_tank_wall_right_Rect;
                QRect m_tank_bulletdetect_forward_Rect;
                QRect m_tank_bulletdetect_left_Rect;
                QRect m_tank_bulletdetect_right_Rect;
                QRect m_tank_bulletdetect_down_Rect;
                QRect space;
                QRect m_tank_attact_left_Rect;
                QRect m_tank_attact_right_Rect;
                QRect m_tank_attact_down_Rect;
                QRect test;
                void setRecorder(int c);
                Bullet m_bullets[BULLET_NUM];
                void setIsDead(bool i);
                bool getIsDead();
                void setBlood(int b);
                int getBlood();
                void BulletReloadTimer();
                void setFireRate(int i);
                int getFireRate();
                void FireRateTimer();
                void updateFireNumber();
                void setFree(bool f);
                bool getFree();
                QRect getRec_up();
                QRect getRec_left();
                QRect getRec_right();
                QRect getRec_down();
                void updateTankPosition();
                QRect getRec_BulletDetector_Forward();
                QRect getRec_BulletDetector_Left();
                QRect getRec_BulletDetector_Right();
                QRect getRec_BulletDetector_Down();
                void updateBlood(float b);
                void setStop(bool s);
                bool getStop();
                void StopTimer();
                void SelfDestruct();
                void setType(int t);
                void DropBuff();
                QRect buff_1_Rect;
                QRect buff_2_Rect;
                QRect buff_3_Rect;
                void setIsDrop(int i,bool j);
                int getIsDrop();
                QPixmap buff_1_Pix;
                QPixmap buff_2_Pix;
                QPixmap buff_3_Pix;
		QPixmap tankboom_Pix;
		void TankBoomTimer();
		void TankBoom();
		QPixmap getPix_TankBoom();
		bool getTankBoom();		
                void setIsOut(bool o);
                void Cannon();
		int getType();
		bool getIsOut();
		
        private:
                QPixmap m_tank_up;
                QPixmap m_tank_left;
                QPixmap m_tank_right;
                QPixmap m_tank_down;
                QPixmap m_tank_test;
                QPixmap m_strongertank_up;
                QPixmap m_strongertank_left;
                QPixmap m_strongertank_right;
                QPixmap m_strongertank_down;
                int m_X;
                int m_Y;
                int m_direction;
                int m_recorder;
                bool fireReady;
                bool m_isdead;
                float m_blood;
                int bulletreloadtime[BULLET_NUM]={0};
                int bulletboomtime[BULLET_NUM]={0};
                int m_firerate=2;
                int m_fireratecounter=0;
                int m_firenumber=1;
                bool m_free;
                bool m_stop;
                int m_stoptime=0;
                int m_type=0;
                int m_buffchoose;
                int m_buff1=0;
                int m_buff2=0;
                int m_buff3=0;
		int m_tankboomtime=0;
		bool m_tankboom=false;
		bool m_out=false;
};
#endif

