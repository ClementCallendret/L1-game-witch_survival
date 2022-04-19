#include "ennemi_chevalier.h"

chevalier::chevalier(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 2;
<<<<<<< HEAD
    PV = 45;
=======
    PV = 30;
>>>>>>> 7601d4f619a448fbff6537633a58109dc7f0ef67
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
