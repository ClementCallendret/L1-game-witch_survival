#include <SFML/Graphics.hpp>
#include "ennemi.h"
#include <cmath>

//Definition global du joueur
Ennemi::Ennemi(Player* j, sf::Vector2f loc) : joueur(j), location(loc)
{   //definition du joueur avec le pointeur j
    //taille de l'image en pixel (a automatiser si y a le tps)
    taille = sf::Vector2f(taille.x, taille.y);

}

// Dessin de l'ennemi
void Ennemi::draw(sf::RenderWindow &window)
{
    // deplacer l'image
    anim.sprite.setPosition(location.x, location.y); 
    anim.update();
    window.draw(anim.sprite);
}

//Deplacement de l'ennemi -> Objectif : suivre le joueur
void Ennemi::update()
{   //Definition variable pour les calculs
    float deplaX,deplaY,angle;

    //Recuperation pos joueur en x et y
    float posxP = joueur->getPlayerPos().x; // On veut le viser le milieu du player et getPlayerPos().x retourne son coin en haut a gauche
    float posyP = joueur->getPlayerPos().y; // donc on rajoute la moitié de son image (32/2 = 16)

    float  posxE = location.x;
    float  posyE = location.y;


    //Calcul de l'angle que l'ennemi doit prendre 
    deplaX = posxP - posxE;
    deplaY = posyP - posyE;

    //Pour éviter un bug quand on divise par 0
    if (deplaX < 0.1 && deplaX> -0.1){
        if (deplaX >= 0){
            deplaX = 0.2;
        }
        else{
            deplaX = -0.2;
        }
        deplaX = 1;
    }

    // Calcul angle
    angle = atan(deplaY/deplaX);

    //Pour éviter angle = 0
    
    if (angle < 0.1 && angle > -0.1){
        if (angle >= 0){
            angle = 0.2;
        }
        else{
            angle = -0.2;
        }
    }



    //si position ennemi < position joueur
   if (posxE - posxP < 1){
        location.x += speed * cos(angle);
        location.y += speed * sin(angle);
    }
    //si position ennemi > position joueur
    else if (posxE - posxP > 1){
        location.x -= speed * cos(angle);
        location.y -= speed * sin(angle); 
    }  

    //Pour que l'anim se tourne quand le player est à droite ou à gauche d'elle
    if (posxP > location.x){
        anim.sprite.setScale(-ratio,ratio); //Pour ratio des randoms sur Twitter
    }
    else{
        anim.sprite.setScale(ratio,ratio);
    }

    collision();
}

//Collision
void Ennemi::collision()
{  
    // Detection collision

    //Def côté Player
    float playerLeftEdge = joueur->getPlayerPos().x - 10; //Pour une hitbox raisonnable a cause du chapeau, de la baguette etc..
    float playerRightEdge = joueur->getPlayerPos().x + 10;
    float playerTopEdge = joueur->getPlayerPos().y - 5;
    float playerBottomEdge = joueur->getPlayerPos().y + 11;

    //Def côté ennemi
    float enemyLeftEdge = location.x - (taille.x/2);
    float enemyRightEdge = location.x + (taille.x/2);
    float enemyTopEdge = location.y - (taille.y/2);
    float enemyBottomEdge = location.y + (taille.y/2);

    //Calcul incroyable pour détecter les collisions
    if ((playerRightEdge) > enemyLeftEdge && playerLeftEdge < enemyRightEdge &&
        playerTopEdge < enemyBottomEdge && playerBottomEdge > enemyTopEdge){   
        //Action quand il y a une collision
        joueur->PV-=degat;
        }


}
