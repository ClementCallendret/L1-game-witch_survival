mainOut : main.o gameengine.o MainMenu.o menustate.o playstate.o Upgrade.o upgradestate.o Class_Player.o class_ennemi.o ennemi_villageois.o ennemi_chevalier.o vague.o map.o Bullet.o BulletFireball.o BulletHache.o BulletOrbe.o BulletEclair.o BulletEpee.o Arme.o ArmeFireball.o ArmeHache.o ArmeOrbe.o ArmeEclair.o ArmeEpee.o ArmeLivre.o ArmeCrane.o ArmeChaudron.o ArmeElixir.o ArmeBalais.o Animation.o Shield.o
	g++ main.o gameengine.o MainMenu.o menustate.o playstate.o Upgrade.o upgradestate.o Class_Player.o class_ennemi.o ennemi_villageois.o ennemi_chevalier.o vague.o map.o Bullet.o BulletFireball.o BulletHache.o BulletOrbe.o BulletEclair.o BulletEpee.o Arme.o ArmeFireball.o ArmeHache.o ArmeOrbe.o ArmeEclair.o ArmeEpee.o ArmeLivre.o ArmeCrane.o ArmeChaudron.o ArmeElixir.o ArmeBalais.o Animation.o Shield.o -o mainOut -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp gameengine.hpp menustate.hpp
	g++ -Wall main.cpp -c

gameengine.o : gameengine.hpp gameengine.cpp gamestate.hpp
	g++ -Wall gameengine.cpp -c 

MainMenu.o : MainMenu.hpp MainMenu.cpp 
	g++ -Wall MainMenu.cpp -c

menustate.o : menustate.hpp menustate.cpp gamestate.hpp MainMenu.hpp gameengine.hpp playstate.hpp
	g++ -Wall menustate.cpp -c 

playstate.o : playstate.hpp playstate.cpp upgradestate.hpp game/Player.h gamestate.hpp menustate.hpp game/Player.h game/map.h game/ennemi_villageois.h game/ennemi_chevalier.h game/Armes/Arme.hpp game/Armes/ArmeFireball.hpp game/Armes/ArmeHache.hpp game/Armes/ArmeOrbe.hpp game/Armes/ArmeEclair.hpp game/Armes/Shield.hpp game/Armes/ArmeEpee.hpp game/Armes/ArmeLivre.hpp game/Armes/ArmeCrane.hpp game/Armes/ArmeChaudron.hpp game/Armes/ArmeElixir.hpp game/Armes/ArmeBalais.hpp game/vague.hpp
	g++ -Wall playstate.cpp -c 

Upgrade.o : Upgrade.cpp Upgrade.hpp game/Player.h game/Armes/Arme.hpp
	g++ -Wall Upgrade.cpp -c

upgradestate.o : playstate.hpp upgradestate.cpp upgradestate.hpp gamestate.hpp Upgrade.hpp
	g++ -Wall upgradestate.cpp -c 

Class_Player.o : game/Player.h game/Class_Player.cpp
	g++ -Wall game/Class_Player.cpp -c

class_ennemi.o : game/ennemi.h game/class_ennemi.cpp game/Player.h
	g++ -Wall game/class_ennemi.cpp -c

ennemi_villageois.o : game/ennemi_villageois.cpp game/ennemi.h game/ennemi_villageois.h 
	g++ -Wall game/ennemi_villageois.cpp -c

ennemi_chevalier.o : game/ennemi_chevalier.cpp game/ennemi.h game/ennemi_chevalier.h
	g++ -Wall game/ennemi_chevalier.cpp -c
	
vague.o : game/vague.hpp game/vague.cpp game/ennemi_villageois.h game/ennemi.h game/ennemi_chevalier.h
	g++ -Wall game/vague.cpp -c

map.o : game/map.h game/map.cpp
	g++ -Wall game/map.cpp -c

Bullet.o : game/Armes/Bullet.hpp game/Armes/Bullet.cpp game/Animation.hpp game/Player.h game/ennemi.h
	g++ -Wall game/Armes/Bullet.cpp -c

