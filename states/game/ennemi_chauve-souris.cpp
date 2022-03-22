#include "ennemi_chauve-souris.h"
#include <cmath>

chauveS::chauveS(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 4;
    PV = 1;
    degat = 1;
    xp = 2;
    name = "Chauve-souris";
    ratio = 0.4;
    if (!texture.loadFromFile("media/chauve-souris.png"))
    return;
    texture.loadFromFile("media/chauve-souris.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 5,sf::Vector2i(72,70),140,140,1,0.1);
    //nom, nb image, milieu, hauteur, largeur, ratio, vitesse
    taille = sf::Vector2f(30,25);

}