
#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <SFML/Graphics.hpp>
#include <stack>

using namespace std;

class CGameState;

class CGameEngine
{
public:

	void Init(const char* title, float width=1600, float height=900, int bpp=0, bool fullscreen=false);
	void Cleanup();

	void ChangeState(CGameState* state);
	void PushState(CGameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	sf::RenderWindow* screen;
	
private:
	// the stack of states
	stack<CGameState*> states;

	bool m_running;
	bool m_fullscreen;
};

#endif
