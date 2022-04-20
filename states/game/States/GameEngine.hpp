#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <SFML/Graphics.hpp>
#include <stack>

class CGameState;

class CGameEngine
{
public:

	void Init(const char* title, float width=1600, float height=900);
	void Cleanup();

	void ChangeState(CGameState* state); // vide la pile et change d'état
	void PushState(CGameState* state);   // empile un état
	void PopState();					 // dépile un état

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	sf::RenderWindow* screen;
	
private:

	std::stack<CGameState*> states; // La pile des états 
	bool m_running;
};

#endif
