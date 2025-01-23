// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

class Player : public Entity
{
private:
    float hp;
    int hpMax;
    float speed;
    int frame;
    Clock speedClock;
    bool clockActive;
    int keyNum;
    Vector2f scale;
    bool action;

public:
    // Constructor and Destructor
    Player(const sf::Texture& t, Vector2f startPos);
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
    void addKey();

    // Core Methods
    void handleInput(float deltaTime, vector<vector<char>>& map);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void resetClock();
};

#endif // PLAYER_H