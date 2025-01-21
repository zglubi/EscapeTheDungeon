#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "RandomNumber.h"

using namespace sf;
using namespace std;

class Map
{
private:
    Texture tileset;               // Texture pour le jeu de tuiles

    Sprite floorSprite;             // Sprite pour le sol
    Sprite wallFrontSprite;        // Sprite pour les murs avant
    Sprite wallSideSprite;         // Sprite pour les murs latéraux
    Sprite wallCornerSprite;
    Sprite doorSprite;
    Sprite doorLeftSprite;
    Sprite doorRightSprite;
    Sprite doorOpenSprite;
    Sprite smallDoorOpenSprite;
    Sprite smallDoorSprite;

    vector<vector<char>> map;      // Représentation de la carte

public:
    Map();                         // Constructeur
    ~Map();                        // Destructeur

    vector<vector<char>> getMap(); // Accesseur pour obtenir la carte

    void draw(RenderWindow& window); // Fonction pour dessiner la carte dans la fenêtre
};

#endif
