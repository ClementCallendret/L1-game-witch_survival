#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include <SFML/Graphics.hpp>
#include "gamestate.hpp"
#include "playstate.hpp"

class CPauseState : public CGameState
{
public:

	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	CPauseState(CPlayState* ps) : playstate(ps) { }
	~CPauseState() {Cleanup();}

private:

    CPlayState* playstate;
	sf::Texture tex_bg;
	sf::Sprite bg;

	int choixSelected = 0;
    sf::Font titlefont;
	sf::Font choixfont;
	sf::Text title;
    std::array<sf::Text, 2> options;
    sf::Texture selecText;
    sf::Sprite selec;
};

#endif