BulletFireball.o : game/Armes/BulletFireball.hpp game/Armes/BulletFireball.cpp game/Armes/Bullet.hpp
	g++ -Wall game/Armes/BulletFireball.cpp -c

BulletHache.o : game/Armes/BulletHache.hpp game/Armes/BulletHache.cpp game/Armes/Bullet.hpp
	g++ -Wall game/Armes/BulletHache.cpp -c 

BulletOrbe.o : game/Armes/BulletOrbe.hpp game/Armes/BulletOrbe.cpp game/Armes/Bullet.hpp
	g++ -Wall game/Armes/BulletOrbe.cpp -c

BulletEclair.o : game/Armes/BulletEclair.hpp game/Armes/BulletEclair.cpp game/Armes/Bullet.hpp
	g++ -Wall game/Armes/BulletEclair.cpp -c

BulletEpee.o : game/Armes/BulletEpee.hpp game/Armes/BulletEpee.cpp game/Armes/Bullet.hpp
	g++ -Wall game/Armes/BulletEpee.cpp -c

Arme.o : game/Armes/Arme.hpp game/Armes/Arme.cpp game/Armes/Bullet.hpp game/Animation.hpp game/Player.h game/ennemi.h
	g++ -Wall game/Armes/Arme.cpp -c

ArmeFireball.o : game/Armes/ArmeFireball.hpp game/Armes/ArmeFireball.cpp game/Armes/Arme.hpp game/Armes/BulletFireball.hpp
	g++ -Wall game/Armes/ArmeFireball.cpp -c

ArmeHache.o : game/Armes/ArmeHache.hpp game/Armes/ArmeHache.cpp game/Armes/Arme.hpp game/Armes/BulletHache.hpp
	g++ -Wall game/Armes/ArmeHache.cpp -c

ArmeOrbe.o : game/Armes/ArmeOrbe.hpp game/Armes/ArmeOrbe.cpp game/Armes/Arme.hpp game/Armes/BulletOrbe.hpp
	g++ -Wall game/Armes/ArmeOrbe.cpp -c

ArmeEclair.o : game/Armes/ArmeEclair.hpp game/Armes/ArmeEclair.cpp game/Armes/Arme.hpp game/Armes/BulletEclair.hpp
	g++ -Wall game/Armes/ArmeEclair.cpp -c

ArmeEpee.o : game/Armes/ArmeEpee.hpp game/Armes/ArmeEpee.cpp game/Armes/Arme.hpp game/Armes/BulletEpee.hpp
	g++ -Wall game/Armes/ArmeEpee.cpp -c

ArmeLivre.o : game/Armes/ArmeLivre.hpp game/Armes/ArmeLivre.cpp game/Armes/Arme.hpp
	g++ -Wall game/Armes/ArmeLivre.cpp -c

ArmeCrane.o : game/Armes/ArmeCrane.hpp game/Armes/ArmeCrane.cpp game/Armes/Arme.hpp
	g++ -Wall game/Armes/ArmeCrane.cpp -c

ArmeChaudron.o : game/Armes/ArmeChaudron.hpp game/Armes/ArmeChaudron.cpp game/Armes/Arme.hpp
	g++ -Wall game/Armes/ArmeChaudron.cpp -c

ArmeElixir.o : game/Armes/ArmeElixir.hpp game/Armes/ArmeElixir.cpp game/Armes/Arme.hpp
	g++ -Wall game/Armes/ArmeElixir.cpp -c

ArmeBalais.o : game/Armes/ArmeBalais.hpp game/Armes/ArmeBalais.cpp game/Armes/Arme.hpp
	g++ -Wall game/Armes/ArmeBalais.cpp -c

Animation.o : game/Animation.hpp game/Animation.cpp
	g++ -Wall game/Animation.cpp -c

Shield.o : game/Armes/Shield.hpp game/Armes/Shield.cpp game/Armes/Arme.hpp
	g++ -Wall game/Armes/Shield.cpp -c

