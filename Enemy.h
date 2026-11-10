#include <iostream>
#include "Item.h"

struct Loot
{
    int gold;
    int xp;
    Item item;
};

class Enemy
{
    public:
        std::string name;
        int hp;
        int dmg;
        
    private:
};