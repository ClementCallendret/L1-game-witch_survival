#include "ennemi_geant.h"
#include <cmath>

geant::geant(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 0.5;
    PV = 10;
    degat = 5;
    xp = 5;
    name = "Geant";
    ratio = 0.4;
    if (!texture.loadFromFile("media/geant.png"))
    return;
    texture.loadFromFile("media/geant.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 40,sf::Vector2i(102,80),160,204,1,0.5);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(80,102); //pour la hitbox

}