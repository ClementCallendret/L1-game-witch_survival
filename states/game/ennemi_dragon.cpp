#include "ennemi_dragon.h"
#include <cmath>

dragon::dragon(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 0.8;
    PV = 200;
    degat = 40;
    xp = 20;
    name = "Dragon";
    ratio = 1;
    if (!texture.loadFromFile("media/dragon.png"))
    return;
    texture.loadFromFile("media/dragon.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 11, sf::Vector2i(70,100),220,220,1,0.2);
    taille = sf::Vector2f(180,200); 

}