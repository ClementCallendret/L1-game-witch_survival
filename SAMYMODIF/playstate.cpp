// afin de mieux comprendre come,t les "states" fonctionnet ---> http://gamedevgeek.com/tutorials/managing-game-states-in-c/ <---
#include <stdio.h>

#include "playstate.hpp"
#include "menustate.hpp"

CPlayState CPlayState::m_PlayState;

void CPlayState::Init()
{
	player = new Player();
	ennemi = new Ennemi(player);
	map = new Map();
	view = new sf::View(sf::Vector2f(600, 450), sf::Vector2f(1600.0, 900.0));
	baguette = new ArmeFireball(player);
	hache = new ArmeHache(player);
	orbe = new ArmeOrbe(player);
	thunder = new ArmeEclair(player);
	shield = new ArmeShield(player);
	epee = new ArmeEpee(player);

	printf("CPlayState Init\n");
}

void CPlayState::Cleanup()
{
	delete player;
	delete ennemi;
	delete map;
	delete view;
	delete baguette;
	delete hache;
	delete orbe;
	delete thunder;
	delete shield;
	delete epee;

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
				Pause();
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
	ennemi->inputs();
	view->setCenter(player->getPlayerPos());
	game->screen->setView(*view);
	baguette->update(ennemi);
	hache->update(ennemi);
	orbe->update(ennemi);
	thunder->update(ennemi);
	shield->update(ennemi);
	epee->update(ennemi);
}

void CPlayState::Draw(CGameEngine *game)
{
	game->screen->clear();
	(game->screen)->draw(*map);

	player->draw(*(game->screen));
	ennemi->draw(*(game->screen));

	baguette->draw(*(game->screen));
	hache->draw(*(game->screen));
	orbe->draw(*(game->screen));
	thunder->draw(*(game->screen));
	shield->draw(*(game->screen));
	epee->draw(*(game->screen));

	game->screen->display();
}
