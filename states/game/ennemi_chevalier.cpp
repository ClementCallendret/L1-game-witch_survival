#include "ennemi_chevalier.h"
#include <cmath>

chevalier::chevalier(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 2;
<<<<<<< HEAD
    PV = 35;
=======
    PV = 30;
>>>>>>> f6b9c168e4929d1e89e90ec52e6b5d0065b6616f
    degat = 1;
    xp = 2;
    name = "chevalier";
    ratio = 1;
    if (!texture.loadFromFile("media/chevalier.png"))
    return;
    texture.loadFromFile("media/chevalier.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 10,sf::Vector2i(25,25),52,52,1,0.3);
    //nom, nb image, milieu, hauteur, largeur, ratio, vitesse
    taille = sf::Vector2f(50,50);

}
