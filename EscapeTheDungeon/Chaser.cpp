// Chaser.cpp
#include "Chaser.h"

// Constructor
//Chaser::Chaser(const sf::Texture& t, int h, float s)
//    : Enemy(t, h, s), moveX(0), moveY(0)
//{
//}

Chaser::Chaser(int h, float s)
    : Enemy(h, s), moveX(0), moveY(0)
{
    this->getSprite().setPosition(randomNumber(0, 1200), randomNumber(0, 800));
}

// Destructor
Chaser::~Chaser()
{
}

// Update movement direction based on Player's position
void Chaser::moveUpdate(std::shared_ptr<Player> player)
{
    if (player->getSprite().getPosition().x > this->getSprite().getPosition().x)
        moveX = 1;
    else if (player->getSprite().getPosition().x < this->getSprite().getPosition().x)
        moveX = -1;
    else
        moveX = 0;

    if (player->getSprite().getPosition().y > this->getSprite().getPosition().y)
        moveY = 1;
    else if (player->getSprite().getPosition().y < this->getSprite().getPosition().y)
        moveY = -1;
    else
        moveY = 0;
}

// Update position based on calculated direction
void Chaser::update(float deltaTime)
{
    this->getSprite().move(this->getSpeed() * moveX * deltaTime, this->getSpeed() * moveY * deltaTime);
}