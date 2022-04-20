#ifndef ENNEMI_VILLAGEOIS
#define ENNEMI_VILLAGEOIS

#include "CEnnemi.hpp"

class villageois : public Ennemi
{
public:
    villageois(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 1;
        PV = 30;
        degat = 1;
        xp = 1;
        name = "villageois";
        ratio = 1;
        if (!texture.loadFromFile("media/pegu.png"))
            return;
        texture.loadFromFile("media/pegu.png");
        sprite.setTexture(texture);
        anim = Animation(sprite, 1, sf::Vector2i(15, 23), 47, 31, 1, 0);
        // nom, nb image, milieu, hauteur, largeur, ratio, vitesse
        taille = sf::Vector2f(31, 40);
    }
    ~villageois() {}
};

#endif