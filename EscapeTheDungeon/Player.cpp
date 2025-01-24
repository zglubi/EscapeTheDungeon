// Player.cpp
#include "Player.h"

// Constructor
Player::Player(const sf::Texture& t, Vector2f startPos) : Entity(t, startPos), hp(100), hpMax(100), speed(200.0f), frame(0)
{
    clockActive = false;
    keyNum = 10;
    scale = { 1.7, 1.7 };
    this->getSprite().setTextureRect(IntRect(128, 74, 15, 21));
    this->getSprite().setScale(scale);
    this->getSprite().setOrigin(this->getSprite().getLocalBounds().width / 2, this->getSprite().getLocalBounds().height / 2);
    action = false;
}

// Destructor
Player::~Player() {}

// Getters
float Player::getHp() const { return hp; }
int Player::getHpMax() const { return hpMax; }
float Player::getSpeed() const { return speed; }
int Player::getFrame() const { return frame; }

// Setters
void Player::setHp(float hp) { this->hp = hp; }
void Player::setHpMax(int hpMax) { this->hpMax = hpMax; }
void Player::setSpeed(float speed) { this->speed = speed; }
void Player::setFrame(int frame) { this->frame = frame; }
void Player::addKey() { keyNum++; }

// Handle input
void Player::handleInput(float deltaTime, vector<vector<char>>& map)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->getSprite().move(sf::Vector2f(0, -speed * deltaTime));
        Vector2i sectionLeft = { static_cast<int>((this->getSprite().getGlobalBounds().left + 2) / 48), static_cast<int>(this->getSprite().getGlobalBounds().top / 48) };
        Vector2i sectionRight = { static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width - 2) / 48), static_cast<int>(this->getSprite().getGlobalBounds().top / 48) };
        Vector2i sectionMid = { static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width / 2) / 48), static_cast<int>(this->getSprite().getGlobalBounds().top / 48) };

        if (
            (map[sectionLeft.y][sectionLeft.x] == 'W' || map[sectionRight.y][sectionRight.x] == 'W' ||
                map[sectionLeft.y][sectionLeft.x] == 'C' || map[sectionRight.y][sectionRight.x] == 'C' ||
                map[sectionLeft.y][sectionLeft.x] == 'c' || map[sectionRight.y][sectionRight.x] == 'c' ||
                ((map[sectionLeft.y][sectionLeft.x] == 'r' &&
                    this->getSprite().getGlobalBounds().left - static_cast<int>(this->getSprite().getGlobalBounds().left / 48) * 48 < 15) ||
                    (map[sectionRight.y][sectionRight.x] == 'r' &&
                        this->getSprite().getGlobalBounds().left - static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width) / 48) * 48 < 15))) ||
            ((map[sectionLeft.y][sectionLeft.x] == 'D' || map[sectionRight.y][sectionRight.x] == 'D' ||
                map[sectionLeft.y][sectionLeft.x] == 'd' || map[sectionRight.y][sectionRight.x] == 'd') &&
                keyNum == 0))
        {
            this->getSprite().setPosition(Vector2f(this->getSprite().getPosition().x, (sectionLeft.y + 1) * 48 + this->getSprite().getGlobalBounds().height / 2));
        }

        else if ((map[sectionMid.y][sectionMid.x] == 'D' || map[sectionMid.y][sectionMid.x] == 'd') && keyNum > 0)
        {

            if (map[sectionMid.y][sectionMid.x] == 'd') 
            {
                map[sectionMid.y][sectionMid.x] = 'o';
                keyNum--;
            }
            else if (map[sectionMid.y][sectionMid.x + 2] == 'D' && map[sectionMid.y][sectionMid.x - 1] == 'D')
            {
                map[sectionMid.y - 1][sectionMid.x - 1] = 'F';
                map[sectionMid.y - 1][sectionMid.x] = 'O';
                map[sectionMid.y - 1][sectionMid.x + 1] = 'O';
                map[sectionMid.y - 1][sectionMid.x + 2] = 'F';

                map[sectionMid.y][sectionMid.x - 1] = 'W';
                map[sectionMid.y][sectionMid.x] = 'O';
                map[sectionMid.y][sectionMid.x + 1] = 'O';
                map[sectionMid.y][sectionMid.x + 2] = 'W';
                keyNum--;
            }
			else if (map[sectionMid.y][sectionMid.x - 2] == 'D' && map[sectionMid.y][sectionMid.x + 1] == 'D')
            {
                map[sectionMid.y - 1][sectionMid.x - 2] = 'F';
                map[sectionMid.y - 1][sectionMid.x - 1] = 'O';
                map[sectionMid.y - 1][sectionMid.x] = 'O';
                map[sectionMid.y - 1][sectionMid.x + 1] = 'F';

                map[sectionMid.y][sectionMid.x - 2] = 'W';
                map[sectionMid.y][sectionMid.x - 1] = 'O';
                map[sectionMid.y][sectionMid.x] = 'O';
                map[sectionMid.y][sectionMid.x + 1] = 'W';
                keyNum--;
            }
            else
            {
                this->getSprite().setPosition(Vector2f(this->getSprite().getPosition().x, (sectionLeft.y + 1) * 48 + this->getSprite().getGlobalBounds().height / 2));
            }
        }

        action = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->getSprite().move(sf::Vector2f(0, speed * deltaTime));
        Vector2i sectionLeft = { static_cast<int>((this->getSprite().getGlobalBounds().left + 2) / 48 ), static_cast<int>((this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height + 12) / 48) };
        Vector2i sectionRight = { static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width - 2) / 48), static_cast<int>((this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height + 12) / 48) };
        Vector2i sectionMid = { static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width / 2) / 48), static_cast<int>((this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height + 12) / 48) };
        if (
            (map[sectionLeft.y][sectionLeft.x] == 'W' || map[sectionRight.y][sectionRight.x] == 'W' ||
                map[sectionLeft.y][sectionLeft.x] == 'C' || map[sectionRight.y][sectionRight.x] == 'C' ||
                map[sectionLeft.y][sectionLeft.x] == 'c' || map[sectionRight.y][sectionRight.x] == 'c' ||
                ((map[sectionLeft.y][sectionLeft.x] == 'r' &&
                    this->getSprite().getGlobalBounds().left - static_cast<int>(this->getSprite().getGlobalBounds().left / 48) * 48 < 15) ||
                    (map[sectionRight.y][sectionRight.x] == 'r' &&
                        this->getSprite().getGlobalBounds().left - static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width) / 48) * 48 < 15))) ||
            ((map[sectionLeft.y][sectionLeft.x] == 'D' || map[sectionRight.y][sectionRight.x] == 'D' ||
                map[sectionLeft.y][sectionLeft.x] == 'd' || map[sectionRight.y][sectionRight.x] == 'd') &&
                keyNum == 0))
        {
            this->getSprite().setPosition(Vector2f(this->getSprite().getPosition().x, (sectionLeft.y) * 48 - this->getSprite().getGlobalBounds().height / 2 - 12));
        }
        else if ((map[sectionMid.y][sectionMid.x] == 'D' || map[sectionMid.y][sectionMid.x] == 'd') && keyNum > 0)
        {
            keyNum--;
            if (map[sectionMid.y][sectionMid.x] == 'D')
            {
                map[sectionMid.y][sectionMid.x - 1] = 'O';
                map[sectionMid.y][sectionMid.x] = 'O';
                map[sectionMid.y][sectionMid.x + 1] = 'O';
            }
            else
            {
                map[sectionMid.y][sectionMid.x] = 'o';
            }

        }

        action = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->getSprite().move(sf::Vector2f(speed * deltaTime, 0));
        Vector2i sectionUp = { static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width) / 48), static_cast<int>(this->getSprite().getGlobalBounds().top / 48) };
        Vector2i sectionDown = { static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width) / 48), static_cast<int>((this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height) / 48) };
        if (((map[sectionUp.y][sectionUp.x] == 'S' || map[sectionDown.y][sectionDown.x] == 'S'
            || map[sectionUp.y][sectionUp.x] == 'C' || map[sectionDown.y][sectionDown.x] == 'C'
            || map[sectionUp.y][sectionUp.x] == 'r' || map[sectionDown.y][sectionDown.x] == 'r'
            || map[sectionUp.y][sectionDown.x] == 'c' || map[sectionUp.y][sectionDown.x] == 'c') && this->getSprite().getGlobalBounds().left - static_cast<int>((this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width) / 48) * 48 < 15)
            || (map[sectionUp.y][sectionUp.x] == 'W' || map[sectionDown.y][sectionDown.x] == 'W')
            )
        {
            this->getSprite().setPosition(Vector2f((sectionUp.x) * 48 - this->getSprite().getGlobalBounds().width / 2, this->getSprite().getPosition().y));
        }

        this->getSprite().setScale(Vector2f(scale.x, scale.y));
        action = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->getSprite().move(sf::Vector2f(-speed * deltaTime, 0));
        Vector2i sectionUp = { static_cast<int>(this->getSprite().getGlobalBounds().left / 48), static_cast<int>(this->getSprite().getGlobalBounds().top / 48) };
        Vector2i sectionDown = { static_cast<int>(this->getSprite().getGlobalBounds().left / 48), static_cast<int>((this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height) / 48) };
        if ((((map[sectionUp.y][sectionUp.x] == 'S' || map[sectionDown.y][sectionDown.x] == 'S') && this->getSprite().getGlobalBounds().left - static_cast<int>(this->getSprite().getGlobalBounds().left / 48) * 48 < 15)
            || map[sectionUp.y][sectionUp.x] == 'C' || map[sectionDown.y][sectionDown.x] == 'C')
            || (map[sectionUp.y][sectionUp.x] == 'W' || map[sectionDown.y][sectionDown.x] == 'W')
            || ((map[sectionUp.y][sectionUp.x] == 'r' || map[sectionDown.y][sectionDown.x] == 'r') && this->getSprite().getGlobalBounds().left - static_cast<int>(this->getSprite().getGlobalBounds().left / 48) * 48 < 15)
            )
        {
            if (map[sectionUp.y][sectionUp.x] == 'W' || map[sectionDown.y][sectionDown.x] == 'W' || map[sectionUp.y][sectionUp.x] == 'C' || map[sectionDown.y][sectionDown.x] == 'C')
            {
                this->getSprite().setPosition(Vector2f((sectionUp.x + 1) * 48 + this->getSprite().getGlobalBounds().width / 2, this->getSprite().getPosition().y));
            }
            else
            {
                this->getSprite().setPosition(Vector2f(sectionUp.x * 48 + 15 + this->getSprite().getGlobalBounds().width / 2, this->getSprite().getPosition().y));
            }
        }

        this->getSprite().setScale(Vector2f(-scale.x, scale.y));
        action = true;
    }

	Vector2f sectionUL = { this->getSprite().getGlobalBounds().left / 48, this->getSprite().getGlobalBounds().top / 48 };
	Vector2f sectionUR = { (this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width) / 48, this->getSprite().getGlobalBounds().top / 48 };
	Vector2f sectionDL = { this->getSprite().getGlobalBounds().left / 48, (this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height) / 48 };
	Vector2f sectionDR = { (this->getSprite().getGlobalBounds().left + this->getSprite().getGlobalBounds().width) / 48, (this->getSprite().getGlobalBounds().top + this->getSprite().getGlobalBounds().height) / 48 };

	if (map[sectionUL.y][sectionUL.x] == '4' || map[sectionUR.y][sectionUR.x] == '4' || map[sectionDL.y][sectionDL.x] == '4' || map[sectionDR.y][sectionDR.x] == '4')
	{
		this->setHp(this->getHp() - 10);
	}
}

// Update method
void Player::update(float deltaTime)
{
    if (speedClock.getElapsedTime().asSeconds() < 5 && clockActive)
    {
        speed = 300;
    }
    else
    {
        speed = 200;
    }
    if (action)
        frame++;
    if (frame / 6 > 7)
        frame = 0;
    this->getSprite().setTextureRect(IntRect(128 + 16 * static_cast<int>(frame / 6), 74, 15, 21));
    action = false;
}

// Draw method
void Player::draw(sf::RenderWindow& window)
{
    window.draw(this->getSprite());
}

void Player::resetClock()
{
    if (!clockActive)
        clockActive = true;
    speedClock.restart();
}