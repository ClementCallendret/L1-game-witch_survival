#include "ennemi.h"
#include <cmath>

//Definition global du joueur
Ennemi::Ennemi(Player* j, sf::Vector2f loc) : joueur(j), location(loc) //Parametre que va prendre la classe joueur
{   

}

void Ennemi::draw(sf::RenderWindow &window) // Dessin de l'ennemi
{   anim.sprite.setPosition(location.x, location.y); // deplacer l'image
    anim.update();
    window.draw(anim.sprite);
}


void Ennemi::update() //Deplacement de l'ennemi -> Objectif : suivre le joueur
{   float deplaX,deplaY,angle; //Definition variable pour les calculs

    float posxP = joueur->getPlayerPos().x; // On récupère les positions du joueur en x et en y
    float posyP = joueur->getPlayerPos().y; // Elles correspondent au centre de l'ennemi

    float  posxE = location.x; //Idem pour l'ennemi
    float  posyE = location.y;
    
    deplaX = posxP - posxE; //Début du calcul de fou
    deplaY = posyP - posyE;

    if (deplaX<0.000001 && deplaX>0.000001){ //Securite car deplaX va être un diviseur donc il ne faut pas qu'il soit égale à 0
        if (deplaX >0){ // si deplaX est positif
            deplaX = 0.01; //
        }
        else{
            deplaX = -0.01;
        }
    }

    angle = atan(deplaY/deplaX); // Calcul de l'angle que l'ennemi doit prendre
    
    if (posxE < posxP){  //si position ennemi < position joueur
        location.x += speed * cos(angle);
        location.y += speed * sin(angle);
        anim.sprite.setScale(-ratio,ratio); 
    }
 
    else {    //si position ennemi >= position joueur
        location.x -= speed * cos(angle);
        location.y -= speed * sin(angle); 
        anim.sprite.setScale(ratio,ratio);
    }  
    collision();

}

//Collision
void Ennemi::collision()
{  
    // Detection collision :

    //Def côté Player
    float playerLeftEdge = joueur->getPlayerPos().x - 10; //Pour une hitbox raisonnable a cause du chapeau, de la baguette etc..
    float playerRightEdge = joueur->getPlayerPos().x + 10;
    float playerTopEdge = joueur->getPlayerPos().y - 5;
    float playerBottomEdge = joueur->getPlayerPos().y + 11;

    //Def côté ennemi
    float enemyLeftEdge = location.x - (taille.x/2); //location.x retourne la position au milieu de l'ennemi,
    float enemyTopEdge = location.y - (taille.y/2); // donc il faut soustraire la moitié de sa taille pour avoir le côté
    float enemyRightEdge = location.x + (taille.x/2);
    float enemyBottomEdge = location.y + (taille.y/2);

    //Calcul incroyable pour détecter les collisions
    if ((playerRightEdge) > enemyLeftEdge && playerLeftEdge < enemyRightEdge &&
        playerTopEdge < enemyBottomEdge && playerBottomEdge > enemyTopEdge){   
        joueur->PV -= degat; //On enlève des pv au joueur
        }


}
