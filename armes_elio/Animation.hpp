#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>

class Animation
{
    public:
    int nbtot_frames;
    float speed, num_frame;
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;

    Animation(sf::Sprite spt, int w, int h, int nb_frames, sf::Vector2i center, float speed = 1, int scale = 1);

    void update();
};

#endif