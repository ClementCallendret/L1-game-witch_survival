// afin de mieux comprendre comment les "states" fonctionnent ---> http://gamedevgeek.com/tutorials/managing-game-states-in-c/ <---
#include <stdio.h>
#include <sstream>
#include "playstate.hpp"
#include "upgradestate.hpp"
#include "pausestate.hpp"
#include "endstate.hpp"

void CPlayState::Init()
{
	player = new Player();
	map = new Map();
	view = new sf::View(sf::Vector2f(600, 450), sf::Vector2f(1600.0, 900.0));
	wave = new Vague(player, view);
	atirail = {new ArmeEpee(player, &wave->ensemble), new ArmeFireball(player, &wave->ensemble), new ArmeHache(player, &wave->ensemble), new ArmeEclair(player, &wave->ensemble), new ArmeOrbe(player, &wave->ensemble), new ArmeShield(player, &wave->ensemble), new ArmeLivre(player, &atirail), new ArmeCrane(player, &atirail), new ArmeBalais(player), new ArmeElixir(player), new ArmeChaudron(player, &atirail)};
	clock.restart();
	font.loadFromFile("media/Pixel.ttf");
	timer.setFont(font);
	timer.setCharacterSize(40);
	chrono = 0;

	music.openFromFile("media/Sounds/inGameMusic.ogg");
	music.play();

	text_shrek.loadFromFile("media/shrek.png");
    sprite_shrek.setTexture(text_shrek);
    anim_shrek = Animation(sprite_shrek, 9,sf::Vector2i(250,140),500,500,0.2,0.2);
    anim_shrek.sprite.setPosition(640, 2200);

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
				game->PushState(new CPauseState(this));
				break;
					
			case sf::Keyboard::M:
				music.pause();
				break;

			case sf::Keyboard::P:
				music.play();
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
	if (chrono < 300 && clock.getElapsedTime().asSeconds() + chrono >= 300)
	{
		float x = view->getCenter().x - 820;
		float y = rand() % 900;
		y += view->getCenter().y - 450;
		Ennemi *e = new enervax(player, sf::Vector2f(x, y));
		wave->ensemble.push_back(e);
	}
	if (chrono < 700 && clock.getElapsedTime().asSeconds() + chrono >= 700)
	{
		float x = view->getCenter().x - 820;
		float y = rand() % 900;
		y += view->getCenter().y - 450;
		Ennemi *e = new dragon(player, sf::Vector2f(x, y));
		wave->ensemble.push_back(e);
	}
	if (chrono < 1200 && clock.getElapsedTime().asSeconds() + chrono >= 1200) {
		music.stop();
		musicBOSS.setVolume(90.);
		musicBOSS.play();
	}
	chrono += clock.getElapsedTime().asSeconds();
	clock.restart();
	wave->level = int(chrono / 100 + 1);
	wave->intervalle = 100/float(chrono / 100 + 1);

	int min = int(chrono) / 60;
	int sec = int(chrono) % 60;
	std::stringstream txt;

	if (min < 10)
		txt << "0";
	txt << min << ":";
	if (sec < 10)
		txt << "0";
	txt << sec;

	timer.setString(txt.str());

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

	if (player->PV <= 0)
	{ // mort
		view->setCenter(800, 450);
		game->screen->setView(*view);
		int k = wave->kills;
		game->ChangeState(new CEndState(k, chrono, 0));
	}
	else if(player->newlevel){  // montée de niveau
		music.setVolume(50);
		game->PushState(new CUpgradeState(this));
	}
}

void CPlayState::Draw(CGameEngine *game)
{
	sf::Vector2f location = view->getCenter();

	sf::RectangleShape totXP(sf::Vector2f(1550, 15));
	totXP.setOrigin(775, 0);
	totXP.setPosition(location.x, location.y - 440);
	totXP.setFillColor(sf::Color(255, 255, 255, 127));
	totXP.setOutlineColor(sf::Color::Black);
	totXP.setOutlineThickness(2);

	sf::RectangleShape XPbar(sf::Vector2f(player->xp * 1550 / player->xpMax, 15));
	XPbar.setOrigin(775, 0);
	XPbar.setFillColor(sf::Color(20, 90, 180, 200));
	XPbar.setPosition(location.x, location.y - 440);

	timer.setPosition(location.x - 60, location.y - 380);

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

	game->screen->draw(anim_shrek.sprite);
	anim_shrek.update();

	player->draw(*(game->screen));
	(game->screen)->draw(totXP);
	(game->screen)->draw(XPbar);
	(game->screen)->draw(timer);

	game->screen->display();
}

void CPlayState::CameraStop()
{
	float posx;
	float posy;
	if (player->getPlayerPos().x < 2817)
		posx = player->getPlayerPos().x;
	else
		posx = 2817;

	if (player->getPlayerPos().x < 800)
		posx = 800;

	if (player->getPlayerPos().y < 2873)
		posy = player->getPlayerPos().y;
	else
		posy = 2873;

	if (player->getPlayerPos().y < 449)
		posy = 449;

	view->setCenter(posx, posy);
}
