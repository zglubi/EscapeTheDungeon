// Enemy.cpp
#include "Enemy.h"

// Constructor
Enemy::Enemy(const sf::Texture& t, Vector2f startPos, int h, float s) : Entity(t, startPos), hp(h), hpMax(h), speed(s) {}

Enemy::Enemy(int h, float s)
    : Entity(sf::Color::Red, sf::Vector2f(25, 40)), hp(h), hpMax(h), speed(s) {
}

// Destructor
Enemy::~Enemy() {}

// Getters
int Enemy::getHp() const { return hp; }
int Enemy::getHpMax() const { return hpMax; }
float Enemy::getSpeed() const { return speed; }

// Setters
void Enemy::setHp(int h) { hp = h; }
void Enemy::setSpeed(float s) { speed = s; }

// Draw method
void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(this->getSprite());
}