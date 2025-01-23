// Entity.cpp
#include "Entity.h"

// Constructor
Entity::Entity(const Texture& t, Vector2f startPos) : texture(t)
{
    sprite.setTexture(texture);
    sprite.setPosition(startPos);
}

// Constructeur par d?faut
Entity::Entity(const sf::Color& color, const sf::Vector2f& size)
{
    sf::Image image;
    image.create(static_cast<unsigned int>(size.x), static_cast<unsigned int>(size.y), color);
    texture.loadFromImage(image);
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