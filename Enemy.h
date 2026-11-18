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
    static sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
    Loot loot;
    EnemyType type;
    int hp;
    int dmg;

public :

    Enemy()
    {
        loadTexture("assets/textures/placeholder.png");
        sprite.setTexture(texture);
    }
    virtual void setStats() = 0;
    void initSprite(sf::IntRect rect)
    {
        sprite.setTextureRect(rect);
    }
    static bool loadTexture(const std::string& path)
    {
        return texture.loadFromFile(path);
    }
};

class Slime : public Enemy
{
public:
    Slime()
    {
        name = "Slime";
        setStats();
        initSprite(sf::IntRect({0,0},{64,64}));
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
    Spider()
    {
        name = "Spider";
        setStats();

        if(!texture.loadFromFile("assets/textures/placeholder.png"))
        {
            std::cout << " Slime not loaded " << "\n";
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect({0,0},{64,64}));
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
    Wolf()
    {
        name = "Wolf";
        setStats();

        if(!texture.loadFromFile("assets/textures/placeholder.png"))
        {
            std::cout << " Slime not loaded " << "\n";
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect({0,0},{64,64}));
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
    Goblin()
    {
        name = "Goblin";
        setStats();

        if(!texture.loadFromFile("assets/textures/placeholder.png"))
        {
            std::cout << " Slime not loaded " << "\n";
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect({0,0},{64,64}));
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
    Bear()
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

        if(!texture.loadFromFile("assets/textures/placeholder.png"))
        {
            std::cout << " Slime not loaded " << "\n";
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect({0,0},{64,64}));
    }

};