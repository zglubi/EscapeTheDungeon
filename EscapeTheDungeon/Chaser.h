// Chaser.h
#ifndef CHASER_H
#define CHASER_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"

class Chaser : public Enemy
{
private:
    int moveX;
    int moveY;

public:
    // Constructor and Destructor
    Chaser(const sf::Texture& t, int h, float s);
    Chaser(int h, float s);
    ~Chaser();

    // Methods
    void moveUpdate(Player& player);
    void update(float deltaTime) override;
};

#endif // CHASER_H
