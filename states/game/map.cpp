#include "map.h"
#include "Animation.hpp"
// c'est ici qu'il y aura la map ingame

Map::Map()
{
    // on cree la map avec le niveau precedemment defini

    if (!load("media/Tileset.png", sf::Vector2u(32, 32), level, 113, 104))
        throw ("Error la map charge pas mon reuf");
}

bool Map::load(const std::string &tileset, sf::Vector2u tileSize, const int *tiles, int width, int height)
{
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (int i = 0; i < width; ++i)
        for (int j = 0; j < height; ++j)
        {
            // on recupere le numero de tuile courant
            int tileNumber = tiles[i + j * width];

            // on en deduit sa position dans la texture du tileset
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // on recupere un pointeur vers le quad a definir dans le tableau de vertex
            sf::Vertex *quad = &m_vertices[(i + j * width) * 4];

            // on definit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // on definit ses quatre coordonnees de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &m_tileset;

    // et on dessine enfin le tableau de vertex
    target.draw(m_vertices, states);
}
