#include "ennemi_gargouille.h"

gargouille::gargouille(Player* j, sf::Vector2f loc): Ennemi(j, loc){
<<<<<<< HEAD
    speed = 1.9;
    PV = 60;
    degat = 1;
    xp = 2;
=======
    speed = 2.5;
    PV = 20;
    degat = 3;
    xp = 3;
>>>>>>> 7601d4f619a448fbff6537633a58109dc7f0ef67
    name = "Gargouille";
    ratio = 0.5;
    if (!texture.loadFromFile("media/gargouille.png"))
    return;
    texture.loadFromFile("media/gargouille.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 4,sf::Vector2i(50,45),100,90,0.5,0.2);
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(90,40); //pour la hitbox

}