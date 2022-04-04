#ifndef UPGRADESTATE_HPP
#define UPGRADESTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.hpp"
#include "playstate.hpp"
#include "Upgrade.hpp"

class CUpgradeState : public CGameState
{
public:

	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	CUpgradeState(CPlayState* ps) : playstate(ps) { }
	~CUpgradeState() {Cleanup();}

private:

    CPlayState* playstate;
	sf::Texture* tex_bg;
	sf::Sprite* bg;
	sf::Music music;
	Upgrade* ameliorations;
};

#endif
