#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

public:
    // Constructeur
    Button(const sf::Texture& t, const sf::Vector2f& pos);

    // M�thode pour v�rifier si le bouton est cliqu�
    bool isClicked(const sf::RenderWindow& window) const;

    // M�thode pour dessiner le bouton
    void draw(sf::RenderWindow& window) const;

    // M�thode pour d�finir la position du bouton
    void setPosition(const sf::Vector2f& pos) {
        position = pos;
        sprite.setPosition(position);
    }
};

#endif // BUTTON_H
