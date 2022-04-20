#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Audio.hpp>
#include <vector>

#include "GameState.hpp"
#include "../Player.hpp"
#include "../Map.hpp"
#include "../Vague.hpp"

#include "../Ennemis/CEnnemi.hpp"
#include "../Ennemis/Enervax.hpp"
#include "../Ennemis/Dragon.hpp"

#include "../Armes/Arme.hpp"
#include "../Armes/ArmeFireball.hpp"
#include "../Armes/ArmeHache.hpp"
#include "../Armes/ArmeOrbe.hpp"
#include "../Armes/ArmeEclair.hpp"
#include "../Armes/ArmeShield.hpp"
#include "../Armes/ArmeEpee.hpp"
#include "../Armes/ArmeLivre.hpp"
#include "../Armes/ArmeCrane.hpp"
#include "../Armes/ArmeBalais.hpp"
#include "../Armes/ArmeChaudron.hpp"
#include "../Armes/ArmeElixir.hpp"

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
