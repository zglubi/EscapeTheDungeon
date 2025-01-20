#include "Objects.h"

// Constructeur
Object::Object() : Entity(sf::Color::Blue, sf::Vector2f(25, 25))
{
    // Initialisation si nécessaire
}

// Destructeur
Object::~Object() {
    // Libération des ressources si nécessaire
}