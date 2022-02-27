#include "gameengine.hpp"
#include "menustate.hpp"
#include <iostream>

int main ( int argc, char *argv[] )
{
	CGameEngine game;

	// initialize the engine
	game.Init( "Engine Test v1.0" );

	// load the menu
	game.ChangeState(new CMenuState());

	// main loop
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}
	
	// cleanup the engine
	game.Cleanup();

	return 0;
}
