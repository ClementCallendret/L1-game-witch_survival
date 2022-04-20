mainOut : main.o Vague.o Map.o Animation.o GameEngine.o MainMenu.o MenuState.o CreditState.o PlayState.o PauseState.o EndState.o Upgrade.o UpgradeState.o Player.o CEnnemi.o Bullet.o BulletFireball.o BulletHache.o BulletOrbe.o BulletEclair.o BulletEpee.o Arme.o ArmeFireball.o ArmeHache.o ArmeOrbe.o ArmeEclair.o ArmeEpee.o ArmeLivre.o ArmeCrane.o ArmeChaudron.o ArmeElixir.o ArmeBalais.o ArmeShield.o
	g++ main.o Vague.o Map.o Animation.o GameEngine.o MainMenu.o MenuState.o CreditState.o PlayState.o PauseState.o EndState.o Upgrade.o UpgradeState.o Player.o CEnnemi.o Bullet.o BulletFireball.o BulletHache.o BulletOrbe.o BulletEclair.o BulletEpee.o Arme.o ArmeFireball.o ArmeHache.o ArmeOrbe.o ArmeEclair.o ArmeEpee.o ArmeLivre.o ArmeCrane.o ArmeChaudron.o ArmeElixir.o ArmeBalais.o ArmeShield.o -o mainOut -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

main.o : game/main.cpp game/States/GameEngine.hpp game/States/MenuState.hpp
	g++ -Wall game/main.cpp -c

Vague.o : game/Vague.hpp game/Vague.cpp game/Ennemis/CEnnemi.hpp game/Ennemis/ChauveSouris.hpp game/Ennemis/Chevalier.hpp game/Ennemis/Villageoi.hpp game/Ennemis/Fantome.hpp game/Ennemis/Enervax.hpp game/Ennemis/Dragon.hpp game/Ennemis/Gargouille.hpp game/Ennemis/Arbre.hpp game/Ennemis/Loup.hpp game/Ennemis/Geant.hpp
	g++ -Wall game/Vague.cpp -c

Map.o : game/Map.hpp game/Map.cpp game/Animation.hpp
	g++ -Wall game/Map.cpp -c

Animation.o : game/Animation.hpp game/Animation.cpp
	g++ -Wall game/Animation.cpp -c

GameEngine.o : game/States/GameEngine.hpp game/States/GameEngine.cpp game/States/GameState.hpp
	g++ -Wall game/States/GameEngine.cpp -c 

MainMenu.o : game/MainMenu.hpp game/MainMenu.cpp 
	g++ -Wall game/MainMenu.cpp -c

MenuState.o : game/States/MenuState.hpp game/States/MenuState.cpp game/States/GameState.hpp game/MainMenu.hpp game/States/PlayState.hpp game/States/CreditState.hpp
	g++ -Wall game/States/MenuState.cpp -c 

CreditState.o : game/States/CreditState.hpp game/States/CreditState.cpp game/States/GameState.hpp game/States/MenuState.hpp
	g++ -Wall game/States/CreditState.cpp -c 

PlayState.o : game/States/PlayState.hpp game/States/PlayState.cpp game/States/GameState.hpp game/Player.hpp game/Map.hpp game/Vague.hpp game/Ennemis/CEnnemi.hpp game/Ennemis/Enervax.hpp game/Ennemis/Dragon.hpp game/Armes/Arme.hpp game/Armes/ArmeFireball.hpp game/Armes/ArmeHache.hpp game/Armes/ArmeOrbe.hpp game/Armes/ArmeEclair.hpp game/Armes/ArmeShield.hpp game/Armes/ArmeEpee.hpp game/Armes/ArmeLivre.hpp game/Armes/ArmeCrane.hpp game/Armes/ArmeBalais.hpp game/Armes/ArmeChaudron.hpp game/Armes/ArmeElixir.hpp game/States/UpgradeState.hpp game/States/PauseState.hpp game/States/EndState.hpp
	g++ -Wall game/States/PlayState.cpp -c 

PauseState.o : game/States/PauseState.hpp game/States/PauseState.cpp game/States/PlayState.hpp game/States/MenuState.hpp game/States/GameState.hpp
	g++ -Wall game/States/PauseState.cpp -c

