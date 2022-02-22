#ifndef ENNEMI_H
#define ENNEMI_H

#include "Player.h"
#include <SFML/Graphics.hpp>

class Ennemi
{
protected:
	Player* joueur;
	float speed,degat;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f location;
	sf::Vector2f taille;

public:
	Ennemi(Player* j);
	short PV;
	void draw(sf::RenderWindow &window);
	void update();
    void collision();
	sf::Vector2f getEnnemiPos(){
		return sf::Vector2f(location.x, location.y);
	};

	sf::Vector2f getEnnemiTaille(){
		return sf::Vector2f(taille.x, taille.y);
	};
	
};


#endif