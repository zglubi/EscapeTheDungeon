// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
private:
    float hp;
    int hpMax;
    float speed;
    int frame;

public:
    // Constructor and Destructor
    Player(const sf::Texture& t);
    Player();
    ~Player();

    // Getters
    float getHp() const;
    int getHpMax() const;
    float getSpeed() const;
    int getFrame() const;

    // Setters
    void setHp(float hp);
    void setHpMax(int hpMax);
    void setSpeed(float speed);
    void setFrame(int frame);

    // Core Methods
    void handleInput(float deltaTime);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};

#endif // PLAYER_H
