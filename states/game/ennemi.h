#ifndef ENNEMI_H
#define ENNEMI_H

#include "Player.h"
#include <SFML/Graphics.hpp>

class Ennemi
{
private:
	Player* joueur;
	static constexpr float speed = 1.;
	sf::Vector2f location = sf::Vector2f(0, 0);

public:
	Ennemi(Player* j);
	short PV = 100;

	void draw(sf::RenderWindow &window);
	void inputs();

	sf::Vector2f getEnnemiPos(){
		return sf::Vector2f(location.x, location.y);
	}
};


#endif