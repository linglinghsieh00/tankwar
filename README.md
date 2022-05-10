Author: Tzu Ling Hsieh

Date: May, 10, 2022



Description
----------------------------

Project 1: Tank War
1）實現遊戲機本要求：

遊戲開始後刷出敵軍坦克，敵軍坦克随機移動並攻擊。
玩家控制的坦克透過移動和發射子彈來保護基地並催毀敵方

失敗條件:基地被摧毁或者玩家生命耗盡
勝利條件:消滅所有敵軍

2）當局狀態欄

顯示玩家生命值 敵軍坦克剩餘量 關卡數 單人或者雙人模式
提供暫停 繼續 開始 離開按鈕

遊戲结束時顯示：
勝負:赢了顯示“Pass Game"圖示，輸了顯示”Game Over"
通關:完整通完三關會顯示"Win!"

3）遊戲開始介面

遊戲開始前選擇單\雙人模式 
透過檔案讀取可以從3種地圖選一種
透過檔案寫入讀出可進行上次未完成之遊戲

Given input files of the lab
----------------------------

(1) Map1.txt
(2) Map2.txt
(3) Map3.txt
(4) Map4.txt

Compilation Guide
----------------------------

1. Enter "cd project_1_5_3" to go project direction
2. Enter "qmake-qt5 -project" to creat .pro file
3. Enter "qmake-qt5 “QT+=widgets“ “QT+=core gui“ “QT+=widgets multimedia“" to creat Makefile
4. Enter "make"
5. Open terminal 2 and enter "startxwin" "execute /bin/pulseaudio.exe" in Cygwin download folder by administrator
6. File name "main.cpp" is for implementation of the project.
7. Open terminal 1 and enter "export DISPLAY=:0.0"
8. Enter "./project_1_4_30" for execution.


basic requirements
-------------------------
1.Show 
• Our tank
• Enemy tank
• Stronger enemy
• Bullet
• Eagles (Base Camp)
• Health point(on the scoreboard)
• Number of enemies left(on the scoreboard)
• Number of stage(on the scoreboard)
• Design backgroundon the screen
om screen

2.bout tank
• Two modes: 1 player or 2 players fighting with computer enemy.
• Player 1 and player 2 can move up, down, left and right and shoot bullets by pressing 
buttons.
• Enemy tanks can move up, down, left and right and shoot bullets automatically

3.About game rule
• If the bullet hits the enemy tank, the enemy tank will disappear and explosion effect 
will be displayed.
• Our tanks Health point are designed to 300, once the base camp is destroyed or the 
Health point is zero, the game over. (our tank =300,enemy tank=100, stronger 
enemy=300)
• Game menu and next level and game end animation to do. 
• he bullet of enemy tank’s only cause damage to our tank.
• Once an enemy tank dies, another new enemy tank randomly spawned on the map
•After defeating Stronger enemies, they will drop buff items. 
•After picking them up, our tank can obtain one of the following three abilities.We offer three different buffs.
1) Enemy tanks will be frozen for 10 seconds, only our tanks can move .
2) Weapon upgrade 
  a. When getting the buff for the first time, the bullets speed double.
  b. When getting the buff for the second time, our tanks can shoot two bullets at the same time.
  c. When getting the buff for the third time, the bullet can break the iron bricks.
3) All the enemy tanks explode on the map.

3.About game appearance
•Main window is 780*780 pixel(26*26 grid, 1 grid is 30*30 pixel).
•The scoreboard include the remaining number of enemies, Health point, stage, mode (1 player or 2 players),

4.About the bullet
•One bullet 100 blood damage
•Only one bullet can be fired at a time, and the next bullet cannot be fired until the bullet is gone.
•When the bullet hits the brick, both of them will disappear at the same time.
•When the bullet hits the iron brick, only the bullet disappears, and the iron brick still exists. 
•When the bullet hits the sea, it just goes through.
•When the bullet hits the grass, it becomes invisible until it crosses the grass.
•When the bullet hits the surrounding border, it will disappear

Bonus
--------------------------------------
1. Sound effect
2. Game save function
3. Map editor


