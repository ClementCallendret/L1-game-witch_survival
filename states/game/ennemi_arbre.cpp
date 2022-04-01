#include "ennemi_arbre.h"
#include <cmath>

arbre::arbre(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 0.7;
    PV = 40;
    degat = 2;
    xp = 2;
    name = "Arbre";
    ratio = 0.2;
    if (!texture.loadFromFile("media/arbre.png"))
    return;
    texture.loadFromFile("media/arbre.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 6,sf::Vector2i(145,140),290,280,0.2,0.2);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(30,30); //pour la hitbox

}