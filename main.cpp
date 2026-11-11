#include <SFML/Graphics.hpp>
#include <optional>
#include <cstdlib>
#include <ctime>
#include "Game.h"

Game game; 

void init();
void update();


int main() {
    std::srand(std::time(nullptr));

    init();

    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3 CMake Setup");
    window.setFramerateLimit(60);

    
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({400.0f, 300.0f});
    circle.setRadius(50.0f);

    while (window.isOpen()) {
        // Use pollEvent() to safely handle events without MSVC debug stack issues
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}

void init()
{
    game.generateFloor();
    game.displayFloor();
}

void update()
{

    if (game.getState() == RoomType::COMBAT)
    {
        game.setEnemy();
        game.processCombat();
    }
}