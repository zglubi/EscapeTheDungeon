// Map.cpp
#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map()
{
    // Charger le tileset à partir du fichier
    if (!tileset.loadFromFile("Assets/Tileset/Tileset.png"))
    {
        cout << "tileset introuvable" << endl;
    }

    // Configurer le sprite du sol
    floorSprite.setTexture(tileset);
    floorSprite.setTextureRect(IntRect(16, 64, 16, 16)); // Positionner la section du tileset utilisée
    floorSprite.setScale(Vector2f(3, 3));

    wallSideSprite.setTexture(tileset);
    wallSideSprite.setTextureRect(IntRect(32, 158, 16, 16));
    wallSideSprite.setScale(Vector2f(3, 3));

    wallFrontSprite.setTexture(tileset);
    wallFrontSprite.setTextureRect(IntRect(36, 132, 16, 20));
    wallFrontSprite.setScale(Vector2f(3, 3));

    wallCornerSprite.setTexture(tileset);
    wallCornerSprite.setTextureRect(IntRect(32, 132, 16, 20));
    wallCornerSprite.setScale(Vector2f(3, 3));

    wallCornerReversedSprite.setTexture(tileset);
    wallCornerReversedSprite.setTextureRect(IntRect(59, 132, 16, 20));
    wallCornerReversedSprite.setScale(Vector2f(3, 3));

    wallCornerDownSprite.setTexture(tileset);
    wallCornerDownSprite.setTextureRect(IntRect(32, 180, 16, 8));
    wallCornerDownSprite.setScale(Vector2f(3, 3));

    wallCornerDownReversedSprite.setTexture(tileset);
    wallCornerDownReversedSprite.setTextureRect(IntRect(59, 180, 6, 8));
    wallCornerDownReversedSprite.setScale(Vector2f(3, 3));

    doorSprite.setTexture(tileset);
    doorSprite.setTextureRect(IntRect(16, 238, 64, 32));
    doorSprite.setScale(Vector2f(3, 3));

    doorLeftSprite.setTexture(tileset);
    doorLeftSprite.setTextureRect(IntRect(16, 238, 16, 32));
    doorLeftSprite.setScale(Vector2f(3, 3));

    doorRightSprite.setTexture(tileset);
    doorRightSprite.setTextureRect(IntRect(64, 238, 16, 32));
    doorRightSprite.setScale(Vector2f(3, 3));

    doorOpenSprite.setTexture(tileset);
    doorOpenSprite.setTextureRect(IntRect(80, 238, 32, 32));
    doorOpenSprite.setScale(Vector2f(3, 3));

    smallDoorSprite.setTexture(tileset);
    smallDoorSprite.setTextureRect(IntRect(32, 238, 32, 32));
    smallDoorSprite.setScale(Vector2f(2, 2));

    smallDoorOpenSprite.setTexture(tileset);
    smallDoorOpenSprite.setTextureRect(IntRect(80, 238, 32, 32));
    smallDoorOpenSprite.setScale(Vector2f(2, 2));

    // Charger la carte depuis le fichier map.txt
    loadMap("Assets/Map/map.txt");
}

Map::~Map() {}

vector<vector<char>>& Map::getMap()
{
    return map; // Retourner la carte
}

void Map::draw(RenderWindow& window)
{
    // Dessiner la carte sur la fenêtre
    for (int i = 0; i < map.size() - 1; i++)
    {
        for (int j = 0; j < map[0].size() - 2; j++)
        {
            floorSprite.setPosition(Vector2f(j * 48 + 48, i * 48 + 48)); // Positionner chaque sprite
            window.draw(floorSprite); // Dessiner le sprite
        }
    }

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            switch (map[i][j])
            {
            case 'S':
                wallSideSprite.setPosition(Vector2f(j * 48, i * 48));
                window.draw(wallSideSprite);
                break;
            case 'W':
                wallFrontSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                window.draw(wallFrontSprite);
                break;
            case 'C':
                wallCornerSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                window.draw(wallCornerSprite);
                break;
            case 'D':
                if (map[i + 1][j] == 'D')
                {
                    doorSprite.setPosition(Vector2f(j * 48, i * 48));
                    window.draw(doorSprite);
                }
                j += 3;
                break;
            case 'O':
                if (map[i + 1][j] == 'O')
                {
                    doorLeftSprite.setPosition(Vector2f((j - 1) * 48, i * 48));
                    doorOpenSprite.setPosition(Vector2f(j * 48, i * 48));
                    doorRightSprite.setPosition(Vector2f(j * 48 + 96, i * 48));
                    window.draw(doorLeftSprite);
                    window.draw(doorOpenSprite);
                    window.draw(doorRightSprite);
                }
                j += 2;
                break;
            case 'd':
                if (map[i][j + 1] == 'W' || map[i][j + 1] == 'S' || map[i][j + 1] == 'C')
                {
                    j++;
                    switch (map[i][j])
                    {
                    case 'S':
                        wallSideSprite.setPosition(Vector2f(j * 48, i * 48));
                        window.draw(wallSideSprite);
                        break;
                    case 'W':
                        wallFrontSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                        window.draw(wallFrontSprite);
                        break;
                    case 'C':
                        wallCornerSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                        window.draw(wallCornerSprite);
                        break;
                    }
                    smallDoorSprite.setPosition(Vector2f((j - 1) * 48 - 8, i * 48 - 16));
                    window.draw(smallDoorSprite);
                    break;
                }
                else
                {
                    smallDoorSprite.setPosition(Vector2f(j * 48, i * 48 - 16));
                    window.draw(smallDoorSprite);
                }
                break;
            case 'o':
                if (map[i][j + 1] == 'W' || map[i][j + 1] == 'S' || map[i][j + 1] == 'C')
                {
                    j++;
                    switch (map[i][j])
                    {
                    case 'S':
                        wallSideSprite.setPosition(Vector2f(j * 48, i * 48));
                        window.draw(wallSideSprite);
                        break;
                    case 'W':
                        wallFrontSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                        window.draw(wallFrontSprite);
                        break;
                    case 'C':
                        wallCornerSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                        window.draw(wallCornerSprite);
                        break;
                    }
                    smallDoorOpenSprite.setPosition(Vector2f((j - 1) * 48 - 8, i * 48 - 16));
                    window.draw(smallDoorOpenSprite);
                    break;
                }
                else
                {
                    smallDoorOpenSprite.setPosition(Vector2f(j * 48, i * 48 - 16));
                    window.draw(smallDoorOpenSprite);
                }
                break;
            case 'c':
                wallCornerDownSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                wallFrontSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                window.draw(wallFrontSprite);
                window.draw(wallCornerDownSprite);
                break;
            case 'R':
                wallCornerReversedSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                window.draw(wallCornerReversedSprite);
                break;
            case 'r':
                wallFrontSprite.setTextureRect(IntRect(56, 132, 4, 20));
                wallCornerDownReversedSprite.setPosition(Vector2f(j * 48, (i * 48) - 12));
                wallFrontSprite.setPosition(Vector2f(j * 48 + 3, (i * 48) - 12));
                window.draw(wallFrontSprite);
                window.draw(wallCornerDownReversedSprite);
                wallFrontSprite.setTextureRect(IntRect(36, 132, 16, 20));
                break;
            default:
                break;
            }
        }
    }
}

void Map::loadMap(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Impossible d'ouvrir le fichier " << filename << endl;
        return;
    }

    map.clear();
    string line;
    while (getline(file, line))
    {
        vector<char> row;
        for (char& tile : line)
        {
            row.push_back(tile);
        }
        map.push_back(row);
    }

    file.close();
}
