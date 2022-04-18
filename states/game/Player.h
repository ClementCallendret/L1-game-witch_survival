#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Vector2f location = sf::Vector2f(1100, 850);
	sf::Texture texture;
	sf::Sprite sprite;

public:
    short PV = 100;
	float xp = 0, xpMax = 10;
	int pvMax = 100, sens = -1;
	float speed = 3.;
	bool newlevel;

	Player();
	
	float degats_subis(float f){return 0.;}; // ici on mettra les degats de l'arme ennemie lorsque elle touche le joueur
	float degats_infliges(float g){return 0.;}; // pareil qu'au dessus mais avec les degats de l'arme actuelle (il faudra donc le mettre a jour pendant le jeu)

	void prendreXP(float n);
	void heal(float n);

	sf::Vector2f getPlayerPos() {return location;};
	void draw(sf::RenderWindow &window); // mettre ici si le niveau de l'arme est superieur a 1 on l'affiche et on l'update
	void inputs();
	bool levelup(){
		return newlevel;
	}
};

#endif
