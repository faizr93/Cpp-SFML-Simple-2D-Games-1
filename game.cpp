#include "game.h"

/*
Future Reference to me and me only ( I used pointers, The reasons are explained below, Use this video If i forget how SFML or C++ functions.
https://www.youtube.com/watch?v=kxb0GvBNOGU&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up&index=6
*/

// Private Functions
void Game::initVariables()
{
    this->window = nullptr;

    // Game logic
    this->points = 0;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Game 1");

    this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5, 0.5));
    this->enemy.setFillColor(sf::Color::Cyan);
    // this->enemy.setOutlineColor(sf::Color::Green);
    // this->enemy.setOutlineThickness(1.f);
}

// Constructor & Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}
Game::~Game()
{
    delete this->window;
}

// Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}

// Functions
void Game::pollEvents()
{
    // Event polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

/**
 * @return void
 *
 * Spawns enemies and sets their color and positions.
 *
 * - Sets a random position.
 *
 * - Sets a random color.
 *
 * - Adds enemy to the vector.
 */
void Game::spawnEnemy()
{
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f);

    this->enemy.setFillColor(sf::Color::Green);

    // Spawn the Enemy
    this->enemies.push_back(this->enemy);

    // Removes enemies at end of screen
}

/**
    @return void

    Updates the mouse positions:
    - Mouse positions relative to window (Vector2i)
*/
void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

/**
    @return void

    Updates the enemy spawn timer and spawns enemies
    when the total amount of enemies is smaller than the maximum.
    Moves the enemies downwards.
    Removes the enemies at the edge of the screen. //TODO

 */
void Game::updateEnemies()
{
    // Updating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            // Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
        {
            this->enemySpawnTimer += 1.f;
        }
    }

    // Moving and Updating enemies
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        this->enemies[i].move(0.f, 5.f);

        // Check if Clicked upon
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
            {
                deleted = true;

                //Gain points
                this->points += 10.f;
            }
        }

        // If enemy past the bottom of the screen
        if (this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            deleted = true;
        }

        //Universal Enemy Delete
        if (deleted)
        {
            this->enemies.erase(this->enemies.begin() + i);
        }
    }
    // for (auto &e : this->enemies)
    // {
    //     e.move(0.f, 1.f);
    // }
}

void Game::update()
{
    this->pollEvents();

    this->updateMousePositions();

    this->updateEnemies();
}

void Game::renderEnemies()
{
    // Rendering all the Enemies
    for (auto &e : this->enemies)
    {
        this->window->draw(e);
    }
}

void Game::render()
{
    /*
        @return void

        - clear old frame
        - return objects
        - display frame in window

        Renders the Game objects.
    */

    this->window->clear();

    // Draw game objects
    this->renderEnemies();

    this->window->display();
}
