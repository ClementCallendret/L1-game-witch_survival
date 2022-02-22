#include "ennemi_villageois.h"
#include <stdio.h>
#include <cmath>

villageois::villageois(Player* j):Ennemi(j){
    speed = 1;
    degat = 1;
    if (!texture.loadFromFile("media/diable.png"))
    return;
    sprite.setTexture(texture);
    location = sf::Vector2f(0,0);
    taille = sf::Vector2f(256,256);
}
