#include "ennemi_loup.h"
#include <cmath>

loup::loup(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 2;
<<<<<<< HEAD
    PV = 70;
    degat = 2;
    xp = 2;
=======
    PV = 80;
    degat = 10;
    xp = 5;
>>>>>>> 033773e6cdb2862e935dcf49b7944595da5f4261
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