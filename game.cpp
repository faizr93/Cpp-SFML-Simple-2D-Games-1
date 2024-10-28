#include "game.h"

/*
Future Reference to me and me only ( I used pointers, The reasons are explained below, Use this video If i forget how SFML or C++ functions.
https://www.youtube.com/watch?v=kxb0GvBNOGU&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up&index=6
*/

// Private Functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Game 1");

    this->window->setFramerateLimit(75);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5, 0.5));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
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

void Game::update()
{
    this->pollEvents();

    // Update mouse position
    // Relative to the screen
    // std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << sf::Mouse::getPosition().y << "\n";
    // Relative to the Screen
    std::cout << "Mouse pos: "
              << sf::Mouse::getPosition(*this->window).x
              << sf::Mouse::getPosition(*this->window).y << "\n";
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
    this->window->draw(this->enemy);

    this->window->display();
}
