#include "EntityManager.h"

EntityManager* EntityManager::instance = nullptr;

// Constructeur privé
EntityManager::EntityManager() {
    // Constructeur privé pour initialiser les valeurs si nécessaire
}

// Méthode statique pour accéder à l'instance unique
EntityManager* EntityManager::getInstance() {
    if (instance == nullptr) {
        instance = new EntityManager();
    }
    return instance;
}

void EntityManager::start()
{
    shared_ptr<Potion> potion = make_shared<Potion>();
    entities.push_back(potion);
    objects.push_back(potion);

    shared_ptr<Key> key = make_shared<Key>();
    entities.push_back(key);
    objects.push_back(key);
}

//Méthode pour vérifier si le joueur est en vie
bool EntityManager::isPlayerAlive()
{
    if (players[0]->getHp() > 0)
        return true;
    else
        return false;
}

// Méthode pour créer un joueur
void EntityManager::createPlayer(string path) 
{
    if (path == "") {
        shared_ptr<Player> player = make_shared<Player>();
        entities.push_back(player);
        players.push_back(player);
    }
    else {
        Texture texture;
        if (!texture.loadFromFile(path)) {
            cout << "sprite player introuvable" << endl;
        }

        shared_ptr<Player> player = make_shared<Player>();
        entities.push_back(player);
        players.push_back(player);
    }
}

// Méthode pour créer un patrouilleur
void EntityManager::createPatrolling(const int h, const float s, const vector<char> p) {
    shared_ptr<Patrolling> patrolling = make_shared<Patrolling>(h, s, p);
    entities.push_back(patrolling);
    enemies.push_back(patrolling);
    patrollings.push_back(patrolling);
}

// Méthode pour créer un chaser
void EntityManager::createChaser(const int h, const float s) {
    shared_ptr<Chaser> chaser = make_shared<Chaser>(h, s);
    entities.push_back(chaser);
    enemies.push_back(chaser);
    chasers.push_back(chaser);
}

// Méthode pour mettre à jour toutes les entités
void EntityManager::update(float deltaTime) {
    for (auto chaser : chasers) {
        chaser->moveUpdate(players[0]);  // Exemple : le premier joueur
    }

    for (auto entity : entities) {
        entity->update(deltaTime);
    }

    shared_ptr<Object> objToDestroy = nullptr;

    for (auto object : objects)
    {
        if (object->getSprite().getGlobalBounds().intersects(players[0]->getSprite().getGlobalBounds()))
        {
            object->interact(players[0]);
            objToDestroy = object;
        }
    }

    if (objToDestroy)
    {
        entities.erase(std::remove(entities.begin(), entities.end(), objToDestroy), entities.end());
        objects.erase(std::remove(objects.begin(), objects.end(), objToDestroy), objects.end());
    }
}

// Méthode pour dessiner toutes les entités
void EntityManager::draw(RenderWindow& window) {
    for (auto entity : entities) {
        entity->draw(window);
    }
}

// Méthode pour gérer les collisions
void EntityManager::collisions()
{
    for (auto enemy : enemies)
    {
        if (enemy->getSprite().getGlobalBounds().intersects(players[0]->getSprite().getGlobalBounds()))
        {
            players[0]->setHp(players[0]->getHp() - 0.5);
        }
    }
}

// Méthode pour supprimer une entité
void EntityManager::removeEntity(Entity* entity) 
{
    auto it = find_if(entities.begin(), entities.end(), [&](const shared_ptr<Entity>& e) 
        {
        return e.get() == entity;  // Compare les adresses mémoire
        });
    if (it != entities.end()) 
    {
        entities.erase(it);
    }
}

// Méthode pour supprimer l'instance de EntityManager
void EntityManager::deleteInstance() 
{
    delete instance;
    instance = nullptr;
}
