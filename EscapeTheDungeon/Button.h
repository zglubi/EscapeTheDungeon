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

    // Méthode pour vérifier si le bouton est cliqué
    bool isClicked(const sf::RenderWindow& window) const;

    // Méthode pour dessiner le bouton
    void draw(sf::RenderWindow& window) const;

    // Méthode pour définir la position du bouton
    void setPosition(const sf::Vector2f& pos) {
        position = pos;
        sprite.setPosition(position);
    }
};

#endif // BUTTON_H
