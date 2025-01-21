// Key.h
#ifndef KEY_H
#define KEY_H

#include "Object.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"

class Key : public Object
{
private:
    int count;

public:
    Key();
    ~Key();

    void interact(std::shared_ptr<Player> player) override;
    void draw(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
};

#endif // KEY_H
