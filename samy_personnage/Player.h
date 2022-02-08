#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "deplacement.h"

namespace sf
{
	class RenderWindow;
}

class Player
{
private:
	static constexpr float speed = 3.f;
	deplacement2D location = deplacement2D(0, 0);

public:
	Player();
	short PV[100];

	void draw(sf::RenderWindow &window);
	void inputs();
};

#endif