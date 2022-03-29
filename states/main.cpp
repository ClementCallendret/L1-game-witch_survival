#include "gameengine.hpp"
#include "menustate.hpp"
#include <iostream>

int main ( int argc, char *argv[] )
{
	CGameEngine game;

	// initialisation de l'engine
	game.Init( "Witch SURVIVAL !!!!!!!!!" );

	// lchargement du premier état(menu)
	game.ChangeState(new CMenuState());

	// boucle principale
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}
	
	// cleanup de l'engine
	game.Cleanup();
	
	return 0;
}
