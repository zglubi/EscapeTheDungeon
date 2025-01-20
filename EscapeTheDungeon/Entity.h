#pragma once// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "RandomNumber.h"
using namespace sf;

class Entity
{
private:
    Texture texture;
    Sprite sprite;

public:
    // Constructor
    Entity(const Texture& t);

    // Constructeur par défaut
    Entity(const sf::Color& color = sf::Color::Blue, const sf::Vector2f& size = sf::Vector2f(50.f, 75.f));

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