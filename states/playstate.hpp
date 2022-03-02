#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "gamestate.hpp"

#include "game/Player.h"
#include "game/map.h"
#include "game/ennemi_villageois.h"

#include "game/Armes/Arme.hpp"
#include "game/Armes/ArmeFireball.hpp"
#include "game/Armes/ArmeHache.hpp"
#include "game/Armes/ArmeOrbe.hpp"
#include "game/Armes/ArmeEclair.hpp"
#include "game/Armes/Shield.hpp"
#include "game/Armes/ArmeEpee.hpp"
#include "game/Armes/ArmeLivre.hpp"
#include "game/Armes/ArmeCrane.hpp"
#include "game/Armes/ArmeBalais.hpp"
#include "game/Armes/ArmeChaudron.hpp"
#include "game/Armes/ArmeElixir.hpp"

class CPlayState : public CGameState
{
public:

	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	CPlayState() { }
	~CPlayState() {Cleanup();}

	Player* player;
	Ennemi* ennemi;
	Map* map;
	std::vector<Arme*> atirail;
	sf::View* view;
};

#endif
