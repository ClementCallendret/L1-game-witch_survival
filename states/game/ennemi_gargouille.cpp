#include "ennemi_gargouille.h"
#include <cmath>

gargouille::gargouille(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 2;
    PV = 1;
    degat = 1;
    xp = 2;
    name = "Gargouille";
    ratio = 0.5;
    if (!texture.loadFromFile("media/gargouille.png"))
    return;
    texture.loadFromFile("media/gargouille.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 4,sf::Vector2i(50,45),100,90,0.5,0.2);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(90,40); //pour la hitbox

}