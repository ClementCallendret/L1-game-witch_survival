#include "gameengine.hpp"
#include "gamestate.hpp"

void CGameEngine::Init(const char* title, float width, float height)
{
	// Initialisation de la fenêtre SFML

	sf::VideoMode resolution(width, height);
	screen = new sf::RenderWindow(resolution, title);
	screen->setFramerateLimit(60);

	m_running = true;
}

void CGameEngine::Cleanup()
{
	// On vide toute la pile avant de fermer

	while ( !states.empty() ) {
		CGameState *s = states.top();
		delete s;
		states.pop();
	}

	screen->close();
}

void CGameEngine::ChangeState(CGameState* state) 
{
	// On vide la pile

	while ( !states.empty() ) {
		CGameState *s = states.top();
		delete s;
		states.pop();
	}

	// initialisation du nouvel état

	states.push(state);
	states.top()->Init();
}

void CGameEngine::PushState(CGameState* state)
{
	// Pause de l'état actuel

	if ( !states.empty() ) {
		states.top()->Pause();
	}

	// initialisation du nouvel état

	states.push(state);
	states.top()->Init();
}

void CGameEngine::PopState()
{
	// Cleanup de l'état actuel puis on dépile

	if ( !states.empty() ) {
		CGameState *s = states.top();
		delete s;
		states.pop();
	}

	// Reprise de l'état précedent

	if ( !states.empty() ) {
		states.top()->Resume();
	}
}


void CGameEngine::HandleEvents() 
{
	states.top()->HandleEvents(this); // Récupère les entrés pour l'état actif
}

void CGameEngine::Update() 
{
	states.top()->Update(this); // Actualise l'état actif
}

void CGameEngine::Draw() 
{
	states.top()->Draw(this); // Draw l'état actif
}

