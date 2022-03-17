#include "ennemi_chevalier.h"
#include <cmath>

chevalier::chevalier(Player* j, sf::Vector2f loc): Ennemi(j, loc){
    speed = 2;
    PV = 50;
    degat = 1;
    xp = 2;
    name = "chevalier";
    if (!texture.loadFromFile("media/chevalier-image.png"))
    return;
    nv_texture.loadFromFile("media/chevalier.png");

    sprite.setTexture(texture);
    taille = sf::Vector2f(50,50);

}

// Dessin du chevalier
void chevalier::draw(sf::RenderWindow &window)
{
    // deplacer l'image
    anim.sprite.setPosition(location.x, location.y); 
    window.draw(anim.sprite);
    anim.update();
}

void chevalier::update()
{   //Definition variable pour les calculs
    float deplaX,deplaY,angle;
    float tailleImg = taille.x;

    //Recuperation pos joueur en x et y
    float posxP = joueur->getPlayerPos().x;
    float posyP = joueur->getPlayerPos().y;

    if (posxP > location.x){
        anim.sprite.setScale(-1,1);
    }
    else{
        anim.sprite.setScale(1,1);
    }
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