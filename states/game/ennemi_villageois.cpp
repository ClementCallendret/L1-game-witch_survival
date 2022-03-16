#include "ennemi_villageois.h"
#include <stdio.h>
#include <cmath>

villageois::villageois(Player* j):Ennemi(j){
    speed = 1;
    degat = 1;
    xp = 1;
    name = "villageois";
    if (!texture.loadFromFile("media/output-onlinepngtools.png"))
    return;
    sprite.setTexture(texture);
    location = sf::Vector2f(0,0);
    taille = sf::Vector2f(50,50);
}

