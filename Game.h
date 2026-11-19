#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Item.h"
#include "Room.h"
#include "Player.h"

struct RoomNode
{
    Room data;
    RoomNode* next;
};

class Game
{
    Player player;
    Enemy* enemy;
    RoomNode* head = nullptr;
    RoomNode* tail = nullptr;

    static const int NO_OF_ROOMS = 10;

    bool chest = true;
    bool shop = true; 
    bool playerTurn = true;
    bool enemyTurn = false;

    sf::Font font;
    sf::Text combatText;
    
    // UI
    sf::RectangleShape backUI;
    sf::RectangleShape selection;
    sf::Text attack;
    sf::Text bag;
    sf::Text run;

public:
    Game();
    RoomNode* createRoomNode(Room room);
    void displayFloor();
    void insertRoom(RoomNode*& head, 
        RoomNode*& tail,
        Room room);
    void generateFloor();
    RoomType getState();
    void setEnemy();
    Enemy* getEnemy() const { return enemy; };
    void processCombat();
    void draw(sf::RenderWindow& window);
    void initUI();

};