#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "deplacement.h"

namespace sf
{
	class RenderWindow;
	
}

class Player
{
private:
	static constexpr float speed = 0.25f;    //variable speed pour la vitesse de deplacement du joueur
	deplacement2D location = deplacement2D(600, 450);
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Player();
	short PV[100];
	float degats_subis(float f){return 0.;}; // ici on mettra les degats de l'arme ennemie lorsque elle touche le joueur
	float degats_infliges(float g){return 0.;}; // pareil qu'au dessus mais avec les degats de l'arme actuelle (il faudra donc le mettre a jour pendant le jeu)

	sf::Vector2f getPlayerPos();
	void draw(sf::RenderWindow &window);
	void inputs();
};

#endif