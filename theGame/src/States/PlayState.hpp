#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Audio.hpp>
#include <vector>

// States
#include "GameState.hpp"

// Core
#include "Player.hpp"
#include "Map.hpp"

// Ennemis
#include "Vague.hpp"
#include "CEnnemi.hpp"
#include "Enervax.hpp"
#include "Dragon.hpp"

// Arme
#include "Arme.hpp"
#include "ArmeFireball.hpp"
#include "ArmeHache.hpp"
#include "ArmeOrbe.hpp"
#include "ArmeEclair.hpp"
#include "ArmeShield.hpp"
#include "ArmeEpee.hpp"
#include "ArmeLivre.hpp"
#include "ArmeCrane.hpp"
#include "ArmeBalais.hpp"
#include "ArmeChaudron.hpp"
#include "ArmeElixir.hpp"

class CPlayState : public CGameState
{
public:

	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameEngine* game);
	void Update(CGameEngine* game);
	void Draw(CGameEngine* game);

	void CameraStop();

	CPlayState() { }
	~CPlayState() {Cleanup();}

	Player* player;
	Vague* wave;
	Map* map;
	ArmeShield * bouclier;
	std::vector<Arme*> atirail;
	sf::View* view;
	sf::Clock clock;
	float chrono;
	float volume = 100.;
	sf::Font font;
	sf::Text timer;
	sf::Music music;
	sf::Music musicBOSS;

	// SHREK 

    sf::Texture text_shrek;
    sf::Sprite sprite_shrek;
    Animation anim_shrek;
};

#endif
