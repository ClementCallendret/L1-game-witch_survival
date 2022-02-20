#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SFML/Graphics.hpp>
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

	static CMenuState* Instance() {
		return &m_MenuState;
	}

protected:
	CMenuState() { }

private:
	static CMenuState m_MenuState;
	sf::Texture* tex_bg;
	sf::Sprite* bg ;
	MainMenu* menu;
};

#endif

