#ifndef VAGUE_HPP
#define VAGUE_HPP
#include "ennemi.h"
#include "ennemi_chauve-souris.h"
#include "ennemi_chevalier.h"
#include "ennemi_villageois.h"
#include "ennemi_fantome.h"
#include "ennemi_enervax.h"
#include "ennemi_dragon.h"
#include "ennemi_gargouille.h"
#include "ennemi_arbre.h"
#include "ennemi_loup.h"
#include <vector>

class Vague {
public:
    Player *joueur;
    sf::View *vue;
    int intervalle, level, kills;
    std::vector<Ennemi *> ensemble;


    Vague(Player *j, sf::View* vue);
    virtual ~Vague();

    void spawn(sf::Vector2f pos);
    void update();
    void draw(sf::RenderWindow &window);

};


#endif