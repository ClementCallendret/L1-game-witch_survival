#ifndef ENNEMI_FANTOME
#define ENNEMI_FANTOME

#include "CEnnemi.hpp"
#include "../Collision.hpp"

class fantome : public Ennemi
{
public:
    fantome(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 2;
<<<<<<< HEAD
        PV = 100;
=======
        PV = 80;
>>>>>>> c21e5f28f9792c8e5b70902bd1b5f8b7a9b1e6da
        degat = 2;
        xp = 7.5;
        name = "Fantome";
        ratio = 0.2;
        if (!Collision::CreateTextureAndBitmask(texture, "media/fantome.png"))
            throw "texture not loaded (fantome)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 6, sf::Vector2i(95, 200), 190, 400, 0.2, 0.08);
        // nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
        taille = sf::Vector2f(35, 90); // pour la hitbox
    }
    ~fantome() {}
};

#endif