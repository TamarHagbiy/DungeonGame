//
// Created by tamar on 04/01/2025.
//
#include "Game.h"
#include "Entity.h"
#include "Room.h"
#include <iostream>
#include <sstream>
#include <string>
#include "MyException.h"


Game::Game(std::string& confile, Player* player) {
    std::ifstream file(confile); // Open configuration file
    if (!file.is_open()) {
        throw MemoryException(); // Exit if file cannot be opened
    }

    this->entrance = Room(); // Initialize entrance as an empty room
    this->player = player;
    std::string line;

    while (std::getline(file, line) && !line.empty()) {
        std::istringstream iss(line);
        std::string roomName;
        int campfire, monsterHealth = 0, monsterDamage = 0;
        char monsterType;

        // Read basic room details
        iss >> roomName >> campfire >> monsterType;

        for (char c : roomName) {
            if (c < '0' || c > '9') {
                throw InvalidValueException(); // Invalid character in roomName
            }
        }
        if (campfire < 0) {
            throw InvalidValueException();
        }
        if (monsterType != 'N' && monsterType != 'G' && monsterType != 'D') {
            throw InvalidValueException();
        }
        // Navigate to the current room
        Room* curr = &this->entrance;
        for (size_t i = 0; i < roomName.length() - 1; ++i) {
            try {
                int index = roomName[i] - '0'; // Navigate to the specified room
                curr = (*curr)[index];
            } catch (InvalidRoomException& e) {
                throw e;
            }
        }

        int lastIndex = roomName.back() - '0';

        // Add a room based on monsterType
        bool status;
        if (monsterType == 'N') {
            status = curr->AddRoom(lastIndex, campfire, 0, 0, 'N'); // No monster
        } else {
            iss >> monsterHealth >> monsterDamage; // Read monster details
            if (monsterHealth < 0 || monsterDamage < 0) {
                throw InvalidValueException();
            }
            status = curr->AddRoom(lastIndex, campfire, monsterHealth, monsterDamage, monsterType);
        }

        if (!status) {
            throw MemoryException(); // Throw memory exception if room addition fails
        }
    }
}



// Handles interactions when entering a room
bool Game::GetInRoom(Room &curr) {
    player->updateSpecelty();
    std::cout << *player << std::endl;

    if(curr.getMonster() != nullptr) {
        if (curr.getCampfire() != 0) { // Heal player if there is a campfire
            std::cout << "You sit by the campfire and heal " << curr.getCampfire() << " health" << std::endl;
            *player += curr.getCampfire();
            player->updateSpecelty();
        }
        if (curr.getMonster()->getCurrentHealth() != 0) { // Encounter a monster
            // player->updateSpecelty();
            if (*player > *(curr.getMonster())) {
                std::cout << "You encounter a smaller "<< curr.getMonster()->getName()<<std::endl;
            } else if (*player == *(curr.getMonster())){
                std::cout << "You encounter a equally sized "<< curr.getMonster()->getName()<<std::endl;
            } else {
                std::cout << "You encounter a larger "<< curr.getMonster()->getName() << std::endl;
            }
            std::cout << *(curr.getMonster()) << std::endl;
            return true; // A monster is present
        } else if (curr.getMonster()->getCurrentHealth() == 0 && curr.getCampfire() == 0) {
            std::cout << "You arrive to an empty room" << std::endl;
            return false; // Room is empty
        }
    }
    else {
        if (curr.getCampfire() != 0) { // Heal player if there is a campfire
            std::cout << "You sit by the campfire and heal " << curr.getCampfire() << " health" << std::endl;
            *player += curr.getCampfire();
            player->updateSpecelty();
        }
        else {
            std::cout << "You arrive to an empty room" << std::endl;
        }
    }
    return false;
}

// Handles the battle between the player and the room's monster
bool Game::Buttele(Room &curr) {
    int damage = 0;
    while (curr.getMonster()->getCurrentHealth() > 0 && player->getCurrentHealth() > 0) {
        damage = player->Attack(*(curr.getMonster())); // Player attacks the monster
        std::cout << "You deal " <<damage << " damage to the "<<curr.getMonster()->getName()<<" and leave it with " << curr.getMonster()->getCurrentHealth() << " health" << std::endl;
        if (curr.getMonster()->getCurrentHealth() <= 0) {
            std::cout << "You defeat the "<<curr.getMonster()->getName()<< " and go on with your journey" << std::endl;
            return true; // Monster is defeated
        }
        damage = (curr.getMonster())->Attack(*player); // Monster attacks the player
        std::cout << "The " << curr.getMonster()->getName() << " deals " << damage << " damage to you and leaves you with " << player->getCurrentHealth() << " health" << std::endl;
        if (player->getCurrentHealth() <= 0) {
            std::cout << "You lost to the dungeon" << std::endl;
            return false; // Player is defeated
        }
    }
    return true;
}

// Handles room navigation
bool Game::MoveRoom(Room *&curr) const {
    // player->updateSpecelty();
    const int doors = curr->getSize();
    int next;
    if (doors == 0) {
        std::cout << "The room continues and opens up to the outside. You won against the dungeon" << std::endl;
        return false; // No more rooms, dungeon completed
    }
    if (doors == 1) {
        std::cout << "You see a single corridor ahead of you labeled 0" << std::endl;
        std::cin >> next;
        curr = (*curr)[next]; // Move to the next room
        return true;
    } else if (doors > 1) {
        std::cout << "You see corridors labeled from 0 to " << doors - 1 << ". Which one will you choose?" << std::endl;
        std::cin >> next;
        curr = (*curr)[next]; // Choose a corridor to move to
        return true;
    }
    return false;
}

// Main game loop
void Game::RunGame() {
    Room* curr = &entrance;
    // player->updateSpecelty();
    while (true) {
        if (this->GetInRoom(*curr) == true) {
            bool continueGame = this->Buttele(*curr); // Handle battles
            if (continueGame == false) {
                break; // End game if player is defeated
            }
        }
        bool stat = this->MoveRoom(curr); // Move to the next room
        if (stat == false) {
            break; // End game if no more rooms
        }
    }
}

Game::~Game() {
    delete player;
}
