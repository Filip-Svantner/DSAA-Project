#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Player
{
    int hp;
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Player() : sprite(texture)
    {
        if(!texture.loadFromFile("assets/textures/player.png"))
        {
            std::cout << "Player not loaded" << "\n";
        }

        sprite.setPosition({100,400});
        sprite.setTextureRect({{16,16},{32,32}});
        sprite.setScale({5,5});
    }
    void drawPlayer(sf::RenderWindow& window);
};