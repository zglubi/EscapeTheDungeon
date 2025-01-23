// Key.cpp
#include "Key.h"

Key::Key(Texture t, Vector2f startPos) : Object(t, startPos), count(0)
{

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