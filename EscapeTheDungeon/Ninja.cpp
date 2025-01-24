#include "Ninja.h"

Ninja::Ninja(const sf::Texture& t, Vector2f startPos, int h, float s) : Enemy(t, startPos, h, s), frame(0), scale(2.5, 2.5), right(true), active(false), movement(0, 0), moveCount(0)
{
	this->getSprite().setTextureRect(IntRect(369, 349, 16, 18));
	this->getSprite().setScale(scale);
	this->getSprite().setOrigin(this->getSprite().getLocalBounds().width / 2, this->getSprite().getLocalBounds().height / 2);
}

Ninja::~Ninja()
{
}

void Ninja::moveUpdate(shared_ptr<Player> player, const vector<vector<char>>& map)
{
	if (((player->getSprite().getPosition().x - this->getSprite().getPosition().x < 200 && player->getSprite().getPosition().x - this->getSprite().getPosition().x > -200) &&
		(player->getSprite().getPosition().y - this->getSprite().getPosition().y < 200 && player->getSprite().getPosition().y - this->getSprite().getPosition().y > -200)) &&
		!active)
	{
		active = true;
		movement = { player->getSprite().getPosition().x - this->getSprite().getPosition().x, player->getSprite().getPosition().y - this->getSprite().getPosition().y };
		if (abs(movement.x) > abs(movement.y))
		{
			movement = { movement.x / abs(movement.x), movement.y / abs(movement.x) };
		}
		else
		{
			movement = { movement.x / abs(movement.y), movement.y / abs(movement.y) };
		}
	}
	
	if (!active)
	{
		if (moveCount > 50)
		{
			moveCount = 0;
			right = !right;
		}
		
		if (right)
		{
			movement.x = 0.1;
			this->getSprite().setScale(Vector2f(scale.x, scale.y));
		}
		else
		{
			movement.x = -0.1;
			this->getSprite().setScale(Vector2f(-scale.x, scale.y));
		}

		moveCount++;
	}
}

void Ninja::update(float deltaTime)
{
	frame++;
	if (frame / 6 > 5)
		frame = 0;
	this->getSprite().setTextureRect(IntRect(369 + 16 * static_cast<int>(frame / 6), 349, 16, 18));
	this->getSprite().move(movement.x * this->getSpeed() * deltaTime, movement.y * this->getSpeed() * deltaTime);
}