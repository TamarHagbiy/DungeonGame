#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"
#include "Goblin.h"
#include "Dragon.h"

// The Fighter class inherits from the Player class
class Fighter : public Player {
public:
    // Default constructor
    Fighter();

    // Constructor initializing maxHealth and damage, setting name to "Fighter"
    Fighter(int maxHealth, int damage): Player(maxHealth, damage) {name="Fighter";};

    // Function for the Fighter to attack a Monster
    virtual int Attack(Monster &other);

    // Function defining how the Fighter is attacked by a Goblin
    virtual int attackedByGoblin(const Goblin &goblin);

    // Function defining how the Fighter is attacked by a Dragon
    virtual int attackedByDragon(const Dragon &dragon);

    // Virtual destructor for the Fighter class
    virtual ~Fighter();
};

#endif // FIGHTER_H
