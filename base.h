#ifndef BASE_H
#define BASE_H
#include <QPixmap>
#include <QRect>
#include "config.h"
class Base{
        public:
                Base();
                void setBase(int x,int y);
                float getX();
                float getY();
                QPixmap getPix();
                QRect m_Rect;
                bool getIsDead();
                void setIsDead(bool i);
        private:
                QPixmap m_pixmap_base;
                bool m_isdead;
                int m_X;
                int m_Y;
};
#endif

