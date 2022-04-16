#include "ennemi_fantome.h"
#include <cmath>

fantome::fantome(Player* j, sf::Vector2f loc): Ennemi(j, loc){
<<<<<<< HEAD
    speed = 2.1;
    PV = 55;
    degat = 2;
    xp = 5;
=======
    speed = 1.5;
    PV = 25;
    degat = 2;
    xp = 2;
>>>>>>> 033773e6cdb2862e935dcf49b7944595da5f4261
    name = "Fantome";
    ratio = 0.2;
    if (!texture.loadFromFile("media/fantome.png"))
    return;
    texture.loadFromFile("media/fantome.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 6,sf::Vector2i(95,200),190,400,0.2,0.08);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(35,90); //pour la hitbox

}