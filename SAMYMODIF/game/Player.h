#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp>
#include <vector>


class Player
{
private:
	static constexpr float speed = 3.;    //variable speed pour la vitesse de deplacement du joueur
	sf::Vector2f location = sf::Vector2f(600, 450);
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Player();
	short PV[100];
	float degats_subis(float f){return 0.;}; // ici on mettra les degats de l'arme ennemie lorsque elle touche le joueur
	float degats_infliges(float g){return 0.;}; // pareil qu'au dessus mais avec les degats de l'arme actuelle (il faudra donc le mettre a jour pendant le jeu)

	sf::Vector2f getPlayerPos() {return location;};
	void draw(sf::RenderWindow &window); // mettre ici si le niveau de l'arme est superieur a 1 on l'affiche et on l'update
	void inputs();
};

#endif