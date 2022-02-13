#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Arme.hpp"
#include "Bullet.hpp"
#include "Animation.hpp"


int main()
{
    int W = 1200;
    int H = 800;
    sf::RenderWindow window(sf::VideoMode(W, H), "Witch survival");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);


    Enemy enemytest(W/2., H/4., 30., 10);  // Je créé un enemy que je ferais bouger moi même pour les testes
    bool moveUp, moveDown, moveLeft, moveRight;

    sf::CircleShape player(30.f);  // Je créé un cercle immobile au centre qui serait notre joueur
    player.setFillColor(sf::Color::Green);
    player.setOrigin(sf::Vector2f(player.getRadius(), player.getRadius()));
    player.setPosition(sf::Vector2f(W/2., H/2.));

    sf::Texture blueFire;
    blueFire.loadFromFile("fire_blue.png");
    sf::Sprite blueSprite(blueFire);

    Animation blueAnim(blueSprite, 32, 64, 16, sf::Vector2i(16, 16));
    Arme baguette(1., 0.1, 1., 10, 1, "baguette de pain", 30, randomm, blueAnim);

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
        baguette.draw(window);
        window.draw(player);
        enemytest.draw(window);
        window.display();
    }
}