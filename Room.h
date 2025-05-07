//
// Created by tamar on 04/01/2025.
//

#ifndef ROOM_H
#define ROOM_H
#include "Entity.h"
#include "Monster.h"
#include "Dragon.h"
#include "Goblin.h"

class Room {
private:
    int campfire; // The amount of health the campfire provides
    Monster * monster; // The monster present in the room
    Room **rooms; // Array of pointers to adjacent rooms
    int size; // The number of rooms currently in the array

public:
    Room(); // Default constructor
    Room(const int campfire);
    Room(const int campfire, const int monsterHealth, const int monsterDamage, char monsterType); // Constructor with parameters
    ~Room(); // Destructor to free allocated memory
    Room* operator[](int index); // Access operator for non-const objects
    Room* operator[](int index) const; // Access operator for const objects
    friend std::ostream& operator<<(std::ostream& os, Room& room); // Output stream operator
    bool resize(int newCapacity); // Resizes the array of rooms
    bool AddRoom(int index, int campfire, int monsterHealth, int monsterDamage, char monsterType); // Adds a room at a specific index
    int getSize() const; // Returns the number of rooms in the array
    int getCapacity() const; // Placeholder for capacity (not implemented)
    Monster* getMonster(); // Returns the monster in the room
    int getCampfire() const; // Returns the campfire value
};

#endif //ROOM_H
