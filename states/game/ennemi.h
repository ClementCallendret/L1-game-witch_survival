#ifndef ENNEMI_H
#define ENNEMI_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

class Ennemi  //Def de la classe Ennemi
// Paramètre propre a chaque ennemi
{

protected: //Caracteristiques des ennemis
	
	Player* joueur;
	float speed,degat,xp,ratio;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f location;
	sf::Vector2f taille;
	std::string name;
	Animation anim;

public:
	Ennemi(Player* j, sf::Vector2f loc); //Paramètre que l'ennemi utilisera
	virtual ~Ennemi() { //On le met en virtual car c'est une classe de classe
		joueur->prendreXP(xp);
	}
	int PV; //Les points de vieeeessssss
	void draw(sf::RenderWindow &window); //Dessin de l'ennemi avec son sprite
	void update(); //update pour le déplacement des ennemis
    void collision(); //on check les collisions entre l'ennemi et le player
	sf::Vector2f getEnnemiPos(){ 
		return sf::Vector2f(location.x, location.y); //on recup la position de l'ennemi
	};

	sf::Vector2f getEnnemiTaille(){
		return sf::Vector2f(taille.x, taille.y); //On recup la taille de l'ennemi
	};
	
};


#endif