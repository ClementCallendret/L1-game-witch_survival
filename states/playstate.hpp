#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Graphics.hpp>
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

	static CPlayState* Instance() {
		return &m_PlayState;
	}

protected:
	CPlayState() { }

private:
	static CPlayState m_PlayState;
	Player* player;
	Ennemi* ennemi;
	Map* map;
    Arme* baguette; 
	Arme* hache;
	Arme* orbe;
	Arme* thunder;
	Arme* shield;
	Arme* epee;
	sf::View* view;
};

#endif
