#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QTimer>
#include <config.h>
#include "Terrain.h"
#include "OurTank.h"
#include "brick.h"
#include "EnemyTank.h"
#include "Base.h"
#include <QSound>

using namespace std;
class Algorithm{                
        public:
		Algorithm();
                void playGame();
                void update();
                void collisionDetector();
                void bullet_brick();
                void ourBullet_enemy();
                void ourBullet_enemyBullet();
                void enemyBullet_ourtank();
                void tank_brick();
                void tank_tank();
		void enemy_base();
                bool ArriveDestination();
                void Destination();
                void updateTankPosition();
                void Dodge();
		void EnemyShoot();
		void SpawnTime();
		void SpawnEnemy(int stage);
		void Buff();
		bool enemyKilled();
		bool baseKilled();
		bool ourtankKilled();
                void setOurTank(bool resume,int mode);
                void setEnemyTank(bool resume,int stage);
                void setGame(bool resume,int mode,int stage);
		int getEnemyLeft();
		void updateBulletDamage();
		void GameSave();
		void SaveOurTank();
		void SaveEnemyTank();
		void SaveTerrain();
		void RemoveBuff();
		void LoadBuff();
		void CleanBuffRect();

        public:
                OurTank ourtank[OURTANK_NUM];
                EnemyTank enemy[ENEMY_NUM];
		Base base;
                int m_destination_x=900;
                int m_destination_y=100;
		Terrain terrain;

	private:
		int m_born_number=0;
		int choose=0;
		int m_enemy_number=0;
		int m_spawn_time=0;
		int spawn_point;
		int buff_counter=0;
};
#endif

