// afin de mieux comprendre come,t les "states" fonctionnet ---> http://gamedevgeek.com/tutorials/managing-game-states-in-c/ <---
#include <stdio.h>
#include "playstate.hpp"
#include "menustate.hpp"
#include "upgradestate.hpp"

void CPlayState::Init()
{
	player = new Player();
	map = new Map();
	view = new sf::View(sf::Vector2f(600, 450), sf::Vector2f(1600.0, 900.0));
	wave = new Vague(player, view);
	atirail = {new ArmeEpee(player, &wave->ensemble), new ArmeFireball(player, &wave->ensemble), new ArmeHache(player, &wave->ensemble), new ArmeEclair(player, &wave->ensemble), new ArmeOrbe(player, &wave->ensemble), new ArmeShield(player, &wave->ensemble), new ArmeLivre(player, &atirail), new ArmeCrane(player, &atirail), new ArmeBalais(player), new ArmeElixir(player), new ArmeChaudron(player, &atirail)};

	printf("CPlayState Init\n");
}

void CPlayState::Cleanup()
{
	delete player;
	delete wave;
	delete map;
	delete view;

	for (auto a : atirail)
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
	for (auto a : atirail)
	{
		if (a->m_level > 0)
		{
			a->update();
		}
	}
	wave->update();

	
	CameraStop(); // camera au niveau du joueur qui va le suivre
	game->screen->setView(*view);

	if(player->newlevel){
		game->PushState(new CUpgradeState(this));
	}
}

void CPlayState::Draw(CGameEngine *game)
{
	game->screen->clear();
	(game->screen)->draw(*map);

	wave->draw(*(game->screen));
	for (auto a : atirail)
	{
		if (a->m_level > 0)
		{
			a->draw(*game->screen);
		}
	}
	player->draw(*(game->screen));

	game->screen->display();
}

void CPlayState::CameraStop() {
	float posx; 
	float posy;
	if (player->getPlayerPos().x < 2753) 
	posx =player->getPlayerPos().x;
	else
	posx = 2753;

	if (player->getPlayerPos().x < -100) 
	posx =-100;

	if (player->getPlayerPos().y < 2053) 
	posy =player->getPlayerPos().y;
	else
	posy = 2053; 

	if (player->getPlayerPos().y < -500) 
	posy =-500;

	view->setCenter(posx, posy);
}