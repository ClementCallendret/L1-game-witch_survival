#ifndef ENNEMI_H
#define ENNEMI_H

#include "deplacement.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

namespace sf
{
	class RenderWindow;
}


class Ennemi
{
private:
	Player* joueur;
	static constexpr float speed = 0.1;
	deplacement2D location = deplacement2D(0, 0);

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