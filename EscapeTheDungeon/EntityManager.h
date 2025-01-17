#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"
#include "Patrolling.h"
#include "Chaser.h"

using namespace sf;
using namespace std;

class EntityManager 
{
private:
    static EntityManager* instance;  // Instance unique

    vector<shared_ptr<Entity>> entities;    // Liste de toutes les entit�s
    vector<shared_ptr<Player>> players;     // Liste des joueurs
    vector<shared_ptr<Enemy>> enemies;      // Liste des ennemis
    vector<shared_ptr<Patrolling>> patrollings;  // Liste des patrouilleurs
    vector<shared_ptr<Chaser>> chasers;     // Liste des chasers

    // Constructeur priv� pour emp�cher la cr�ation d'instances ext�rieures
    EntityManager();

public:
    // M�thode statique pour acc�der � l'instance unique
    static EntityManager* getInstance();

    void start();

    //M�thode pour v�rifier si le joueur est en vie
    bool isPlayerAlive();

    // M�thode pour cr�er un joueur
    void createPlayer(string path = "");

    // M�thode pour cr�er un patrouilleur
    void createPatrolling(const int h, const float s, const vector<char> p);

    // M�thode pour cr�er un chaser
    void createChaser(const int h, const float s);

    // M�thode pour mettre � jour toutes les entit�s
    void update(float deltaTime);

    // M�thode pour dessiner toutes les entit�s
    void draw(RenderWindow& window);

    // M�thode pour g�rer les collisions
    void collisions();

    // M�thode pour supprimer une entit�
    void removeEntity(Entity* entity);

    // M�thode pour supprimer l'instance de EntityManager
    static void deleteInstance();
};

#endif // ENTITYMANAGER_H
