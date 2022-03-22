#ifndef VAGUE_HPP
#define VAGUE_HPP
#include "ennemi.h"
#include <vector>

class Vague {
public:
    Player *joueur;
    sf::View *vue;
    int intervalle;
    bool actif = false;
    std::vector<Ennemi *> ensemble;


    Vague(Player *j, sf::View* vue);
    virtual ~Vague();

    virtual void spawn(sf::Vector2f pos) = 0;
    void update();
    void draw(sf::RenderWindow &window);

};


#endif