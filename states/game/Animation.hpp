#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>

class Animation
{
    public:
    sf::Sprite sprite;
    int nbtot_frames;
    float speed, num_frame;
    std::vector<sf::IntRect> frames;

    Animation() {};
    Animation(sf::Sprite spt, int nb_frames, sf::Vector2i center, int w, int h, float scale = 1, float speed = 1);

    void update();
};

#endif