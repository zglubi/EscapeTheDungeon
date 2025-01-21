// Key.cpp
#include "Key.h"

Key::Key() : count(0)
{
    this->getSprite().setPosition(randomNumber(600, 1200), randomNumber(400, 800));
}

Key::~Key() {}

void Key::interact(std::shared_ptr<Player> player)
{
    player->addKey();
    std::cout << "key grabbed";
}

void Key::draw(sf::RenderWindow& window)
{
    window.draw(this->getSprite());
}

void Key::update(float deltaTime)
{
    count++;
}
