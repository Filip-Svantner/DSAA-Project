#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

struct Loot
{
    int gold;
    int xp;
};
enum class EnemyType
{
    SLIME,
    SPIDER,
    WOLF,
    GOBLIN,
    BEAR
};

class Enemy
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
    Loot loot;
    EnemyType type;
    int hp;
    int dmg;

public :

    Enemy(const std::string& texturePath, sf::IntRect rect) : sprite(texture)
    {
        if (!texture.loadFromFile(texturePath)) 
        {
            std::cout << "Failed to load texture: " << texturePath << "\n";
        }
        sprite.setTextureRect(rect);
        sprite.setPosition({400,100});
        sprite.scale({5.0f,5.0f});
    }

    virtual void setStats() = 0;
    void drawEnemy(sf::RenderWindow& window);

};

class Slime : public Enemy
{
public:
    Slime() : Enemy("assets/textures/placeholder.png", {{272, 16}, {32, 32}})
    {
        name = "Slime";
        setStats();
    }
    void setStats() override
    {
        hp = 50;
        dmg = 5;
        loot.gold = 20;
        loot.xp = 40;
    }
};

class Spider : public Enemy
{
public:
    Spider() : Enemy("assets/textures/placeholder.png", {{144, 16}, {32, 32}})
    {
        name = "Spider";
        setStats();
    }
    void setStats() override
    {
        hp = 30;
        dmg = 12;
        loot.gold = 30;
        loot.xp = 40;
    }
};

class Wolf : public Enemy
{
public:
    Wolf() : Enemy("assets/textures/placeholder.png", {{16, 16}, {32, 32}})
    {
        name = "Wolf";
        setStats();
    }
    void setStats() override
    {
        hp = 45;
        dmg = 10;
        loot.gold = 15;
        loot.xp = 60;
    }
};

class Goblin : public Enemy
{
public:
    Goblin() : Enemy("assets/textures/placeholder.png", {{208, 16}, {32, 32}})
    {
        name = "Goblin";
        setStats();
    }
    void setStats() override
    {
        hp = 70;
        dmg = 8;
        loot.gold = 60;
        loot.xp = 50;
    }
};

class Bear : public Enemy
{
public:
    Bear() : Enemy("assets/textures/placeholder.png", {{80, 16}, {32, 32}})
    {
        name = "Bear";
        setStats();
    }

    void setStats() override
    {
        hp = 100;
        dmg = 15;
        loot.gold = 50;
        loot.xp = 100;
    }

};