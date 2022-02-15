/*#pragma once

#include <SFML/Graphics.hpp>

#ifndef TITREDUJEU_H
#define TITREDUJEU_H



class background 
{
public:
    bool sapasse; // pour passer au travers ou pas
    sf::Vector2f pos; // Vector2f contient des valeurs pour x et y, on l'appelle "pos" pour "position"
    sf::Texture texture; // Il nous faut bien une texture pour l'afficher
    sf::Sprite sprite; // La texture va etre attachée au sprite tout le temps ; il fait reference au "texture"

    GameTile(std::string,float, float, bool) // La fonction pour le constructeur. "string" --> pour le nome de la texture / les deux "float" --> pour x et y / le "bool" --> pour savoir si c'est passable. 
    bool setUpSprite(std::string); // cela va changer et s'actualiser quand le joueur et les ennemis vont bouger



};


#endif
*/