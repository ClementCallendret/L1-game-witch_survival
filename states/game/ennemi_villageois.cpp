#include "ennemi_villageois.h"
#include <stdio.h>
#include <cmath>

villageois::villageois(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 1;
    PV = 30;
    degat = 1;
    xp = 1;
    name = "villageois";
    if (!texture.loadFromFile("media/chevalier-image.png"))
    return;
    sprite.setTexture(texture);
    location = sf::Vector2f(0,0);
    taille = sf::Vector2f(50,50);
}

