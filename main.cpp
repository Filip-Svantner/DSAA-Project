#include <SFML/Graphics.hpp>
#include <optional>
#include "Enemy.h"
#include "Item.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3 CMake Setup");
    window.setFramerateLimit(60);

    


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
        window.display();
    }
    return 0;
}

void init()
{
    std::vector<Enemy> enemies;
    std::vector<Items> items;
    
}