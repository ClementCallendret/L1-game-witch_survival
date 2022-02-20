// lien utile de fou !!!! <https://www.sfml-dev.org/documentation/2.5.1-fr/>
// <pour compiler> g++ main.cpp -o test.o -lsfml-graphics -lsfml-window -lsfml-system


#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "map.h"
#include "Animation.hpp"
#include "ennemi.h"
#include "Armes/Bullet.hpp"
#include "Armes/Arme.hpp"
#include "Armes/ArmeFireball.hpp"
#include "Armes/ArmeHache.hpp"
#include "Armes/ArmeOrbe.hpp"
#include "Armes/ArmeEclair.hpp"
#include "Armes/Shield.hpp"
#include "Armes/ArmeEpee.hpp"


int main()
{
    // on cree la fenetre principale
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Witch SURVIVAL !"); // Taille de la fenetre principale appelee ici "window" (1600/900)
    window.setFramerateLimit(56);
    
    Map map = Map();
    Player player;
    Ennemi ennemi(&player);
    
    Arme* baguette = new ArmeFireball(&player);
    Arme* hache = new ArmeHache(&player);
    Arme* fire = new ArmeOrbe(&player);
    Arme* thunder = new ArmeEclair(&player);
    Arme* shield = new ArmeShield(&player);
    Arme* epee = new ArmeEpee(&player);

    while (window.isOpen()) // On entre dans la boucle while tant que le jeu est ouvert.
    {
        // inputs on gere les events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // Lorsque l'on va fermer le jeu, notre code vabel et bien s'arreter
                {
                    delete baguette;
                    baguette = 0;
                    delete hache;
                    hache = 0;
                    delete fire;
                    fire = 0;
                    delete thunder;
                    thunder = 0;
                    delete shield;
                    shield = 0;
                    delete epee;
                    epee = 0;
                    window.close();
                }         

        }

        player.inputs();
        ennemi.inputs();
        if (baguette) baguette->update(&ennemi);
        if (hache) hache->update(&ennemi);
        if (fire) fire->update();
        if (thunder) thunder->update(&ennemi);
        // if (shield) shield->update();
        if (epee) epee->update();

        // on draw le jeu
        window.clear();
        window.draw(map);
        ennemi.draw(window);
        player.draw(window);

        if (baguette) baguette->draw(window);
        if (hache) hache->draw(window);
        if (fire) fire->draw(window);
        if (thunder) thunder->draw(window);
        //if (shield) shield->draw(window);
        if (epee) epee->draw(window);
        
        window.display();


    }

    return 0;
}

/*
sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
*/