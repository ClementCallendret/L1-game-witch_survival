#include <SFML/Graphics.hpp>
#include "ennemi.h"
#include <stdio.h>
#include <cmath>

//Definition global du joueur
Ennemi::Ennemi(Player* j)
{   //definition du joueur avec le pointeur j
    joueur = j;
    //taille de l'image en pixel (a automatiser si y a le tps)
    taille = sf::Vector2f(256, 256);

}

// Dessin de l'ennemi
void Ennemi::draw(sf::RenderWindow &window)
{
    // deplacer l'image
    sprite.setPosition(location.x, location.y); 

    window.draw(sprite);
}

//Deplacement de l'ennemi -> Objectif : suivre le joueur
void Ennemi::update()
{   //Definition variable pour les calculs
    float deplaX,deplaY,angle;

    //Recuperation pos joueur en x et y
    float posxP = joueur->getPlayerPos().x;
    float posyP = joueur->getPlayerPos().y;

    //Calcul de l'angle que l'ennemi doit prendre 
    deplaX = posxP - location.x;
    deplaY = posyP - location.y;
    angle = atan(deplaY/deplaX);

    //si position ennemi < position joueur
   if (location.x < posxP ){
        location.x += speed * cos(angle);
        location.y += speed * sin(angle);
    }
    //si position ennemi > position joueur
    else if (location.x > posxP ){
        location.x -= speed * cos(angle);
        location.y -= speed * sin(angle); 
    }  
}

//Collision
void Ennemi::collision()
{  
    //Recuperation pos joueur en x et y
    float posxP = joueur->getPlayerPos().x;
    float posyP = joueur->getPlayerPos().y;

     //taille de l'image de l'ennemi
    int tailleE = 256;
    //taille de l'image du joueur
    int tailleP = 32;
    // Detection collision
    if (location.x < (posxP + tailleP) && location.x + tailleE > posxP && location.y < posyP + tailleP && location.y + tailleE > posyP){
        location.x = 0;
        location.y = 0;
}
}