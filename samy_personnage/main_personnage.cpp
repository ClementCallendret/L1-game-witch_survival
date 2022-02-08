// lien utile de fou !!!! <https://www.sfml-dev.org/documentation/2.5.1-fr/>

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "deplacement.h"

int main()
{
    // la fenetre principale
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

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

        player.inputs();

        // draw
        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}

/*
sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
*/