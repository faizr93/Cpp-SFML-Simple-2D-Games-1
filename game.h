#pragma once

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
 
    // Private Functions.
    void initVariables();
    void initWindow();
public:
    // Constructors & Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;
    
    // Functions
    void pollEvents();
    void update();
    void render();
};