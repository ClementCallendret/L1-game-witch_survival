#include "ennemi_enervax.h"

enervax::enervax(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 0.8;
<<<<<<< HEAD
    PV = 3000;
    degat = 3;
    xp = 20;
=======
    PV = 500;
    degat = 30;
    xp = 30;
>>>>>>> 7601d4f619a448fbff6537633a58109dc7f0ef67
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