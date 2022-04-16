#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "gameengine.hpp"

class CGameState
{
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(CGameEngine* game) = 0;
	virtual void Update(CGameEngine* game) = 0;
	virtual void Draw(CGameEngine* game) = 0;

	CGameState() { }
	virtual ~CGameState() {}
};

#endif

