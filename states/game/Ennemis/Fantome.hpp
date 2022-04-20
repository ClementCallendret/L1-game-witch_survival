#ifndef ENNEMI_FANTOME
#define ENNEMI_FANTOME

#include "CEnnemi.hpp"

class fantome : public Ennemi
{
public:
    fantome(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 2.1;
        PV = 55;
        degat = 2;
        xp = 5;
        name = "Fantome";
        ratio = 0.2;
        if (!texture.loadFromFile("media/fantome.png"))
            return;
        texture.loadFromFile("media/fantome.png");
        sprite.setTexture(texture);
        anim = Animation(sprite, 6, sf::Vector2i(95, 200), 190, 400, 0.2, 0.08);
        // nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
        taille = sf::Vector2f(35, 90); // pour la hitbox
    }
    ~fantome() {}
};

#endif