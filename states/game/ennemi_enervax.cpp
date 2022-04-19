#include "ennemi_enervax.h"

enervax::enervax(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 0.8;
    PV = 3000;
    degat = 3;
    xp = 40;
    name = "Enervax";
    ratio = 0.4;
    if (!texture.loadFromFile("media/enervax.png"))
    return;
    texture.loadFromFile("media/enervax.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 6,sf::Vector2i(130,145),260,290,0.4,0.1);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(90,100); //pour la hitbox

}