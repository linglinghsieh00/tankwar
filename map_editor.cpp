
#include "map_editor.h"

MapEditor::MapEditor(){
        m_type_tmp = 0;
        setTerrain(1);
}
void MapEditor::setTerrain(int i){
        if(i == 1){
                ifstream map_in("Map1.txt",ios::in);
                if(!map_in){
                        cerr << "Failed opening map1" << endl;
                        exit(1);
                }
                for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
                        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
                                map_in >> m_type_tmp;
                                brick[i][j].setBrick(m_type_tmp,j*TERRAIN_UNIT,i*TERRAIN_UNIT);

                        }
                }
        }
        if(i == 2){
                ifstream map_in("Map2.txt",ios::in);
                if(!map_in){
                        cerr << "Failed opening map1" << endl;
                        exit(1);
                }
                for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
                        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
                                map_in >> m_type_tmp;
                                brick[i][j].setBrick(m_type_tmp,j*TERRAIN_UNIT,i*TERRAIN_UNIT);

                        }
                }
	
	}
        if(i == 3){
                ifstream map_in("Map3.txt",ios::in);
                if(!map_in){
                        cerr << "Failed opening map1" << endl;
                        exit(1);
                }
                for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
                        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
                                map_in >> m_type_tmp;
                                brick[i][j].setBrick(m_type_tmp,j*TERRAIN_UNIT,i*TERRAIN_UNIT);

                        }
                }

	}
	m_type_tmp =0;
}

void MapEditor::setBrick(int x,int y){
        brick[y][x].setType(m_type_tmp);
}
void MapEditor::saveMap(int c){
	if(c==1){
        	ofstream map_out("Map1.txt",ios::out);
        	if(!map_out){
        	        cerr << "Failed saving map1" << endl;
        	        exit(1);
        	}
        	for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
        	        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
        	                map_out << brick[i][j].getType() << " ";
        	        }
        	        map_out <<"\n" ;
        	}
	}
        if(c==2){
                ofstream map_out("Map2.txt",ios::out);
                if(!map_out){
                        cerr << "Failed saving map1" << endl;
                        exit(1);
                }
                for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
                        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
                                map_out << brick[i][j].getType() << " ";
                        }
                        map_out <<"\n" ;
                }
        }
        if(c==3){
                ofstream map_out("Map3.txt",ios::out);
                if(!map_out){
                        cerr << "Failed saving map1" << endl;
                        exit(1);
                }
                for(unsigned int i=0;i<TERRAIN_HEIGHT;i++){
                        for(unsigned int j=0;j<TERRAIN_WIDTH;j++){
                                map_out << brick[i][j].getType() << " ";
                        }
                        map_out <<"\n" ;
                }
        }
	m_type_tmp = 0;

}
void MapEditor::setType(int t){
        m_type_tmp = t;
}
