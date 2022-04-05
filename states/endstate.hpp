#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.hpp"

class CEndState : public CGameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	CEndState(int k, float t, bool w) : kill(k), time(t), win(w) { }
	~CEndState() {Cleanup();}

private:
	sf::RectangleShape bg;
	int kill;
	float time;
	bool win;
	sf::Font titlefont, txtfont;
	sf::Text title, kill_txt, time_txt, quitter_txt;
};

#endif

