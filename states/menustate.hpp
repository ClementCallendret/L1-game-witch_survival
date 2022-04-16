#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.hpp"
#include "MainMenu.hpp"

class CMenuState : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	CMenuState() { }
	~CMenuState() {Cleanup();}
	
	float volume = 100.;

private:
	sf::Texture tex_bg;
	sf::Sprite bg ;
	MainMenu* menu; // classe qui gère les textes et les options
	
	sf::Music music;
};

#endif

