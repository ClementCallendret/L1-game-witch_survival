#include "Arme.hpp"
#include "ennemi.h"
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

// oui, ca fait beaucoup mais on le fait qu'une fois par arme donc ok ca va*

Arme::Arme(float d, float vP, int nP, float tP, int vieP, std::string nom, sf::Time cool, ModeDeTir mDT, Animation &a, Player* j) : degats(d), vitesseProjectile(vP), nombreProjectile(nP), tailleProjectile(tP), vieProjectile(vieP), nomArme(nom), cooldown(cool), mdt(mDT), anim(a), joueur(j)
{
    clock.restart();
}

void Arme::tirer(Ennemi &cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new Bullet(joueur->getPlayerPos().x, joueur->getPlayerPos().y, tailleProjectile, degats, vitesseProjectile, vieProjectile, cible, anim, mdt, joueur);
        ensemble.push_back(b);
        clock.restart();
    }
}

void Arme::update(Ennemi &cible)
{
    tirer(cible);
    /* for (auto b : ensemble) // On verifie si un projectile touche un enemi
    {
        if (b->collision(&cible))
        {
            b->hit(cible);
        }
    } */

    for (auto i = std::begin(ensemble); i != std::end(ensemble);)
    {
        Bullet *e = *i;
        e->update(); // on fait bouger les projectiles grace a la fct update

        if (e->getBulLife() == 0) // on efface les projectiles qui sont "mort"
        {
            i = ensemble.erase(i);
            delete e;
        }
        else
            i++;
    }
}

void Arme::draw(sf::RenderWindow & window){
    for (auto b : ensemble)
        {
            b->draw(window);
        }
}