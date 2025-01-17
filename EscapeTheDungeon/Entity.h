#pragma once// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Entity
{
private:
    Texture texture;
    Sprite sprite;

public:
    // Constructor
    Entity(const Texture& t);

    // Destructor
    virtual ~Entity();

    // Methods
    virtual void update(float deltaTime) = 0;

    virtual void draw(RenderWindow& window) = 0;

    // Getter for the sprite
    Sprite& getSprite();

    // Setter for the texture
    void setTexture(const Texture& t);
};

#endif // ENTITY_H