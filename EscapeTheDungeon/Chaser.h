#ifndef CHASER_H
#define CHASER_H

#include "Enemy.h"
#include "Player.h"
#include <memory>
#include <vector>

class Chaser : public Enemy
{
private:
    int moveX;
    int moveY;
    int frame;
    Vector2f scale;

    std::vector<Vector2f> findPath(Vector2f start, Vector2f goal, const std::vector<std::vector<char>>& map);

public:
    // Constructor
    Chaser(const sf::Texture& t, Vector2f startPos, int h, float s);

    // Destructor
    ~Chaser();

    // Update movement direction based on Player's position
    void moveUpdate(std::shared_ptr<Player> player, const std::vector<std::vector<char>>& map);

    // Update position based on calculated direction
    void update(float deltaTime) override;
};

#endif // CHASER_H
