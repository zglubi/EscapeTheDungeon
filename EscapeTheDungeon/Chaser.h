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
    int frame;
    Vector2f scale;

public:
    // Constructor and Destructor
    Chaser(const sf::Texture& t, Vector2f startPos, int h, float s);
    Chaser(int h, float s);
    ~Chaser();

    // Methods
    void moveUpdate(std::shared_ptr<Player> player);
    void update(float deltaTime) override;
};

#endif // CHASER_H