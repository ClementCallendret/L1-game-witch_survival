#include <SFML/Graphics.hpp>
#include "ennemi.h"
#include <stdio.h>
#include <cmath>

//Definition global du joueur
Ennemi::Ennemi(Player* j)
{   //definition du joueur avec le pointeur j
    joueur = j;
    //taille de l'image en pixel (a automatiser si y a le tps)
    taille = sf::Vector2f(taille.x, taille.y);

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
    float tailleImg = taille.x;

    //Recuperation pos joueur en x et y
    float posxP = joueur->getPlayerPos().x;
    float posyP = joueur->getPlayerPos().y;


    float  posxE = location.x + (tailleImg/2);
    float  posyE = location.y + (tailleImg/2);


    //Calcul de l'angle que l'ennemi doit prendre 
    deplaX = posxP - posxE;
    deplaY = posyP - posyE;
    angle = atan(deplaY/deplaX);

    //si position ennemi < position joueur
   if (posxE < posxP ){
        location.x += speed * cos(angle);
        location.y += speed * sin(angle);
    }
    //si position ennemi > position joueur
    else if (posxE > posxP ){
        location.x -= speed * cos(angle);
        location.y -= speed * sin(angle); 
    }  
    collision();
}

//Collision
void Ennemi::collision()
{  
    // Detection collision

    float playerLeftEdge = joueur->getPlayerPos().x;
    float playerRightEdge = playerLeftEdge;
    float playerTopEdge = joueur->getPlayerPos().y;
    float playerBottomEdge = playerTopEdge;

    float enemyLeftEdge = location.x;
    float enemyRightEdge = enemyLeftEdge + taille.x;
    float enemyTopEdge = location.y;
    float enemyBottomEdge = enemyTopEdge + taille.y;

    if ((playerRightEdge) > enemyLeftEdge && playerLeftEdge < enemyRightEdge &&
        playerTopEdge < enemyBottomEdge && playerBottomEdge > enemyTopEdge){
        location.x = 0;
        location.y = 0;     
        joueur->PV-=degat;     
        printf("PV joueur %d \n",joueur->PV);  
        }


}
