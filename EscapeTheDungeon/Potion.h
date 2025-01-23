#ifndef POTION_H
#define POTION_H

#include "Object.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using namespace sf;

class Potion : public Object
{
private:
    int speedUpgrade;  // La valeur d'am?lioration de la vitesse
    int count;

public:
    Potion(Texture t, Vector2f startPos);  // Constructeur
    ~Potion();  // Destructeur

    // Impl?mentation de la m?thode interact
    void interact(shared_ptr<Player> player) override;
    void draw(RenderWindow& window) override;
    void update(float deltaTime) override;
};

#endif // POTION_H