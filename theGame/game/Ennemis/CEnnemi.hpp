#ifndef ENNEMI_H
#define ENNEMI_H

#include "../Player.hpp"
#include "../Animation.hpp"
#include <SFML/Graphics.hpp>

class Ennemi // Def de la classe Ennemi
// Paramètre propre a chaque ennemi
{
protected: // Caracteristiques des ennemis
	Player *joueur;
	float speed, xp, ratio;
	
	sf::Vector2f location;
	sf::Vector2f taille;
	std::string name;

public:
	float degat;
	int PV;
	sf::Texture texture;
	sf::Sprite sprite;
	Animation anim;

	Ennemi(Player *j, sf::Vector2f loc); // Paramètre que l'ennemi utilisera
	virtual ~Ennemi()
	{ // On le met en virtual car c'est une classe de classe
		joueur->prendreXP(xp);
	}

	void update();						 // update pour le déplacement des ennemis
	void draw(sf::RenderWindow &window); // Dessin de l'ennemi avec son sprite				 // on check les collisions entre l'ennemi et le player

	sf::Vector2f getEnnemiPos()
	{
		return sf::Vector2f(location.x, location.y); // on recup la position de l'ennemi
	};

	sf::Vector2f getEnnemiTaille()
	{
		return sf::Vector2f(taille.x, taille.y); // On recup la taille de l'ennemi
	};
};

#endif
