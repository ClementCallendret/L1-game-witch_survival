#include "ennemi_enervax.h"
#include <cmath>

enervax::enervax(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 0.8;
<<<<<<< HEAD
    PV = 80;
    degat = 5;
    xp = 5;
=======
    PV = 500;
    degat = 30;
    xp = 30;
>>>>>>> f6b9c168e4929d1e89e90ec52e6b5d0065b6616f
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