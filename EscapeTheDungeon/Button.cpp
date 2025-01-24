#include "Button.h"

// Constructeur
Button::Button(const sf::Texture& t, const sf::Vector2f& pos) : texture(t), position(pos) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(0.3, 0.3);
}

// M�thode pour v�rifier si le bouton est cliqu�
bool Button::isClicked(const sf::RenderWindow& window) const {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

// M�thode pour dessiner le bouton
void Button::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
