#include "ennemi_dragon.h"

dragon::dragon(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 1;
    PV = 10000;
    degat = 5;
    xp = 30;
    name = "Dragon";
    ratio = 1;
    if (!texture.loadFromFile("media/dragon.png"))
    return;
    texture.loadFromFile("media/dragon.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 11, sf::Vector2i(70,100),220,220,1,0.2);
    taille = sf::Vector2f(180,200); 

}