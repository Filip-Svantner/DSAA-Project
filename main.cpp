#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3 CMake Setup");
    window.setFramerateLimit(60);

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin({50.f, 50.f});
    shape.setPosition({400.f, 300.f});

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
        window.draw(shape);
        window.display();
    }
    return 0;
}