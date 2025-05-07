#ifndef SORCERER_H
#define SORCERER_H

#include "Player.h"
#include "Goblin.h"
#include "Dragon.h"

class Sorcerer : public Player {
public:
    Sorcerer(); //default constructor, not in use in this game for now.
    Sorcerer(int maxHealth, int damage): Player(maxHealth, damage) {this->name = "Sorcerer";}; //constructor
    virtual int Attack(Monster &other);  // attack monster
    virtual int attackedByGoblin(const Goblin &goblin); // for polymorphism
    virtual int attackedByDragon(const Dragon &dragon);

    virtual ~Sorcerer(); //detractor
};

#endif // SORCERER_H
