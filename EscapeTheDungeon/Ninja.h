#ifndef NINJA_H
#define NINJA_H
#include "Enemy.h"
#include "Player.h"
using namespace sf;
using namespace std;


class Ninja : public Enemy
{
private:
	int frame;
	Vector2f scale;
	bool right;
	bool active;
	Vector2f movement;
	int moveCount;

public:
	// Constructor
	Ninja(const sf::Texture& t, Vector2f startPos, int h, float s);
	// Destructor
	~Ninja();
	// Update movement direction based on Player's position
	void moveUpdate(std::shared_ptr<Player> player, const std::vector<std::vector<char>>& map);
	// Update position based on calculated direction
	void update(float deltaTime) override;

};

#endif // NINJA_H