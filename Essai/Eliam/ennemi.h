#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "deplacement.h"

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
	short PV[100];

	void draw(sf::RenderWindow &window);
	void inputs();
};


#endif