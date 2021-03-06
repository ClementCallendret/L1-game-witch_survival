#ifndef UPGRADESTATE_HPP
#define UPGRADESTATE_HPP

#include <SFML/Audio.hpp>
#include "GameState.hpp"
#include "PlayState.hpp"
#include "../Upgrade.hpp"

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
