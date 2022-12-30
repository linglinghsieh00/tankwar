#include "terrain.h"

Terrain::Terrain(){
	for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
		for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
			brick[i][j].setBrick(0,j*TERRAIN_UNIT,i*TERRAIN_UNIT);
			//type_tmp[i][j]= 0;
		}
	}
	type_tmp = 0;
}

void Terrain::setTerrain(bool resume,int stage){
        if(resume == false){
        	if(stage == 1){
        	        ifstream map1_in("Map1.txt",ios::in);
        	        if(!map1_in){
        	                cerr << "Failed opening map1" << endl;
        	                exit(1);
        	        }
        	        for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
        	                for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
        	                        map1_in >> type_tmp;
        	                        brick[i][j].setBrick(type_tmp,j*TERRAIN_UNIT,i*TERRAIN_UNIT);
        	                }
        	        }
        	}
		if(stage == 2){
        	        ifstream map2_in("Map2.txt",ios::in);
        	        if(!map2_in){
        	                cerr << "Failed opening map2" << endl;
        	                exit(1);
        	        }
        	        for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
        	                for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
        	                        map2_in >> type_tmp;
        	                        brick[i][j].setBrick(type_tmp,j*TERRAIN_UNIT,i*TERRAIN_UNIT);
        	                }
        	        }
        	}
        	if(stage == 3){
        	        ifstream map3_in("Map3.txt",ios::in);
        	        if(!map3_in){
        	                cerr << "Failed opening map3" << endl;
        	                exit(1);
        	        }
        	        for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
        	                for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
        	                        map3_in >> type_tmp;
        	                        brick[i][j].setBrick(type_tmp,j*TERRAIN_UNIT,i*TERRAIN_UNIT);
        	                }
        	        }
        	}
        }
        else if(resume == true){
                ifstream map4_in("Map4.txt",ios::in);
                if(!map4_in){
                        cerr << "Failed opening map4" << endl;
                        exit(1);
                }
                for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
                        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
                                map4_in >> type_tmp;
                                brick[i][j].setBrick(type_tmp,j*TERRAIN_UNIT,i*TERRAIN_UNIT);
                        }
                }
        }
}
