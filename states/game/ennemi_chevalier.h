#ifndef ENNEMI_CHEVALIER
#define ENNEMI_CHEVALIER

#include "ennemi.h"
#include "Animation.hpp"

class chevalier: public Ennemi{
    public :
    chevalier(Player *j);
    sf::Texture nv_texture;
    sf::Sprite nv_sprite{nv_texture};
    void update();
    Animation anim = Animation(nv_sprite, 10,sf::Vector2i(25,25),52,52,1,0.3);
    //nb image, centre, hauteur, largeur, ratio taille, vitesse 0.3 
    //
    void draw(sf::RenderWindow & window);
};








#endif