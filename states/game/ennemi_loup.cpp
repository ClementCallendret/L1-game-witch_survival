#include "ennemi_loup.h"
#include <cmath>

loup::loup(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 2;
    PV = 2;
    degat = 2;
    xp = 2;
    name = "Loup";
    ratio = 0.3;
    if (!texture.loadFromFile("media/loup.png"))
    return;
    texture.loadFromFile("media/loup.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 8,sf::Vector2i(80,115),160,230,0.3,0.2);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(75,110); //pour la hitbox

}