EndState.o : game/States/EndState.hpp game/States/EndState.cpp game/States/MenuState.hpp game/States/GameState.hpp
	g++ -Wall game/States/EndState.cpp -c
	
Upgrade.o : game/Upgrade.cpp game/Upgrade.hpp game/Player.hpp game/Armes/Arme.hpp
	g++ -Wall game/Upgrade.cpp -c

UpgradeState.o : game/States/UpgradeState.cpp game/States/UpgradeState.hpp game/States/PlayState.hpp game/States/GameState.hpp game/Upgrade.hpp
	g++ -Wall game/States/UpgradeState.cpp -c 

Player.o : game/Player.hpp game/Player.cpp
	g++ -Wall game/Player.cpp -c

CEnnemi.o : game/Ennemis/CEnnemi.hpp game/Ennemis/CEnnemi.cpp game/Player.hpp game/Animation.hpp
	g++ -Wall game/Ennemis/CEnnemi.cpp -c

Bullet.o : game/Bullets/Bullet.hpp game/Bullets/Bullet.cpp game/Ennemis/CEnnemi.hpp
	g++ -Wall game/Bullets/Bullet.cpp -c

BulletFireball.o : game/Bullets/BulletFireball.hpp game/Bullets/BulletFireball.cpp game/Bullets/Bullet.hpp game/Animation.hpp
	g++ -Wall game/Bullets/BulletFireball.cpp -c

BulletHache.o : game/Bullets/BulletHache.hpp game/Bullets/BulletHache.cpp game/Bullets/Bullet.hpp game/Player.hpp
	g++ -Wall game/Bullets/BulletHache.cpp -c 

BulletOrbe.o : game/Bullets/BulletOrbe.hpp game/Bullets/BulletOrbe.cpp game/Bullets/Bullet.hpp game/Animation.hpp game/Player.hpp
	g++ -Wall game/Bullets/BulletOrbe.cpp -c

BulletEclair.o : game/Bullets/BulletEclair.hpp game/Bullets/BulletEclair.cpp game/Bullets/Bullet.hpp game/Animation.hpp
	g++ -Wall game/Bullets/BulletEclair.cpp -c

BulletEpee.o : game/Bullets/BulletEpee.hpp game/Bullets/BulletEpee.cpp game/Bullets/Bullet.hpp game/Animation.hpp game/Player.hpp
	g++ -Wall game/Bullets/BulletEpee.cpp -c

Arme.o : game/Armes/Arme.hpp game/Armes/Arme.cpp game/Bullets/Bullet.hpp
	g++ -Wall game/Armes/Arme.cpp -c

ArmeFireball.o : game/Armes/ArmeFireball.hpp game/Armes/ArmeFireball.cpp game/Armes/Arme.hpp game/Bullets/BulletFireball.hpp
	g++ -Wall game/Armes/ArmeFireball.cpp -c

ArmeHache.o : game/Armes/ArmeHache.hpp game/Armes/ArmeHache.cpp game/Armes/Arme.hpp game/Bullets/BulletHache.hpp
	g++ -Wall game/Armes/ArmeHache.cpp -c

ArmeOrbe.o : game/Armes/ArmeOrbe.hpp game/Armes/ArmeOrbe.cpp game/Armes/Arme.hpp game/Bullets/BulletOrbe.hpp
	g++ -Wall game/Armes/ArmeOrbe.cpp -c

ArmeEclair.o : game/Armes/ArmeEclair.hpp game/Armes/ArmeEclair.cpp game/Armes/Arme.hpp game/Bullets/BulletEclair.hpp
	g++ -Wall game/Armes/ArmeEclair.cpp -c

ArmeEpee.o : game/Armes/ArmeEpee.hpp game/Armes/ArmeEpee.cpp game/Armes/Arme.hpp game/Bullets/BulletEpee.hpp
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

ArmeShield.o : game/Armes/ArmeShield.hpp game/Armes/ArmeShield.cpp game/Armes/Arme.hpp
	g++ -Wall game/Armes/ArmeShield.cpp -c
