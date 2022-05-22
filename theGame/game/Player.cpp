#include "Player.hpp"
#include "Collision.hpp"

Player::Player()
{
    if (!Collision::CreateTextureAndBitmask(texture, "media/witch.png"))
        return;

    sprite.setTexture(texture);
    anim = Animation(sprite, 1, sf::Vector2i(16, 16), 32, 32);
}

void Player::update() // deplacement de notre joueur (Haut/Bas/Gauche/Droite) ainsi que l'arret lors de l'atteinte des bords de la map
{
    bool gauche = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);  // Récuperation des fleches pressees
    bool droite = sf::Keyboard::isKeyPressed(sf::Keyboard::Right); // Dans des variables bools
    bool haut = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool bas = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    float coef = 0.85; // coef pour la vitesse en diagonale

    if (gauche && droite)
    { // Si deux flèches opposees activees alors elles s'annulent
        gauche = 0;
        droite = 0;
    }
    if (haut && bas)
    {
        haut = 0;
        bas = 0;
    }

    if (droite)
    { // Quand fleche de droite appuyee
        if (haut)
        { // Et que fleche haut appuyee, on monte en diagonale
            location.x += coef * speed;
            location.y -= coef * speed; // OUI, quand on veut monter faut diminuer la position en Y, pas moi qu'est fait ça
        }
        else if (bas)
        { // Et que fleche bas activee,on descend en diagonale
            location.x += coef * speed;
            location.y += coef * speed;
        }
        else
        {
            location.x += speed; // Si juste fleche droite activee, on va a droite
        }
        anim.sprite.setScale(-1, 1); // Pour changer où regarde la perso (pas qu'il fasse du moonwalk)
        sens = 1;               // Pour le sens des armes 
    }

    if (gauche)
    { // Même principe qu'en haut mais avec la fleche gauche appuyee
        if (haut)
        {
            location.x -= coef * speed;
            location.y -= coef * speed;
        }
        else if (bas)
        {
            location.x -= coef * speed;
            location.y += coef * speed;
        }
        else
        {
            location.x -= speed;
        }
        anim.sprite.setScale(1, 1);
        sens = -1;
    }

    if (haut && (droite == 0) && (gauche == 0))
    { // Si juste fleche haut activee
        location.y -= speed;
    }
    if (bas && (!droite) && (!gauche))
    { // Si juste fleche bas activee
        location.y += speed;
    }

    if (location.x >= 3571.)
    { // Les 4 if c'est pour gerer les bordures de la map, pour pas que le perso sorte
        location.x = 3571.;
    }
    else if (location.x <= 45)
    {
        location.x = 45;
    }
    if (location.y <= 45.)
    {
        location.y = 45.;
    }
    else if (location.y >= 3283.)
    {
        location.y = 3283.;
    }
    newlevel = 0;
    anim.update();
}

void Player::draw(sf::RenderWindow &window)
{
    anim.sprite.setPosition(location.x, location.y); // pour deplacer l'image de notre joueur il faut deja la placer

    sf::RectangleShape totlife(sf::Vector2f(75, 5));
    totlife.setOutlineColor(sf::Color::Black);
    totlife.setOutlineThickness(1);
    totlife.setFillColor(sf::Color(255, 255, 255, 127));
    totlife.setOrigin(75 / 2, 2.5);
    totlife.setPosition(location.x, location.y - 30);

    sf::RectangleShape lifebar(sf::Vector2f(PV * 75 / pvMax, 5)); // barre de vie du perso
    lifebar.setFillColor(sf::Color::Red);
    lifebar.setOrigin(75 / 2, 2.5);
    lifebar.setPosition(location.x, location.y - 30);

    window.draw(totlife);
    window.draw(lifebar);
    window.draw(anim.sprite);
}

void Player::heal(float n)
{
    PV += n;
    if (PV > pvMax)
    {
        PV = pvMax;
    }
}

void Player::prendreXP(float n)
{
    if (xp + n >= xpMax)
    {
        xp = n - (xpMax - xp);
        xpMax *= 1.1;
        newlevel = 1;
    }
    else
        xp += n;
}
