#include "Animation.hpp"

/* Le constructeur prend en parametre le sprite de l'objet, la largeur et la hauteur d'une animation,
le nombre de frames de l'animation, l'origine du projectile, et éventuellement l'échelle */

Animation::Animation(sf::Sprite spt, int nbf, sf::Vector2i center, int w, int h, int scl, float spd) : sprite(spt), nbtot_frames(nbf), speed(spd)
{
    for (int i = 0; i < nbf; i++)
        frames.push_back(sf::IntRect(i * w, 0, w, h));

    num_frame = 0;
    sprite.setTextureRect(frames[0]);
    sprite.setOrigin(center.x, center.y);
    sprite.scale(scl, scl);
}

// Permet de passer a l'animation suivante

void Animation::update()
{
    num_frame += speed;
    if(num_frame >= nbtot_frames)
        num_frame -= nbtot_frames;
    sprite.setTextureRect(frames[(int)num_frame]);
}