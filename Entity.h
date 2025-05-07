//
// Created by tamar on 04/01/2025.
//
#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
#include <utility>
using std::ostream;
#include <cmath>
class Entity {

protected:
    std::string name; // Name of the entity
    int _maxHealth, _currentHealth, _damage; // Health and damage attributes
    void updateHealth(int i);
    Entity():  _maxHealth(0), _currentHealth(0), _damage(0) {} // Default constructor
    Entity(int maxHealth, int damage)
        : _maxHealth(maxHealth), _currentHealth(maxHealth), _damage(damage) {} // Constructor with parameters

public:

    Entity(const Entity& other); // Copy constructor

    Entity& operator -= ( const Entity& other); // Overloaded operator to reduce health by another entity's damage

    Entity& operator -= ( int input); // Overloaded operator to reduce damage by an integer

    Entity& operator += ( int health); // Overloaded operator to increase health by an integer

    bool operator == ( const Entity& other) const; // Check equality based on health and damage

    bool operator>(const Entity &other) const; // Compare strength of entities

    friend ostream& operator << (ostream& out, const Entity& entity); // Output entity details

    int getCurrentHealth() const; // Getter for current health

    int getMaxHealth() const; // Getter for maximum health

    int getDamage() const; // Getter for damage

    std::string& getName();

    virtual ~Entity() {}
};


#endif //ENTITY_H
