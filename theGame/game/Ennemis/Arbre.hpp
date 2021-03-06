#ifndef ENNEMI_ARBRE
#define ENNEMI_ARBRE

#include "CEnnemi.hpp"

class arbre : public Ennemi
{
public:
    arbre(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 0.7;
        PV = 70;
        degat = 1;
        xp = 5;
        name = "Arbre";
        ratio = 0.2;
        if (!Collision::CreateTextureAndBitmask(texture, "media/arbre.png"))
            return;
        sprite.setTexture(texture);                                              // application de la texture
        anim = Animation(sprite, 6, sf::Vector2i(145, 140), 290, 280, 0.2, 0.2); // Animation de l'ennemi
        // nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
        taille = sf::Vector2f(30, 30); // pour la hitbox
    }
    ~arbre() {}
};

#endif