//
// Created by tamar on 04/01/2025.
//

#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <string>

#include "Entity.h"
#include "Room.h"
#include "Player.h"
#include "Sorcerer.h"
#include "Fighter.h"
class Game {
    Player *player; // The player entity
    Room entrance; // The starting room of the game
public:
    Game(std::string& confile,Player *player); // Constructor to initialize the game with a config file and player details

    bool GetInRoom(Room &curr); // Handles interactions when the player enters a room

    void RunGame(); // Main game loop that manages gameplay

    bool Buttele(Room &curr); // Manages the battle between the player and the monster in the current room
    bool MoveRoom(Room *&curr) const; // Handles the player's movement between rooms
    ~Game();
};

#endif //GAME_H
