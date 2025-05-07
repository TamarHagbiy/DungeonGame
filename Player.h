//
// Created by tamar on 24/01/2025.
//
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

// Forward declarations for Dragon, Goblin, and Monster classes
class Dragon;
class Goblin;
class Monster;

// The Player class inherits from the Entity class
class Player : public Entity {

protected:
  // A counter used to track specialty status
  int counterSpecelty;

public:
  // Default constructor
  Player();

  // Constructor initializing maxHealth and damage
  Player(int maxHealth, int damage);

  // Updates the specialty counter
  void updateSpecelty();

  // Checks if the player has a specialty
  bool isSpecelty();

  // Pure virtual function for the Player to attack a Monster
  virtual int Attack(Monster &other) = 0;

  // Pure virtual function defining how the Player is attacked by a Goblin
  virtual int attackedByGoblin(const Goblin &Goblin) = 0;

  // Pure virtual function defining how the Player is attacked by a Dragon
  virtual int attackedByDragon(const Dragon &Dragon) = 0;

  // Virtual destructor for the Player class
  virtual ~Player(){};
};

#endif //PLAYER_H
