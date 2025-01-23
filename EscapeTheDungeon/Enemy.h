// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Enemy : public Entity
{
private:
    int hp;
    int hpMax;
    float speed;

public:
    // Constructor and Destructor
    Enemy(const sf::Texture& t, Vector2f startPos, int h, float s);
    Enemy(int h, float s);
    ~Enemy();

    // Getters
    int getHp() const;
    int getHpMax() const;
    float getSpeed() const;

    // Setters
    void setHp(int h);
    void setSpeed(float s);

    // Core Methods
    void update(float deltaTime) override = 0;
    void draw(sf::RenderWindow& window) override;
};

#endif // ENEMY_H