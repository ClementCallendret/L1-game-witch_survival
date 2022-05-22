#ifndef ENNEMI_GEANT
#define ENNEMI_GEANT

#include "CEnnemi.hpp"
#include "../Collision.hpp"

class geant : public Ennemi
{
public:
    geant(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 0.65;
        PV = 100;
        degat = 5;
        xp = 15;
        name = "Geant";
        ratio = 0.4;
        if (!Collision::CreateTextureAndBitmask(texture, "media/geant.png"))
            throw "texture not loaded (geant)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 20, sf::Vector2i(102, 80), 160, 204, 1, 0.5);
        // nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
        taille = sf::Vector2f(80, 102); // pour la hitbox
    }
    ~geant() {}
};

#endif