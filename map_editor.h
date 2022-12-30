#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "brick.h"
#include <fstream>
#include <iostream>
using namespace std;
class MapEditor{
        public:
                MapEditor();
                void setTerrain(int i);
                void setBrick(int x,int y);
                void saveMap(int c);
                void setType(int t);
        public:
                Brick brick[TERRAIN_HEIGHT][TERRAIN_WIDTH];
        private:
                int m_type_tmp;
};
#endif

