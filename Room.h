#include <iostream>

enum RoomType
{
    COMBAT,
    CHEST,
    SHOP,
    EVENT
};

class Room
{
    RoomType type;
};