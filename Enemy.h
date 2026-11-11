#pragma once
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
    std::string name;
    Loot loot;
    EnemyType type;
    int hp;
    int dmg;

public :

    virtual ~Enemy() = default;
    virtual void setStats() = 0;
};

class Slime : public Enemy
{
public:
    Slime()
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
    Spider()
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
    Wolf()
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
    Goblin()
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
    }

};