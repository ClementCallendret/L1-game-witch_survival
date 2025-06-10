#ifndef VAGUE_HPP
#define VAGUE_HPP

#include <vector>

#include "CEnnemi.hpp"
#include "ChauveSouris.hpp"
#include "Chevalier.hpp"
#include "Villageoi.hpp"
#include "Fantome.hpp"
#include "Enervax.hpp"
#include "Dragon.hpp"
#include "Gargouille.hpp"
#include "Arbre.hpp"
#include "Loup.hpp"
#include "Geant.hpp"


class Vague {
public:
    Player *joueur;
    sf::View *vue;
    float intervalle;
    int level, kills;
    std::vector<Ennemi *> ensemble;


    Vague(Player *j, sf::View* vue);
    virtual ~Vague();

    void spawn(sf::Vector2f pos);
    void update();
    void draw(sf::RenderWindow &window);

};


#endif