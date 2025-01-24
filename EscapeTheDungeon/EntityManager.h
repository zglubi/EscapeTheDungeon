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
#include "Ninja.h"

using namespace sf;
using namespace std;

class EntityManager
{
private:
    static EntityManager* instance;  // Instance unique

    vector<shared_ptr<Entity>> entities;    // Liste de toutes les entit?s

    vector<shared_ptr<Player>> players;     // Liste des joueurs
    Texture playerTexture;

    vector<shared_ptr<Enemy>> enemies;      // Liste des ennemis
    Texture patrollingTexture;
    Texture chaserTexture;
	Texture ninjaTexture;
    vector<shared_ptr<Patrolling>> patrollings;  // Liste des patrouilleurs
    vector<shared_ptr<Chaser>> chasers;     // Liste des chasers
	vector<shared_ptr<Ninja>> ninjas;       // Liste des ninjas

    vector<shared_ptr<Object>> objects;
    Texture potionTexture;
    Texture keyTexture;

	Texture winBgTexture;
	Sprite winBg;
	Texture loseBgTexture;
	Sprite loseBg;

    // Constructeur priv? pour emp?cher la cr?ation d'instances ext?rieures
    EntityManager();

public:
    // M?thode statique pour acc?der ? l'instance unique
    static EntityManager* getInstance();

    void start(vector<vector<char>> map);

    //M?thode pour v?rifier si le joueur est en vie
    bool isPlayerAlive(bool& isRunning);

    // M?thode pour cr?er un joueur
    void createPlayer(string path = "");

    // M?thode pour cr?er un patrouilleur
    void createPatrolling(Vector2f startPos, const int h, const float s, const vector<char> p);

    // M?thode pour cr?er un chaser
    void createChaser(Vector2f startPos, const int h, const float s);

	void createNinja(Vector2f startPos, const int h, const float s);

    // M?thode pour mettre ? jour toutes les entit?s
    void update(float deltaTime, vector<vector<char>>& map);

    // M?thode pour dessiner toutes les entit?s
    void draw(RenderWindow& window);

    // M?thode pour g?rer les collisions
    void collisions();

    // M?thode pour supprimer une entit?
    void removeEntity(Entity* entity);

    // M?thode pour supprimer l'instance de EntityManager
    static void deleteInstance();

	void winCheck(bool& isRunning);

	void winScreen(RenderWindow& window);
};

#endif // ENTITYMANAGER_H#pragma once