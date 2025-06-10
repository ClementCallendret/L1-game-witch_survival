#ifndef ENNEMI_CHAUVES
#define ENNEMI_CHAUVES

#include "CEnnemi.hpp"

// Core
#include "Collision.hpp"

class chauveS : public Ennemi
{
public:
    chauveS(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 2;
        PV = 30;
        degat = 0.5;
        xp = 2;
        name = "Chauve-souris";
        ratio = 0.4;
        if (!Collision::CreateTextureAndBitmask(texture, "media/chauve-souris.png"))
            throw "texture not loaded (chauve souris)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 5, sf::Vector2i(72, 70), 140, 140, 1, 0.1);
        // nom, nb image, milieu, hauteur, largeur, ratio, vitesse
        taille = sf::Vector2f(30, 25);
    }
    ~chauveS() {}
};

#endif