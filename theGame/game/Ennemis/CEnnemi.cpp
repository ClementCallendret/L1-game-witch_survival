#include "CEnnemi.hpp"
#include "../Collision.hpp"
#include <cmath>

// Definition global du joueur
Ennemi::Ennemi(Player *j, sf::Vector2f loc) : joueur(j), location(loc) // Parametre que va prendre la classe joueur
{
}

void Ennemi::draw(sf::RenderWindow &window) // Dessin de l'ennemi
{
    anim.sprite.setPosition(location.x, location.y); // deplacer l'image
    anim.update();
    window.draw(anim.sprite);
}

void Ennemi::update() // Deplacement de l'ennemi -> Objectif : suivre le joueur
{
    float deplaX, deplaY, angle; // Definition variable pour les calculs

    float posxP = joueur->getPlayerPos().x; // On récupère les positions du joueur en x et en y
    float posyP = joueur->getPlayerPos().y; // Elles correspondent au centre de l'ennemi

    float posxE = location.x; // Idem pour l'ennemi
    float posyE = location.y;

    deplaX = posxP - posxE; // Début du calcul de fou
    deplaY = posyP - posyE;

    if (deplaX < 0.000001 && deplaX > 0.000001)
    { // Securite car deplaX va être un diviseur donc il ne faut pas qu'il soit égale à 0
        if (deplaX > 0)
        {                  // si deplaX est positif
            deplaX = 0.01; //
        }
        else
        {
            deplaX = -0.01;
        }
    }

    angle = atan(deplaY / deplaX); // Calcul de l'angle que l'ennemi doit prendre

    if (posxE < posxP)
    { // si position ennemi < position joueur
        location.x += speed * cos(angle);
        location.y += speed * sin(angle);
        anim.sprite.setScale(-ratio, ratio);
    }

    else
    { // si position ennemi >= position joueur
        location.x -= speed * cos(angle);
        location.y -= speed * sin(angle);
        anim.sprite.setScale(ratio, ratio);
    }
    
    if(Collision::PixelPerfectTest(anim.sprite, joueur->anim.sprite)){
        if (!joueur->bouclier)
        joueur->PV -= degat; // On enlève des pv au joueur
    }
}
