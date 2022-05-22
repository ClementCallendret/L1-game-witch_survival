#include "Map.hpp"
#include "Animation.hpp"

// 0 = herbe arrondit haut droie        0
// 1 = herbe arrondit haut gauche       1
// 2 - 16 = herbe                       2
// 17 - 31 = herbe + fleur              3
// 32 - 37 = 4 carreaux                 4
// 38 = angle bas droite                5
// 39 = angle bas gauche                6
// 40 = angle haut gauche               7
// 41 = angle haut droite               8
// 42 - 45 = carreaux en bas            9
// 46 - 49 = carreaux en haut           10
// 50 - 52 = droite                     11
// 53 - 56 = gauche                     12
// 57 = haut droite                     13
// 58 - 59 = bas droite                 14
// 60 = bas gauche                      15
// 61 = haut gauche                     16

Map::Map()
{
    // on cree la map avec le niveau precedemment defini
    for (int i = 0; i < 113*104; i++)
    {
        switch (level[i])
        {
        case 2:
            level[i] = 2 + rand() % (16 - 2 + 1);
            break;
        case 3:
            level[i] = 17 + rand() % (31 - 17 + 1);
            break;
        case 4:
            level[i] = 32 + rand() % (37 - 32 + 1);
            break;
        case 5:
            level[i] = 38;
            break;
        case 6:
            level[i] = 39;
            break;
        case 7:
            level[i] = 40;
            break;
        case 8:
            level[i] = 41;
            break;
        case 9:
            level[i] = 42 + rand() % (45 - 42 + 1);
            break;
        case 10:
            level[i] = 46 + rand() % (49 - 46 + 1);
            break;
        case 11:
            level[i] = 50 + rand() % (52 - 50 + 1);
            break;
        case 12:
            level[i] = 53 + rand() % (56 - 53 + 1);
            break;
        case 13:
            level[i] = 57;
            break;
        case 14:
            level[i] = 58 + rand() % 2;
            break;
        case 15:
            level[i] = 60;
            break;
        case 16:
            level[i] = 61;
            break;
        default:
            break;
        }
    }

    if (!load("media/newmap.png", sf::Vector2u(32, 32), level, 113, 104))
        throw("Erreur la map ne charge pas");
}

bool Map::load(const std::string &tileset, sf::Vector2u tileSize, int *tiles, int width, int height)
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
