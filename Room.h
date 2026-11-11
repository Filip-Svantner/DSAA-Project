#pragma once
#include <iostream>

enum class RoomType
{
    COMBAT,
    CHEST,
    SHOP,
    EVENT,
    EMPTY
};

class Room
{
public:
    RoomType type;

    Room() : type(RoomType::EMPTY) {}
    void changeType(RoomType t);
};