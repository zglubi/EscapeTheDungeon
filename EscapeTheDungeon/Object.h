#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Interactable.h"

using namespace std;
using namespace sf;  // Ajout� pour utiliser les types de SFML sans le pr�fixe sf::

class Object : public Entity, public Interactable
{
public:
    Object(Texture t, Vector2f startPos);  // Constructeur
    virtual ~Object();  // Destructeur
    virtual void interact(std::shared_ptr<Player> player) override = 0;  // M�thode virtuelle pure
};

#endif // OBJECTS_H