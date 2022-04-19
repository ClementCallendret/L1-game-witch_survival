#include "ennemi_loup.h"

loup::loup(Player* j, sf::Vector2f loc): Ennemi(j, loc){
<<<<<<< HEAD
    speed = 1.75;
    PV = 70;
    degat = 1.5;
    xp = 2;
=======
    speed = 2;
    PV = 80;
    degat = 10;
    xp = 5;
>>>>>>> 7601d4f619a448fbff6537633a58109dc7f0ef67
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