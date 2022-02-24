#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <array>

class MainMenu 
{
private : 

    static MainMenu m_menu;
    int menuSelected, nbChoix;
    sf::Font police;
    std::array<sf::Text, 3 > choix;

public :

    MainMenu();
    void draw(sf::RenderWindow & window);
    void moveUp();
    void moveDown();

    int ChoixPresse(){
        return menuSelected;
    }

};

#endif