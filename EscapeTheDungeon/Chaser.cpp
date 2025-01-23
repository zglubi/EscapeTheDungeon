// Chaser.cpp
#include "Chaser.h"

// Constructor
Chaser::Chaser(const sf::Texture& t, Vector2f startPos, int h, float s)
    : Enemy(t, startPos, h, s), moveX(0), moveY(0), frame(0)
{
    scale = { 1.5, 1.5 };
    this->getSprite().setTextureRect(IntRect(16, 430, 31, 33));
    this->getSprite().setScale(scale);
    this->getSprite().setOrigin(this->getSprite().getLocalBounds().width / 2, this->getSprite().getLocalBounds().height / 2);
}

// Destructor
Chaser::~Chaser()
{
}

// Update movement direction based on Player's position
void Chaser::moveUpdate(std::shared_ptr<Player> player)
{
    if (player->getSprite().getPosition().x - 5 > this->getSprite().getPosition().x)
        moveX = 1;
    else if (player->getSprite().getPosition().x + 5 < this->getSprite().getPosition().x)
        moveX = -1;
    else
        moveX = 0;

    if (player->getSprite().getPosition().y - 5 > this->getSprite().getPosition().y)
        moveY = 1;
    else if (player->getSprite().getPosition().y + 5 < this->getSprite().getPosition().y)
        moveY = -1;
    else
        moveY = 0;

    if (moveX != 0 && moveY != 0)
    {
        this->getSprite().setScale(Vector2f(scale.x * moveX, this->getSprite().getScale().y));
    }
}

// Update position based on calculated direction
void Chaser::update(float deltaTime)
{
    frame++;
    if (frame / 12 > 7)
        frame = 0;
    this->getSprite().setTextureRect(IntRect(16 + 32 * static_cast<int>(frame / 12), 430, 31, 33));

    this->getSprite().move(this->getSpeed() * moveX * deltaTime, this->getSpeed() * moveY * deltaTime);
}