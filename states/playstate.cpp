// afin de mieux comprendre come,t les "states" fonctionnet ---> http://gamedevgeek.com/tutorials/managing-game-states-in-c/ <---
#include <stdio.h>
#include "playstate.hpp"
#include "menustate.hpp"
#include "upgradestate.hpp"

void CPlayState::Init()
{
	player = new Player();
	ennemi = new villageois(player);
	map = new Map();
	view = new sf::View(sf::Vector2f(600, 450), sf::Vector2f(1600.0, 900.0));
	atirail =  {new ArmeEpee(player), new ArmeFireball(player), new ArmeHache(player), new ArmeEclair(player), new ArmeOrbe(player), new ArmeShield(player), new ArmeLivre(player, &atirail), new ArmeCrane(player, &atirail), new ArmeBalais(player), new ArmeElixir(player), new ArmeChaudron(player, &atirail)};
	printf("CPlayState Init\n");
}

void CPlayState::Cleanup()
{
	delete player;
	delete ennemi;
	delete map;
	delete view;

	for(auto a : atirail)
	{
		delete a;
	}

	printf("CPlayState Cleanup\n");
}

void CPlayState::Pause()
{
	printf("CPlayState Pause\n");
}

void CPlayState::Resume()
{
	printf("CPlayState Resume\n");
}

void CPlayState::HandleEvents(CGameEngine *game)
{
	sf::Event event;

	if (game->screen->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			game->Quit();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				game->PushState(new CUpgradeState(this));
				break;
			default:
			
				break;
			}
			break;
		default:
			break;
		}
	}
}

void CPlayState::Update(CGameEngine *game)
{

	player->inputs();
	ennemi->update();

	view->setCenter(player->getPlayerPos());
	game->screen->setView(*view);

	for(auto a : atirail)
	{
		if(a->m_level > 0)
		{
			a->update(ennemi);
		}
	}
}

void CPlayState::Draw(CGameEngine *game)
{
	game->screen->clear();
	(game->screen)->draw(*map);

	player->draw(*(game->screen));
	ennemi->draw(*(game->screen));

	for(auto a : atirail)
	{
		if(a->m_level > 0)
		{
			a->draw(*game->screen);
		}
	}

	game->screen->display();
}
