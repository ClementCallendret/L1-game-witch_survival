#ifndef ENNEMI_CHEVALIER
#define ENNEMI_CHEVALIER

#include "CEnnemi.hpp"

class chevalier : public Ennemi
{
public:
    chevalier(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 2;
        PV = 50;
        degat = 1;
        xp = 2;
        name = "chevalier";
        ratio = 1;
        if (!Collision::CreateTextureAndBitmask(texture, "media/chevalier.png"))
            throw "texture not loaded (chevalier)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 10, sf::Vector2i(25, 25), 52, 52, 1, 0.3);
        // nom, nb image, milieu, hauteur, largeur, ratio, vitesse
        taille = sf::Vector2f(50, 50);
    }
    ~chevalier() {}
};

#endif