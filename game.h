#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
/*
    Class that acts as Game Engine
    Wrapper Class
*/

class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow *window; // without pointers, the object gets destroyed after functions completion.
    sf::VideoMode videoMode;
    sf::Event ev;

    // Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    // Private Functions.
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    // Constructors & Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;

    // Functions
    void spawnEnemy();
    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();
    void renderEnemies();
    void render();
};