//
// Created by tamar on 24/01/2025.
//

#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"
#include <iostream>
#include <string>
#include <utility>
using std::ostream;

class Player; // Forward declaration of the Player class

// The Monster class inherits from the Entity class
class Monster : public Entity {

public:
  // Constructor initializing maxHealth and damage
  Monster(int maxHealth, int damage): Entity(maxHealth, damage){};

  // Pure virtual function for attacking a Player
  virtual int Attack(Player &other) = 0;

  // Virtual destructor for the Monster class
  virtual ~Monster(){};
};

#endif //MONSTER_H
