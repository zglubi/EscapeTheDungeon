// Entity.cpp
#include "Entity.h"

// Constructor
Entity::Entity(const Texture& t) : texture(t)
{
    sprite.setTexture(texture);
}

// Destructor
Entity::~Entity() {}


// Getter for the sprite
Sprite& Entity::getSprite()
{
    return sprite;
}

// Setter for the texture
void Entity::setTexture(const Texture& t)
{
    texture = t;
    sprite.setTexture(texture);
}
