#ifndef VAGUE_HPP
#define VAGUE_HPP

#include "Ennemis/CEnnemi.hpp"
#include "Ennemis/ChauveSouris.hpp"
#include "Ennemis/Chevalier.hpp"
#include "Ennemis/Villageoi.hpp"
#include "Ennemis/Fantome.hpp"
#include "Ennemis/Enervax.hpp"
#include "Ennemis/Dragon.hpp"
#include "Ennemis/Gargouille.hpp"
#include "Ennemis/Arbre.hpp"
#include "Ennemis/Loup.hpp"
#include "Ennemis/Geant.hpp"
#include <vector>

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