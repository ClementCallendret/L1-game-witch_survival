#ifndef ENNEMI_GARGOUILLE
#define ENNEMI_GARGOUILLE

#include "CEnnemi.hpp"
#include "../Collision.hpp"

class gargouille : public Ennemi
{
public:
    gargouille(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 1.9;
        PV = 60;
        degat = 1;
        xp = 8;
        name = "Gargouille";
        ratio = 1.5;
        if (!Collision::CreateTextureAndBitmask(texture, "media/Flight.png"))
            throw "texture not loaded (gargouille)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 8, sf::Vector2i(75, 75), 150, 150, 1.5, 0.3);
        // nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
        taille = sf::Vector2f(90, 40); // pour la hitbox
    }
    ~gargouille() {}
};

#endif