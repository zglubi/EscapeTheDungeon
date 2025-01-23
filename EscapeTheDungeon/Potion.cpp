#include "Potion.h"

Potion::Potion(Texture t, Vector2f startPos) : Object(t, startPos), speedUpgrade(50)
{
    this->getSprite().setTextureRect(IntRect(307, 339, 9, 10));
    this->getSprite().setScale(Vector2f(2.5, 2.5));
    count = 0;
}

Potion::~Potion()
{
    // Lib?ration des ressources sp?cifiques si n?cessaire
}

void Potion::interact(shared_ptr<Player> player)
{

    player->resetClock();
}

void Potion::draw(RenderWindow& window)
{
    window.draw(this->getSprite());
}

void Potion::update(float deltaTime)
{
    count++;
}