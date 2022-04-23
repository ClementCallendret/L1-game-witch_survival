#ifndef ENNEMI_LOUP
#define ENNEMI_LOUP

#include "CEnnemi.hpp"

class loup : public Ennemi
{
public:
    loup(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 1.75;
        PV = 70;
        degat = 1.5;
        xp = 2;
        name = "Loup";
        ratio = 0.3;
        if (!Collision::CreateTextureAndBitmask(texture, "media/loup.png"))
            throw "texture not loaded (loup)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 8, sf::Vector2i(80, 115), 160, 230, 0.3, 0.2);
        // nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
        taille = sf::Vector2f(75, 110); // pour la hitbox
    }
    ~loup() {}
};

#endif