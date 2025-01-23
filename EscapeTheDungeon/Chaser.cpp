// Chaser.cpp
#include "Chaser.h"
#include <queue>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <tuple>

// Définir une fonction de hachage pour std::pair<int, int>
namespace std {
    template <>
    struct hash<std::pair<int, int>> {
        std::size_t operator()(const std::pair<int, int>& v) const {
            return std::hash<int>()(v.first) ^ (std::hash<int>()(v.second) << 1);
        }
    };
}

// Convertir sf::Vector2f en std::pair<int, int> (coordonnées de tuiles)
std::pair<int, int> toTile(const sf::Vector2f& v) {
    return { static_cast<int>(v.x / 48), static_cast<int>(v.y / 48) };
}

// Convertir std::pair<int, int> en sf::Vector2f (coordonnées en pixels)
sf::Vector2f toPixel(const std::pair<int, int>& p) {
    return { static_cast<float>(p.first * 48 + 24), static_cast<float>(p.second * 48 + 24) };
}

// Constructor
Chaser::Chaser(const sf::Texture& t, Vector2f startPos, int h, float s)
    : Enemy(t, startPos, h, s), moveX(0), moveY(0), frame(0)
{
    scale = { 1.5, 1.5 };
    this->getSprite().setTextureRect(IntRect(16, 430, 31, 33));
    this->getSprite().setScale(scale);
    this->getSprite().setOrigin(this->getSprite().getLocalBounds().width / 2, this->getSprite().getLocalBounds().height / 2);
}

// Destructor
Chaser::~Chaser()
{
}

// Heuristic function for A* (Manhattan distance)
float heuristic(std::pair<int, int> a, std::pair<int, int> b)
{
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

// A* pathfinding algorithm
std::vector<sf::Vector2f> Chaser::findPath(Vector2f start, Vector2f goal, const std::vector<std::vector<char>>& map)
{
    auto startTile = toTile(start);
    auto goalTile = toTile(goal);

    std::priority_queue<std::pair<float, std::pair<int, int>>, std::vector<std::pair<float, std::pair<int, int>>>, std::greater<std::pair<float, std::pair<int, int>>>> frontier;
    frontier.emplace(0, startTile);

    std::unordered_map<std::pair<int, int>, std::pair<int, int>> came_from;
    std::unordered_map<std::pair<int, int>, float> cost_so_far;
    came_from[startTile] = startTile;
    cost_so_far[startTile] = 0;

    std::vector<std::pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    while (!frontier.empty())
    {
        auto current = frontier.top().second;
        frontier.pop();

        if (current == goalTile)
            break;

        for (auto dir : directions)
        {
            auto next = std::make_pair(current.first + dir.first, current.second + dir.second);
            if (next.first < 0 || next.first >= map[0].size() || next.second < 0 || next.second >= map.size())
                continue;

            char nextTile = map[next.second][next.first];
            bool canMove = (nextTile == 'F' || nextTile == 'R' || nextTile == 'r' || nextTile == 'o' ||
                (nextTile == 'S' && dir.first == -1 && goalTile == next));

            if (!canMove)
                continue;

            float new_cost = cost_so_far[current] + 1;
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next])
            {
                cost_so_far[next] = new_cost;
                float priority = new_cost + heuristic(next, goalTile);
                frontier.emplace(priority, next);
                came_from[next] = current;
            }
        }
    }

    std::vector<sf::Vector2f> path;
    auto current = goalTile;
    while (current != startTile)
    {
        path.push_back(toPixel(current));
        current = came_from[current];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

// Update movement direction based on Player's position
void Chaser::moveUpdate(std::shared_ptr<Player> player, const std::vector<std::vector<char>>& map)
{
    Vector2f start = this->getSprite().getPosition();
    Vector2f goal = player->getSprite().getPosition();
    std::vector<Vector2f> path = findPath(start, goal, map);

    if (!path.empty())
    {
        Vector2f next = path[0];
        moveX = (next.x - start.x > 0) ? 1 : (next.x - start.x < 0) ? -1 : 0;
        moveY = (next.y - start.y > 0) ? 1 : (next.y - start.y < 0) ? -1 : 0;

        if (moveX != 0 && std::abs(next.x - start.x) >= 10)
        {
            this->getSprite().setScale(Vector2f(scale.x * moveX, this->getSprite().getScale().y));
        }
    }
}

// Update position based on calculated direction
void Chaser::update(float deltaTime)
{
    frame++;
    if (frame / 12 > 7)
        frame = 0;
    this->getSprite().setTextureRect(IntRect(16 + 32 * static_cast<int>(frame / 12), 430, 31, 33));

    this->getSprite().move(this->getSpeed() * moveX * deltaTime, this->getSpeed() * moveY * deltaTime);
}

