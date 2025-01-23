#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;
using namespace std;

class Interactable
{
public:
	virtual void interact(shared_ptr<Player> player) = 0;
};

#endif