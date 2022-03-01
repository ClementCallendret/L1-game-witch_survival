#ifndef UPGRADE_HPP
#define UPGRADE_HPP

#include "game/Player.h"
#include "game/Armes/Arme.hpp"
#include <vector>
#include <array>

class Upgrade 
{
private :
    Player* joueur;
    std::vector<Arme *> weapons;
    int choixSelected = 0;
    sf::Font police;
    std::array<sf::Text[2], 3> options;
    sf::Texture selecText;
    sf::Sprite selec;

public : 
    Upgrade(Player *joueur, std::vector<Arme *> weapons, sf::Vector2f position);
    void draw(sf::RenderWindow & window);
    void moveUp();
    void moveDown();

    void choose(){
        weapons[choixSelected]->upgrade();
    }
};

#endif