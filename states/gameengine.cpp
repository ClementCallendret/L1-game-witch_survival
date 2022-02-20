#include <iostream>

#include "gameengine.hpp"
#include "gamestate.hpp"

void CGameEngine::Init(const char* title, int width, int height, int bpp, bool fullscreen)
{

	// initialize SDL
	sf::VideoMode resolution(width, height);
	screen = new sf::RenderWindow(resolution, title);
	screen->setFramerateLimit(60);

	m_fullscreen = fullscreen;
	m_running = true;

	std::cout << "CGameEngine Init" << std::endl ;
}

void CGameEngine::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() ) {
		states.top()->Cleanup();
		states.pop();
	}

	// switch back to windowed mode so other 
	// programs won't get accidentally resized
	if ( m_fullscreen ) {
		screen->setSize(sf::Vector2u(1200, 800));
	}

	screen->close();
	printf("CGameEngine Cleanup\n");
}

void CGameEngine::ChangeState(CGameState* state) 
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.top()->Cleanup();
		states.pop();
	}

	// store and init the new state
	states.push(state);
	states.top()->Init();
	printf("CGameEngine ChangeState done\n");
}

void CGameEngine::PushState(CGameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.top()->Pause();
	}

	// store and init the new state
	states.push(state);
	states.top()->Init();
}

void CGameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.top()->Cleanup();
		states.pop();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.top()->Resume();
	}
}


void CGameEngine::HandleEvents() 
{
	// let the state handle events
	states.top()->HandleEvents(this);
}

void CGameEngine::Update() 
{
	// let the state update the game
	states.top()->Update(this);
}

void CGameEngine::Draw() 
{
	// let the state draw the screen
	states.top()->Draw(this);
}
