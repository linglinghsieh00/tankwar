#ifndef TERRAIN_H
#define TERRAIN_H


#include <QPixmap>
#include "Brick.h"
#include <QRect>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;
class Terrain{
	public:
		Terrain();
		void setTerrain(bool resume,int stage);
		Brick brick[TERRAIN_WIDTH][TERRAIN_HEIGHT];
	private:
		int type_tmp;
};
		
#endif
