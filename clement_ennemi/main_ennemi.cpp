// lien utile de fou !!!! <https://www.sfml-dev.org/documentation/2.5.1-fr/>
// g++ -Wall -c main_ennemi.cpp class_ennemi.cpp
// g++ main_ennemi.o class_ennemi.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
// ./sfml-app 
#include <SFML/Graphics.hpp>
#include "ennemi.h"
#include "deplacement_ennemi.h"
#include "math.h"

int main()
{
    // la fenetre principale
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Test ennemi");
    Ennemi ennemi;
    Player player;

    while (window.isOpen())
    {
        // inputs
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ennemi.inputs();
        player.inputs();
        // draw
        window.clear();
        ennemi.draw(window);
        player.draw(window);
        window.display();
        
    }

    return 0;
}

/*
sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
*/