
#include "base.h"
Base::Base(){
        m_pixmap_base.load(BASE_PATH);
        m_Rect.setHeight(m_pixmap_base.height());
        m_Rect.setWidth(m_pixmap_base.width());
        setBase(730,1500);
        setIsDead(false);
}
void Base::setBase(int x,int y){
        m_X = x;
        m_Y = y;
        m_Rect.moveTo(m_X,m_Y);
}
float Base::getX(){
        return m_X;
}
float Base::getY(){
        return m_Y;
}
QPixmap Base::getPix(){
        return m_pixmap_base;
}
bool Base::getIsDead(){
        return m_isdead;
}
void Base::setIsDead(bool i){
        m_isdead = i;
}
