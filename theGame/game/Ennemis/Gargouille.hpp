#ifndef ENNEMI_GARGOUILLE
#define ENNEMI_GARGOUILLE

#include "CEnnemi.hpp"

class gargouille : public Ennemi
{
public:
    gargouille(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 1.9;
        PV = 60;
        degat = 1;
        xp = 2;
        name = "Gargouille";
        ratio = 0.5;
        if (!Collision::CreateTextureAndBitmask(texture, "media/gargouille.png"))
            throw "texture not loaded (gargouille)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 4, sf::Vector2i(50, 45), 100, 90, 0.5, 0.2);
        // nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
        taille = sf::Vector2f(90, 40); // pour la hitbox
    }
    ~gargouille() {}
};

#endif