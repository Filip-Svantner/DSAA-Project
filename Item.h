#pragma once
#include <iostream>
#include <string>

enum Type
{
    WEAPON,
    ARMOR,
    CONSUMABLE
};

enum class WeaponType
{
    SWORD,
    SPEAR,
    HAMMER
};

enum class ArmorType
{
    BOOTS,
    LEGGINS,
    CHEST,
    HEAD
};

enum class ConsumableType
{
    POTION,
    FOOD,
    HERB
};

class Item
{
    Type type;
    std::string name;
public: 
    Item()
    {
        type = Type::ARMOR;
    }
};