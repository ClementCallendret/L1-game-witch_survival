#include "ennemi_dragon.h"
#include <cmath>

dragon::dragon(Player* j, sf::Vector2f loc): Ennemi(j, loc){
<<<<<<< HEAD
    speed = 0.9;
    PV = 1000;
    degat = 5;
    xp = 5;
=======
    speed = 0.8;
    PV = 200;
    degat = 40;
    xp = 20;
>>>>>>> f6b9c168e4929d1e89e90ec52e6b5d0065b6616f
    name = "Dragon";
    ratio = 1;
    if (!texture.loadFromFile("media/dragon.png"))
    return;
    texture.loadFromFile("media/dragon.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 11, sf::Vector2i(70,100),220,220,1,0.2);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(180,200); //pour la hitbox

}