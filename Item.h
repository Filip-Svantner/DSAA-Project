#include <iostream>

enum Type
{
    WEAPON,
    ARMOR,
    CONSUMABLE
};

class Item
{
    Type type;
    std::string name;
    
};