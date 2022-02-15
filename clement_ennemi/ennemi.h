#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "deplacement_ennemi.h"

namespace sf
{
	class RenderWindow;
}


class Ennemi
{
private:
	static constexpr float speed = 0.1;
	deplacement2D location = deplacement2D(0, 0);

public:
	Ennemi();
	short PV[100];

	void draw(sf::RenderWindow &window);
	void inputs();
};

class Player
{
private:
	static constexpr float speed = 1.f;
	deplacement2D location = deplacement2D(500,500);

public:
	Player();
	short PV[100];

	void draw(sf::RenderWindow &window);
	void inputs();
};

#endif