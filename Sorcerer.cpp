//
// Created by tamar on 24/01/2025.
//
#include "Sorcerer.h"
#include <cmath> // if you need std::round

Sorcerer::Sorcerer() {
    this->name = "sorcerer";
}

int Sorcerer::Attack(Monster &other) {
    int damage = 0;
    // Example logic: if Sorcerer is "specialty mode,double-attack
    if (this->isSpecelty()) {
        other -= *this;  // first hit
        other -= *this;
        damage = 2*this->_damage;
        return damage;
    }
    // normal attack
    other -= *this;
    damage += this->_damage;
    this->updateSpecelty();
    return damage;
}

int Sorcerer::attackedByGoblin(const Goblin &goblin) {
    // Sorcerer might take half goblin’s damage
    int damageTaken = static_cast<int>(std::round(0.5 * goblin.getDamage()));
    this->updateHealth(damageTaken);
    return damageTaken;
}

int Sorcerer::attackedByDragon(const Dragon &dragon) {
    // Sorcerer might take double dragon’s damage
    int damageTaken =2 * dragon.getDamage();
    this->updateHealth(damageTaken);
    return damageTaken;
}

Sorcerer::~Sorcerer() {
    // Any cleanup if needed
}
