#include "Objects.h"

// Constructeur
Object::Object() : Entity(sf::Color::Blue, sf::Vector2f(25, 25))
{
    // Initialisation si n�cessaire
}

// Destructeur
Object::~Object() {
    // Lib�ration des ressources si n�cessaire
}