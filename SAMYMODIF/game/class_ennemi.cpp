#include <SFML/Graphics.hpp>
#include "ennemi.h"
#include <stdio.h>
#include <cmath>

Ennemi::Ennemi(Player* j)
{
    joueur = j;
    taille = sf::Vector2f(256, 256);
}

void Ennemi::draw(sf::RenderWindow &window)
{
    sf::Texture texture;
    if (!texture.loadFromFile("media/diable.png"))
        return;

    sf::Sprite sprite(texture);
    sprite.setOrigin(157, 157);

    sprite.setPosition(location.x, location.y); // deplacer l'image

    window.draw(sprite);
}


void Ennemi::inputs()
{
    //float pente;
    float deplaX,deplaY,angle;
    //pente = (location.y - posyP) / (location.x - posxP);
    //printf("%f %f\n",location.y,location.x);


       // Collision
    //printf("%lf %lf\n",location.x,posxP);
    float posxP = joueur->getPlayerPos().x;
    float posyP = joueur->getPlayerPos().y;

    deplaX = posxP - location.x;
    deplaY = posyP - location.y;
    angle = atan(deplaY/deplaX);


   if ((location.x < posxP && location.y < posyP) || (location.x < posxP && location.y > posyP)){
        location.x += speed * cos(angle);
        location.y += speed * sin(angle);
    }

    else if ((location.x > posxP && location.y < posyP) || (location.x > posxP && location.y > posyP)){
        location.x -= speed * cos(angle);
        location.y -= speed * sin(angle); 
    }      
    int tailleE = 256;
    int tailleP = 32;
// COLLISION 
if (location.x < (posxP + tailleP) && location.x + tailleE > posxP && location.y < posyP + tailleP && location.y + tailleE > posyP){
    location.x = 0;
    location.y = 0;
}

}
                     
    //if (int (location.x + 256) == int (posxP) || int(location.x) == int(posxP + 225) || (int(location.y + 256) == int(posyP)) || int(location.y) ==  int(posyP + 225)){
     //   location.x = 0;
     //   location.y = 0;
   // }
   //Collision gauche
   /*
   printf("%f   %f\n",(location.x + tailleE), posxP);
   if (((location.y + tailleE)<posyP) || (location.y > (posyP + tailleP))){

    if (((location.x) < posxP) && (int(location.x + tailleE) == int (posxP))){
        location.x = 0;
        location.y = 0;

   }
   }

*/


    //Other conditions

   /* deplaX = posxP - location.x;
    deplaY = posyP - location.y;
    if (location.x <= deplaX){
        location.x += (deplaX/(deplaX + deplaY)) * speed;
    }
    if (location.x > deplaX){
        location.x -= (deplaX/(deplaX + deplaY)) * speed;
    }


    if (location.y <= deplaY){
        location.y += (deplaY/(deplaX + deplaY)) * speed;
    }

    if (location.y > deplaY){
        location.y -= (deplaY/(deplaX + deplaY)) * speed;
    }*/
    //printf("%f    %f\n",location.x, posxP);
    //if ((int (location.x) == int (posxP)) && (int (location.y) == int (posyP))){
      //  location.x = 0;
        //location.y = 0;}



    /*

    float angle = atan(pente);

    if (posyP < location.y)
        angle += M_PI;
    printf("%f\n",angle);

    location.x += speed * sin(angle); // fait avvancer le projectiles dans la bonne
    location.y += speed * cos(angle); // direction grace à la trigo
    // Axe X
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        location.x -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        location.x += speed;
    }

    if (location.x > posxP){
        location.x -= 0.2*speed;
    }
    
    if (location.x <posxP){
        location.x += 0.2*speed;
    }

// Axe Y
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        location.y -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        location.y += speed;
    }

    if (location.y > posyP){
        location.y -= 0.2*speed;
    }
    
    if (location.y <posyP){
        location.y += 0.2*speed;
    }
    */