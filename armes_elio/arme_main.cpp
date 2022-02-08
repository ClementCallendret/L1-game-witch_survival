// 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 token git

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include "Entity_arme.hpp"


int main()
{
    int W = 1200;
    int H = 800;
    sf::RenderWindow window(sf::VideoMode(W, H), "Witch survival");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);


    Enemy enemytest(W/2., H/4., 50., 3);  // Je créé un enemy que je ferais bouger moi même pour les testes
    bool moveUp, moveDown, moveLeft, moveRight;

    sf::CircleShape player(30.f);  // Je créé un cercle immobile au centre qui serait notre joueur
    player.setFillColor(sf::Color::Green);
    player.setOrigin(sf::Vector2f(player.getRadius(), player.getRadius()));
    player.setPosition(sf::Vector2f(W/2., H/2.));
    
    Arme baguette(1., 0.1, 1., 10., 1, "baguette de pain", 120);

    while (window.isOpen())  // Boucle Principale de l'app
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    moveUp = true;
                    break;
                case sf::Keyboard::Down:
                    moveDown = true;
                    break;
                case sf::Keyboard::Left:
                    moveLeft = true;
                    break;
                case sf::Keyboard::Right:
                    moveRight = true;
                    break;
                /* case sf::Keyboard::Space:
                    Bullet *b = new Bullet(player.getPosition().x, player.getPosition().y, 15., 1.5, enemytest);
                    ens_bullet.push_back(b); */
                }

            if (event.type == sf::Event::KeyReleased)
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    moveUp = false;
                    break;
                case sf::Keyboard::Down:
                    moveDown = false;
                    break;
                case sf::Keyboard::Left:
                    moveLeft = false;
                    break;
                case sf::Keyboard::Right:
                    moveRight = false;
                    break;
                }
        }

        // me permet de faire bouger l'enemi lorsque les touches sont pressés

        if (moveUp)
            enemytest.y -= 6;
        if (moveDown)
            enemytest.y += 6;
        if (moveLeft)
            enemytest.x -= 6;
        if (moveRight)
            enemytest.x += 6;

        // on actualise enfin la fenetre
        baguette.update(enemytest);

        window.clear();
        for (auto b : baguette.ensemble)
        {
            b->draw(window);
        }
        window.draw(player);
        enemytest.draw(window);
        window.display();
    }
}