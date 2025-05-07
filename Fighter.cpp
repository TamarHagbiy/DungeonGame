//
// Created by tamar on 24/01/2025.
//
#include "Fighter.h"
#include <cmath> // if needed for round

Fighter::Fighter() {
    this->name = "fighter";
}

int Fighter::Attack(Monster &other) {
    // Fighter's attack reduces the monster's health
    other -= *this;  // same pattern as in your original code
    this->updateSpecelty();
    return this->getDamage();
}

int Fighter::attackedByGoblin(const Goblin &goblin) {
    // If not in specialty state, take double goblin’s damage
    int damageTaken = 0;
    if (!this->isSpecelty()) {
        damageTaken = 2 * goblin.getDamage();
        this->updateHealth(damageTaken);
    }
    return damageTaken;
}

int Fighter::attackedByDragon(const Dragon &dragon) {
    // If not in specialty state, take half the dragon’s damage (rounded)
    if (!this->isSpecelty()) {
        int damageTaken = static_cast<int>(std::round(0.5 * dragon.getDamage()));
        this->updateHealth(damageTaken);
        return damageTaken;
    }
    return 0;
}

Fighter::~Fighter() {
    // Any cleanup if needed
}
