// Patrolling.h
#ifndef PATROLLING_H
#define PATROLLING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"

class Patrolling : public Enemy
{
private:
    std::vector<char> patern;
    int paternNum;
    int paternPhase;
    Vector2f scale;
    int frame;

public:
    // Constructor and Destructor
    Patrolling(const sf::Texture& t, Vector2f startPos, int h, float s, std::vector<char> p);
    Patrolling(int h, float s, std::vector<char> p);
    ~Patrolling();

    // Update method
    void update(float deltaTime) override;
};

#endif // PATROLLING_H