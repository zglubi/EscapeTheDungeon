#include "Potion.h"

Potion::Potion() : Object(), speedUpgrade(50) {
    // Initialisation spécifique si nécessaire
}

Potion::~Potion() {
    // Libération des ressources spécifiques si nécessaire
}

void Potion::interact(shared_ptr<Player> player) {
    // Vérifie si le joueur entre en collision avec la potion
    if (this->getSprite().getGlobalBounds().intersects(player->getSprite().getGlobalBounds())) {
        // Si collision, améliore la vitesse du joueur
        player->setSpeed(player->getSpeed() + speedUpgrade);
        cout << "Potion picked up! Speed increased by " << speedUpgrade << endl;
    }

    // Appel explicite du destructeur de la potion (généralement déconseillé)
    // this->~Potion();  // Il est préférable de ne pas faire cela.
}
