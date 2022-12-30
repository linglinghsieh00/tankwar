
#ifndef WALL_H
#define WALL_H
#include <QPixmap>
#include <QRect>
#include "config.h"
class Brick{
        public:
                Brick();	
                void setBrick(int type,int x,int y);
                void setShield(bool s);
                void setBlock(bool b);
                void setDestructible(bool d);
                bool getShield();
                bool getBlock();
                bool getDestructible();
                float getX();
                float getY();
                QPixmap getPix();
                QRect m_Rect;
                bool getIsDead();
                void setIsDead(bool i);
		int getType();
		void setType(int t);

        private:
		QPixmap m_pixmap_wall;
		QPixmap m_pixmap_black;
		QPixmap m_pixmap_river;
		QPixmap m_pixmap_iron;
		QPixmap m_pixmap_grass;
                bool m_isdead;
                bool m_shield;
                bool m_block;
                bool m_destructible;
                int m_X;
                int m_Y;
		int m_type;
};
#endif
