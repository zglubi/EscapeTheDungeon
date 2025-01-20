// Player.cpp
#include "Player.h"

// Constructor
Player::Player(const sf::Texture& t) : Entity(t), hp(100), hpMax(100), speed(200.0f), frame(0)
{
    this->getSprite().setPosition(Vector2f(200, 200));
}

Player::Player() : Entity(sf::Color::Green, sf::Vector2f(50, 75))
, hp(100), hpMax(100), speed(200.0f), frame(0)
{
    this->getSprite().setPosition(Vector2f(200, 200));
}

// Destructor
Player::~Player() {}

// Getters
int Player::getHp() const { return hp; }
int Player::getHpMax() const { return hpMax; }
float Player::getSpeed() const { return speed; }
int Player::getFrame() const { return frame; }

// Setters
void Player::setHp(int hp) { this->hp = hp; }
void Player::setHpMax(int hpMax) { this->hpMax = hpMax; }
void Player::setSpeed(float speed) { this->speed = speed; }
void Player::setFrame(int frame) { this->frame = frame; }

// Handle input
void Player::handleInput(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->getSprite().move(sf::Vector2f(0, -speed * deltaTime));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->getSprite().move(sf::Vector2f(0, speed * deltaTime));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->getSprite().move(sf::Vector2f(speed * deltaTime, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->getSprite().move(sf::Vector2f(-speed * deltaTime, 0));
    }
}

// Update method
void Player::update(float deltaTime)
{
    handleInput(deltaTime);
    frame++;
}

// Draw method
void Player::draw(sf::RenderWindow& window)
{
    window.draw(this->getSprite());
}
