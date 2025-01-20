#include "Potion.h"

Potion::Potion() : Object(), speedUpgrade(50) {
    // Initialisation sp�cifique si n�cessaire
}

Potion::~Potion() {
    // Lib�ration des ressources sp�cifiques si n�cessaire
}

void Potion::interact(shared_ptr<Player> player) {
    // V�rifie si le joueur entre en collision avec la potion
    if (this->getSprite().getGlobalBounds().intersects(player->getSprite().getGlobalBounds())) {
        // Si collision, am�liore la vitesse du joueur
        player->setSpeed(player->getSpeed() + speedUpgrade);
        cout << "Potion picked up! Speed increased by " << speedUpgrade << endl;
    }

    // Appel explicite du destructeur de la potion (g�n�ralement d�conseill�)
    // this->~Potion();  // Il est pr�f�rable de ne pas faire cela.
}
