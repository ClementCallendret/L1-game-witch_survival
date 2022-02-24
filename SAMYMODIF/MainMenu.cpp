#include "MainMenu.hpp"
#include <iostream>
#include <string>

MainMenu::MainMenu()
{
    if(!police.loadFromFile("media/Witch.ttf"))
    {
        std::cout << "police non chargé" << std::endl;
    }

    // JOUEUR
    choix[0].setFont(police);
    choix[0].setFillColor(sf::Color::White);
    choix[0].setString("Jouer");
    choix[0].setCharacterSize(100);
    choix[0].setPosition(400, 250);

    // CREDITS
    choix[1].setFont(police);
    choix[1].setFillColor(sf::Color::White);
    choix[1].setString("Credits");
    choix[1].setCharacterSize(100);
    choix[1].setPosition(400, 400);

    // QUITTER
    choix[2].setFont(police);
    choix[2].setFillColor(sf::Color::White);
    choix[2].setString("Quitter");
    choix[2].setCharacterSize(100);
    choix[2].setPosition(400, 550);

    nbChoix = 3;
    menuSelected = -1;
}

void MainMenu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < nbChoix; i++)
        window.draw(choix[i]);
}

void MainMenu::moveUp()
{
    if(menuSelected == -1)
    {
        menuSelected = nbChoix-1;
    }
    else if(menuSelected == 0)
    {
        choix[menuSelected].setFillColor(sf::Color::White);
        menuSelected = nbChoix-1;
    }
    else
    {
        choix[menuSelected].setFillColor(sf::Color::White);
        menuSelected = (menuSelected - 1)%nbChoix;
    }

    choix[menuSelected].setFillColor(sf::Color::Yellow);

}

void MainMenu::moveDown()
{
    if(menuSelected == -1)
    {
        menuSelected = 0;
    }
    else
    {
        choix[menuSelected].setFillColor(sf::Color::White);
        menuSelected = (menuSelected + 1)%nbChoix;
    }
    
    choix[menuSelected].setFillColor(sf::Color::Yellow);
}
