// Patrolling.cpp
#include "Patrolling.h"

// Constructor
Patrolling::Patrolling(const sf::Texture& t, int h, float s, std::vector<char> p)
    : Enemy(t, h, s), patern(p), paternNum(0), paternPhase(0) {
}

Patrolling::Patrolling(int h, float s, std::vector<char> p)
    : Enemy(h, s), patern(p), paternNum(0), paternPhase(0)  {
}


// Destructor
Patrolling::~Patrolling() {}

// Update method
void Patrolling::update(float deltaTime)
{
    if (paternNum > 100)
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
        break;
    case 'R':
        this->getSprite().move(this->getSpeed() * deltaTime, 0);
        break;
    }

    paternNum++;
}