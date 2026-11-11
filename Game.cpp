#include <iostream>
#include "Game.h"

Game::Game() : combatText(font)
{
    if(!font.openFromFile("assets/arial.ttf"))
    {
        std::cout << "Font not loaded" << "\n";
    }
}

RoomNode* Game::createRoomNode(Room room)
{
    RoomNode* newNode = new RoomNode();
    newNode->data = room; 
    newNode->next = nullptr;

    return newNode;
}

void Game::displayFloor()
{
    if(head == nullptr)
    {
        std::cout << "Empty list" << "\n";
        return;
    }

    RoomNode* current = head;

    do
    {
        std::cout << static_cast<int>(current->data.type) << "\n";
        current = current->next;
    } while (current != head);
    
}

 void Game::insertRoom(RoomNode*& head, 
        RoomNode*& tail,
        Room room)
{
    RoomNode* newNode = createRoomNode(room);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void Game::generateFloor()
{
    chest, shop = false;
    for (int i = 0; i < NO_OF_ROOMS; i++)
    {
        int r = rand()%101;
        Room room;
        RoomType type;

        if(r <= 60)
        {
            type = RoomType::COMBAT;
        }
        else if(r <= 80)
        {
            type = RoomType::EVENT;
        }
        else if(r <= 90 && !shop)
        {
            type = RoomType::SHOP;
            shop = true;
        }
        else if (r <= 100 && !chest)
        {
            type = RoomType::CHEST;
            chest = true;
        }

        room.changeType(type);
        insertRoom(head, tail, room);

    }
}

RoomType Game::getState()
{
    return head->data.type;
}

void Game::setEnemy()
{
    enemy = nullptr;
    int r = rand()%5;

    switch(r)
    {
    case 0: 
        enemy = new Slime();
        break;
    case 1: 
        enemy = new Spider();
        break;
    case 2: 
        enemy = new Wolf();
        break;
    case 3: 
        enemy = new Goblin();
        break;
    case 4: 
        enemy = new Bear();
        break;
    default: 
        break;
    }
}

void Game::processCombat()
{
    if(playerTurn)
    {
        combatText.setString("Attack");
    }
}
