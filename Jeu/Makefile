mainTestOut : main.o Class_Player.o class_ennemi.o map.o Bullet.o BulletTeleguided.o BulletHache.o Arme.o ArmeBaguette.o ArmeHache.o Animation.o
	g++ main.o Class_Player.o class_ennemi.o map.o Bullet.o BulletHache.o BulletTeleguided.o Arme.o ArmeBaguette.o ArmeHache.o Animation.o -o mainTestOut -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp Player.h map.cpp Animation.hpp ennemi.h Armes/Bullet.hpp Armes/Arme.hpp Armes/ArmeBaguette.hpp Armes/ArmeHache.hpp
	g++ -Wall main.cpp -c

Class_Player.o : Player.h Class_Player.cpp
	g++ -Wall Class_Player.cpp -c

class_ennemi.o : ennemi.h class_ennemi.cpp Player.h
	g++ -Wall class_ennemi.cpp -c

map.o : map.h map.cpp
	g++ -Wall map.cpp -c 

Bullet.o : Armes/Bullet.hpp Armes/Bullet.cpp Animation.hpp Player.h ennemi.h
	g++ -Wall Armes/Bullet.cpp -c

BulletTeleguided.o : Armes/BulletTeleguided.hpp Armes/BulletTeleguided.cpp Armes/Bullet.hpp
	g++ -Wall Armes/BulletTeleguided.cpp -c

BulletHache.o : Armes/BulletHache.hpp Armes/BulletHache.cpp Armes/Bullet.hpp
	g++ -Wall Armes/BulletHache.cpp -c 

Arme.o : Armes/Arme.hpp Armes/Arme.cpp Armes/Bullet.hpp Animation.hpp Player.h ennemi.h
	g++ -Wall Armes/Arme.cpp -c

ArmeBaguette.o : Armes/ArmeBaguette.hpp Armes/ArmeBaguette.cpp Armes/Arme.hpp Armes/BulletTeleguided.hpp
	g++ -Wall Armes/ArmeBaguette.cpp -c

ArmeHache.o : Armes/ArmeHache.hpp Armes/ArmeHache.cpp Armes/Arme.hpp Armes/BulletHache.hpp
	g++ -Wall Armes/ArmeHache.cpp -c

Animation.o : Animation.hpp Animation.cpp
	g++ -Wall Animation.cpp -c

