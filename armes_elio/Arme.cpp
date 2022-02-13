#include "Arme.hpp"
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

// oui, ca fait beaucoup mais on le fait qu'une fois par arme donc ok ca va*

Arme::Arme(float d, float vP, int nP, float tP, int vieProjectile, std::string nom, int cool, ModeDeTir mDT, Animation &a) : degats(d), vitesseProjectile(vP), nombreProjectile(nP), tailleProjectile(tP), nomArme(nom), cooldown(cool), mdt(mDT), anim(a)
{
}

void Arme::tirer(Enemy &cible)
{
    if (compteFrame == cooldown)
    {
        Bullet *b = new Bullet(600, 400, tailleProjectile, degats, vitesseProjectile, cible, anim, mdt);
        ensemble.push_back(b);
        compteFrame = 0;
    }
    else compteFrame++;
}

void Arme::update(Enemy &cible)
{
    tirer(cible);
    for (auto b : ensemble) // On verifie si un projectile touche un enemi
    {
        if (b->collision(&cible))
        {
            b->life = 0; // si c'est le cas le projectile "meurt" et l'ennemi prend des degats
            cible.life -= b->degats;
            std::cout << cible.life << std::endl;
        }
    }

    for (auto i = std::begin(ensemble); i != std::end(ensemble);)
    {
        Bullet *e = *i;
        e->update(); // on fait bouger les projectiles grace a la fct update

        if (e->life == 0) // on efface les projectiles qui sont "mort"
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