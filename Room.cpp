//
// Created by tamar on 04/01/2025.
//
#include "Room.h"
#include "MyException.h"
// Default constructor - initializes an empty room with no campfire or monster
// Default constructor
Room::Room() : campfire(0), monster(nullptr), rooms(nullptr), size(0) {}

// Constructor with parameters for campfire and monster attributes
Room::Room(const int campfire, const int monsterHealth, const int monsterDamage, char monsterType)
    : campfire(campfire), monster(nullptr), rooms(nullptr), size(0) {
    if (monsterType == 'G') {
        monster = new Goblin(monsterHealth, monsterDamage);
    } else if (monsterType == 'D') {
        monster = new Dragon(monsterHealth, monsterDamage);
    }
}


Room::Room(const int campfire): campfire(campfire), monster(nullptr), rooms(nullptr), size(0){}

// Access operator for non-const Room - returns the pointer to a room at the given index
Room* Room::operator[](const int index) {
    if (index < 0 || index >= size) {
        throw InvalidRoomException(); // trow exception
    }
    return rooms[index];
}

// Access operator for const Room - returns the pointer to a room at the given index
Room* Room::operator[](const int index) const {
    if (index < 0 || index >= size) {
        throw InvalidRoomException(); // trow exception
    }
    return rooms[index];
}



// Resize the array of rooms to a new capacity
bool Room::resize(int newCapacity) {
    Room** newRooms = new Room*[newCapacity]; // Allocate new memory
    if (!newRooms) {
        std::cerr << "Room::resize: out of memory" << std::endl;
        delete[] rooms;
        rooms = nullptr;
        size = 0;
        return false;
    }

    for (int i = 0; i < newCapacity; ++i) {
        newRooms[i] = nullptr; // Initialize new room slots to nullptr
    }
    for (int i = 0; i < size; ++i) {
        newRooms[i] = rooms[i]; // Copy existing rooms
    }
    delete[] rooms; // Free old memory
    rooms = newRooms; // Update to new room array
    size = newCapacity; // Update size
    return true;
}

Room::~Room() {
    // Clean up child Rooms
    for (int i = 0; i < size; i++) {
        delete rooms[i];
    }
    delete[] rooms;

    // Clean up monster
    delete monster;
}

// Add a room at the specified index with given campfire and monster attributes
bool Room::AddRoom(int index, int campfire, int monsterHealth, int monsterDamage, char monsterType) {
    if (index >= size) {
        bool status = this->resize(index + 1); // Resize if index exceeds current size
        if (!status) {
            return false; // Return false if resize fails
        }
    }
    // Free memory for existing room at index
    if (rooms[index] != nullptr) {
        delete rooms[index];
    }

    if (monsterType != 'N') {
        rooms[index] = new Room(campfire, monsterHealth, monsterDamage, monsterType);
    } // Create new room
    else {
        rooms[index] = new Room(campfire);
    }
    if (!rooms[index]) {
        std::cerr << "Room::AddRoom: out of memory" << std::endl;
        return false; // Return false if memory allocation fails
    }
    return true;
}

// Getter for the size of the room array
int Room::getSize() const {
    return size;
}

// Getter for the monster in the room
Monster* Room::getMonster() {
    if (monster == nullptr){return nullptr;};
    return monster;
}

// Getter for the campfire value
int Room::getCampfire() const {
    return campfire;
}
