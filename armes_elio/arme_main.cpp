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

    sf::CircleShape player(50.f);  // Je créé un cercle immobile au centre qui serait notre joueur
    player.setFillColor(sf::Color::Green);
    player.setOrigin(sf::Vector2f(player.getRadius(), player.getRadius()));
    player.setPosition(sf::Vector2f(W/2., H/2.));

    std::vector<Bullet *> ens_bullet; // tableau dynamique contenant des pointeurs vers chaque projectile a l'ecran


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
                case sf::Keyboard::Space:
                    Bullet *b = new Bullet(player.getPosition().x, player.getPosition().y, 15., 1.5, enemytest);
                    ens_bullet.push_back(b);
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


        for (auto b : ens_bullet) // On verifie si un projectile touche un enemi
        {
            if (b->collision(&enemytest))
                {
                b->life = 0;    // si c'est le cas le projectile "meurt" et l'ennemi prend des degats
                enemytest.life -= b->degats;
                }
            
        }

        for (auto i = std::begin(ens_bullet); i != std::end(ens_bullet);) 
        { 
            Bullet *e = *i;
            e->update();  // on fait bouger les projectiles grace a la fct update

            if (e->life == 0)  // on efface les projectiles qui sont "mort"
            {
                i = ens_bullet.erase(i);
                delete e;
            }
            else
                i++;
            
        }

        // on actualise enfin la fenetre

        window.clear();
        window.draw(player);
        enemytest.draw(window);
        for (auto b : ens_bullet)
        {
            b->draw(window);
        }
        window.display();
    }
}