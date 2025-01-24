#include "EntityManager.h"

EntityManager* EntityManager::instance = nullptr;

// Constructeur priv?
EntityManager::EntityManager()
{
    if (!playerTexture.loadFromFile("Assets/Tileset/Tileset.png"))
    {
        cout << "tileset introuvable" << endl;
    }

    if (!patrollingTexture.loadFromFile("Assets/Tileset/Tileset.png"))
    {
        cout << "tileset introuvable" << endl;
    }
    if (!chaserTexture.loadFromFile("Assets/Tileset/Tileset.png"))
    {
        cout << "tileset introuvable" << endl;
    }

    if (!potionTexture.loadFromFile("Assets/Tileset/Tileset.png"))
    {
        cout << "tileset introuvable" << endl;
    }
    if (!keyTexture.loadFromFile("Assets/Tileset/key.png"))
    {
        cout << "tileset introuvable" << endl;
    }

	if (!winBgTexture.loadFromFile("Assets/Background/win.png"))
	{
		cout << "tileset introuvable" << endl;
	}
	winBg.setTexture(winBgTexture);
	winBg.setPosition(-100, 0);

	if (!loseBgTexture.loadFromFile("Assets/Background/lose.png"))
	{
		cout << "tileset introuvable" << endl;
	}
	loseBg.setTexture(loseBgTexture);
	loseBg.setPosition(-100, 0);
}

// M?thode statique pour acc?der ? l'instance unique
EntityManager* EntityManager::getInstance() 
{
    if (instance == nullptr) 
    {
        instance = new EntityManager();
    }
    return instance;
}

void EntityManager::start(vector<vector<char>> map)
{
    int potionsToPlace = 3;

    while (potionsToPlace > 0)
    {
        Vector2f position = { static_cast<float>(randomNumber(96, 1338)), static_cast<float>(randomNumber(96, 950)) };
        Vector2i section1 = { static_cast<int>(position.x / 48.0), static_cast<int>(position.y / 48.0) };
        Vector2i section2 = { static_cast<int>((position.x + 23) / 48), static_cast<int>((position.y + 25) / 48)};

        if (map[section1.y][section1.x] == 'F' && map[section2.y][section2.x] == 'F')
        {
            shared_ptr<Potion> potion = make_shared<Potion>(potionTexture, position);
            entities.push_back(potion);
            objects.push_back(potion);
            potionsToPlace--;
        }
    }

    shared_ptr<Key> key = make_shared<Key>(keyTexture, Vector2f(1000, 800));
    entities.push_back(key);
    objects.push_back(key);

    shared_ptr<Key> key1 = make_shared<Key>(keyTexture, Vector2f(250, 450));
    entities.push_back(key1);
    objects.push_back(key1);
}

//M?thode pour v?rifier si le joueur est en vie
bool EntityManager::isPlayerAlive(bool& isRunning)
{
    if (players[0]->getHp() > 0)
        return true;
    else
    {
		isRunning = false;
		return false;
    }
}

// M?thode pour cr?er un joueur
void EntityManager::createPlayer(string path)
{
    shared_ptr<Player> player = make_shared<Player>(playerTexture, Vector2f(650, 800));
    entities.push_back(player);
    players.push_back(player);
}

// M?thode pour cr?er un patrouilleur
void EntityManager::createPatrolling(Vector2f startPos, const int h, const float s, const vector<char> p)
{
    shared_ptr<Patrolling> patrolling = make_shared<Patrolling>(patrollingTexture, startPos, h, s, p);
    entities.push_back(patrolling);
    enemies.push_back(patrolling);
    patrollings.push_back(patrolling);
}

// M?thode pour cr?er un chaser
void EntityManager::createChaser(Vector2f startPos, const int h, const float s) {
    shared_ptr<Chaser> chaser = make_shared<Chaser>(chaserTexture, startPos, h, s);
    entities.push_back(chaser);
    enemies.push_back(chaser);
    chasers.push_back(chaser);
}

void EntityManager::createNinja(Vector2f startPos, const int h, const float s)
{
	shared_ptr<Ninja> ninja = make_shared<Ninja>(chaserTexture, startPos, h, s);
	entities.push_back(ninja);
	enemies.push_back(ninja);
	ninjas.push_back(ninja);
}

// M?thode pour mettre ? jour toutes les entit?s
void EntityManager::update(float deltaTime, vector<vector<char>>& map) {
    for (auto chaser : chasers) {
        chaser->moveUpdate(players[0], map);  // Exemple : le premier joueur
    }
    for (auto ninja : ninjas)
    {
		ninja->moveUpdate(players[0], map);
    }
    for (auto entity : entities) {
        entity->update(deltaTime);
    }
    players[0]->handleInput(deltaTime, map);
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

// M?thode pour dessiner toutes les entit?s
void EntityManager::draw(RenderWindow& window) {
    for (auto entity : entities)
    {
        entity->draw(window);
    }
}

// M?thode pour g?rer les collisions
void EntityManager::collisions()
{
    for (auto enemy : enemies)
    {
        if (enemy->getSprite().getGlobalBounds().intersects(players[0]->getSprite().getGlobalBounds()))
        {
            players[0]->setHp(players[0]->getHp() - 2.5);
        }
    }
}

// M?thode pour supprimer une entit?
void EntityManager::removeEntity(Entity* entity)
{
    auto it = find_if(entities.begin(), entities.end(), [&](const shared_ptr<Entity>& e)
        {
            return e.get() == entity;  // Compare les adresses m?moire
        });
    if (it != entities.end())
    {
        entities.erase(it);
    }
}

// M?thode pour supprimer l'instance de EntityManager
void EntityManager::deleteInstance()
{
    delete instance;
    instance = nullptr;
}

void EntityManager::winCheck(bool& isRunning)
{
    if (players[0]->getSprite().getPosition().y < 60)
    {
		cout << "You win!" << endl;
        isRunning = false;
    }
}

void EntityManager::winScreen(RenderWindow& window)
{
    if (players[0]->getHp() > 0)
    {
        window.draw(winBg);
    }

    else
    {
        window.draw(loseBg);
    }
}

void EntityManager::clear()
{
	players.clear();
	patrollings.clear();
	chasers.clear();
	ninjas.clear();
	objects.clear();
	entities.clear();
}