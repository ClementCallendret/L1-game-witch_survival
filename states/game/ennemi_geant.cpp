#include "ennemi_geant.h"

geant::geant(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 0.5;
<<<<<<< HEAD
    PV = 75;
=======
    PV = 100;
>>>>>>> 7601d4f619a448fbff6537633a58109dc7f0ef67
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