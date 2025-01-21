#include "Potion.h"

Potion::Potion() : Object(), speedUpgrade(50) 
{
    this->getSprite().setPosition(randomNumber(600, 1200), randomNumber(400, 800));
    count = 0;
}

Potion::~Potion() 
{
    // Libération des ressources spécifiques si nécessaire
}

void Potion::interact(shared_ptr<Player> player) 
{

    player->resetClock();
    cout << "Potion picked up! Speed increased by " << speedUpgrade << endl;

    // this->~Potion();  // Il est préférable de ne pas faire cela.
}

void Potion::draw(RenderWindow& window)
{
    window.draw(this->getSprite());
}

void Potion::update(float deltaTime)
{
    count++;
}