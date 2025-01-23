// Patrolling.cpp
#include "Patrolling.h"

// Constructor
Patrolling::Patrolling(const sf::Texture& t, Vector2f startPos, int h, float s, std::vector<char> p)
    : Enemy(t, startPos, h, s), patern(p), paternNum(0), paternPhase(0), frame(0)
{
    scale = { 1.8, 1.8 };
    this->getSprite().setTextureRect(IntRect(22, 388, 31, 27));
    this->getSprite().setScale(scale);
    this->getSprite().setOrigin(this->getSprite().getLocalBounds().width / 2, this->getSprite().getLocalBounds().height / 2);
}

Patrolling::Patrolling(int h, float s, std::vector<char> p)
    : Enemy(h, s), patern(p), paternNum(0), paternPhase(0)
{
    this->getSprite().setPosition(randomNumber(600, 1200), randomNumber(400, 800));
}


// Destructor
Patrolling::~Patrolling() {}

// Update method
void Patrolling::update(float deltaTime)
{
    frame++;
    if (frame / 12 > 7)
        frame = 0;

    this->getSprite().setTextureRect(IntRect(16 + 32 * static_cast<int>(frame / 12), 388, 31, 27));



    if (paternNum > 10)
    {
        paternNum = 0;
        paternPhase++;
    }

    int num = paternPhase % patern.size();

    switch (patern[num])
    {
    case 'U':
        this->getSprite().move(0, -this->getSpeed() * deltaTime);
        break;
    case 'D':
        this->getSprite().move(0, this->getSpeed() * deltaTime);
        break;
    case 'L':
        this->getSprite().move(-this->getSpeed() * deltaTime, 0);
        this->getSprite().setScale(Vector2f(-scale.x, scale.y));
        break;
    case 'R':
        this->getSprite().move(this->getSpeed() * deltaTime, 0);
        this->getSprite().setScale(Vector2f(scale.x, scale.y));
        break;
    }
    paternNum++;
}