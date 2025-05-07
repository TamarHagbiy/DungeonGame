//
// Created by tamar on 24/01/2025.
//
#include "Player.h"

// Default constructor for the Player class
// Initializes the specialty counter to 4
Player::Player() {
    counterSpecelty = 4;
}

// Constructor initializing maxHealth and damage, and setting the specialty counter to 4
Player::Player(int maxHealth, int damage) : Entity(maxHealth, damage), counterSpecelty(4) {}

// Updates the specialty counter by incrementing it
void Player::updateSpecelty() {
    ++counterSpecelty;
}

// Checks if the player has a specialty
// If the specialty counter is 4 or greater, it resets the counter to 0 and returns true
// Otherwise, it returns false
bool Player::isSpecelty() {
    if (counterSpecelty >= 4) {
        counterSpecelty = 0;
        return true;
    }
    return false;
}
