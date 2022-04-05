#include "ennemi_arbre.h"
#include <cmath>

arbre::arbre(Player* j, sf::Vector2f loc): Ennemi(j, loc){ //paramètre utilisé pour les deplacements de l'ennemi car il suit le joueur
    speed = 0.7; //vitesse
    PV = 40; //point de vie
    degat = 2; //degats
    xp = 2; //experience donnee quand tué
    name = "Arbre"; //nom
    ratio = 0.2; //Pour redimensionner l'image en jeu : image en jeu = image de base * ratio
    if (!texture.loadFromFile("media/arbre.png")) //texture de l'arbre
    return;
    texture.loadFromFile("media/arbre.png"); 
    sprite.setTexture(texture); //application de la texture
    anim = Animation(sprite, 6,sf::Vector2i(145,140),290,280,0.2,0.2); //Animation de l'ennemi
    //nom, nb image, milieu, LARGEUR, HAUTEUR, ratio, vitesse
    taille = sf::Vector2f(30,30); //pour la hitbox

}