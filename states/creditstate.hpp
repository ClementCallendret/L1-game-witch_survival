#ifndef CREDITSTATE_HPP
#define CREDITSTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.hpp"
#include "MainMenu.hpp"

class CCreditsState : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	CCreditsState() { }
	~CCreditsState() {Cleanup();}

private:
	sf::Texture tex_lane;
	sf::Sprite lane ;
	
	sf::Music music;
};

#endif

