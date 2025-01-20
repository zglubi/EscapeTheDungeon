#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Player.h"

using namespace std;

class Object : public Entity {
public:
    Object();  // Constructeur
    virtual ~Object();  // Destructeur

    // Méthode virtuelle pure pour l'interaction avec un joueur
    virtual void interact(shared_ptr<Player> player) = 0;
};

#endif // OBJECTS_H
