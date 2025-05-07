//
// Created by tamar on 24/01/2025.
//
#include "Dragon.h"
int Dragon::Attack(Player &other) {
    return other.attackedByDragon(*this);
}

Dragon::~Dragon() {
}
