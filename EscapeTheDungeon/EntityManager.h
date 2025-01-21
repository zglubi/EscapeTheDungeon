#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"
#include "Patrolling.h"
#include "Chaser.h"
#include "Potion.h"
#include "Key.h"

using namespace sf;
using namespace std;

class EntityManager 
{
private:
    static EntityManager* instance;  // Instance unique

    vector<shared_ptr<Entity>> entities;    // Liste de toutes les entités

    vector<shared_ptr<Player>> players;     // Liste des joueurs

    vector<shared_ptr<Enemy>> enemies;      // Liste des ennemis
    vector<shared_ptr<Patrolling>> patrollings;  // Liste des patrouilleurs
    vector<shared_ptr<Chaser>> chasers;     // Liste des chasers

    vector<shared_ptr<Object>> objects;


    // Constructeur privé pour empêcher la création d'instances extérieures
    EntityManager();

public:
    // Méthode statique pour accéder à l'instance unique
    static EntityManager* getInstance();

    void start();

    //Méthode pour vérifier si le joueur est en vie
    bool isPlayerAlive();

    // Méthode pour créer un joueur
    void createPlayer(string path = "");

    // Méthode pour créer un patrouilleur
    void createPatrolling(const int h, const float s, const vector<char> p);

    // Méthode pour créer un chaser
    void createChaser(const int h, const float s);

    // Méthode pour mettre à jour toutes les entités
    void update(float deltaTime);

    // Méthode pour dessiner toutes les entités
    void draw(RenderWindow& window);

    // Méthode pour gérer les collisions
    void collisions();

    // Méthode pour supprimer une entité
    void removeEntity(Entity* entity);

    // Méthode pour supprimer l'instance de EntityManager
    static void deleteInstance();
};

#endif // ENTITYMANAGER_H
