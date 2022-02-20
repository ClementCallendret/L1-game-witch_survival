mainTestOut : main.o Class_Player.o class_ennemi.o map.o Bullet.o BulletFireball.o BulletHache.o BulletOrbe.o BulletEclair.o BulletEpee.o Arme.o ArmeFireball.o ArmeHache.o ArmeOrbe.o ArmeEclair.o ArmeEpee.o Animation.o Shield.o
	g++ main.o Class_Player.o class_ennemi.o map.o Bullet.o BulletHache.o BulletFireball.o BulletOrbe.o BulletEclair.o BulletEpee.o Arme.o ArmeFireball.o ArmeHache.o ArmeOrbe.o ArmeEclair.o ArmeEpee.o Animation.o Shield.o -o mainTestOut -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp Player.h map.cpp Animation.hpp ennemi.h Armes/Bullet.hpp Armes/Arme.hpp Armes/ArmeFireball.hpp Armes/ArmeHache.hpp
	g++ -Wall main.cpp -c

Class_Player.o : Player.h Class_Player.cpp
	g++ -Wall Class_Player.cpp -c

class_ennemi.o : ennemi.h class_ennemi.cpp Player.h
	g++ -Wall class_ennemi.cpp -c

map.o : map.h map.cpp
	g++ -Wall map.cpp -c 

Bullet.o : Armes/Bullet.hpp Armes/Bullet.cpp Animation.hpp Player.h ennemi.h
	g++ -Wall Armes/Bullet.cpp -c

BulletFireball.o : Armes/BulletFireball.hpp Armes/BulletFireball.cpp Armes/Bullet.hpp
	g++ -Wall Armes/BulletFireball.cpp -c

BulletHache.o : Armes/BulletHache.hpp Armes/BulletHache.cpp Armes/Bullet.hpp
	g++ -Wall Armes/BulletHache.cpp -c 

BulletOrbe.o : Armes/BulletOrbe.hpp Armes/BulletOrbe.cpp Armes/Bullet.hpp
	g++ -Wall Armes/BulletOrbe.cpp -c

BulletEclair.o : Armes/BulletEclair.hpp Armes/BulletEclair.cpp Armes/Bullet.hpp
	g++ -Wall Armes/BulletEclair.cpp -c

BulletEpee.o : Armes/BulletEpee.hpp Armes/BulletEpee.cpp Armes/Bullet.hpp
	g++ -Wall Armes/BulletEpee.cpp -c

Arme.o : Armes/Arme.hpp Armes/Arme.cpp Armes/Bullet.hpp Animation.hpp Player.h ennemi.h
	g++ -Wall Armes/Arme.cpp -c

ArmeFireball.o : Armes/ArmeFireball.hpp Armes/ArmeFireball.cpp Armes/Arme.hpp Armes/BulletFireball.hpp
	g++ -Wall Armes/ArmeFireball.cpp -c

ArmeHache.o : Armes/ArmeHache.hpp Armes/ArmeHache.cpp Armes/Arme.hpp Armes/BulletHache.hpp
	g++ -Wall Armes/ArmeHache.cpp -c

ArmeOrbe.o : Armes/ArmeOrbe.hpp Armes/ArmeOrbe.cpp Armes/Arme.hpp Armes/BulletOrbe.hpp
	g++ -Wall Armes/ArmeOrbe.cpp -c

ArmeEclair.o : Armes/ArmeEclair.hpp Armes/ArmeEclair.cpp Armes/Arme.hpp Armes/BulletEclair.hpp
	g++ -Wall Armes/ArmeEclair.cpp -c

ArmeEpee.o : Armes/ArmeEpee.hpp Armes/ArmeEpee.cpp Armes/Arme.hpp Armes/BulletEpee.hpp
	g++ -Wall Armes/ArmeEpee.cpp -c

Animation.o : Animation.hpp Animation.cpp
	g++ -Wall Animation.cpp -c

Shield.o : Armes/Shield.hpp Armes/Shield.cpp Armes/Arme.hpp
	g++ -Wall Armes/Shield.cpp -c
