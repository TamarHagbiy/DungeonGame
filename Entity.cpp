//
// Created by tamar on 04/01/2025.
//

#include "Entity.h"

// Copy constructor - copies all attributes from another Entity
Entity::Entity(const Entity& other) : name(other.name), _maxHealth(other._maxHealth), _currentHealth(other._currentHealth), _damage(other._damage) {}

Entity& Entity::operator+=(const int health) { // Increase current health by a given amount
    _currentHealth += health;
    if (_currentHealth > _maxHealth) {_currentHealth = _maxHealth;} // Ensure health doesn't exceed max
    return *this;
}

Entity& Entity::operator-=(int input) { // Reduce damage by a given amount
    _damage -= input;
    if (_damage < 0) {_currentHealth = 0 ;} // Set health to 0 if damage becomes negative
    return *this;
}

Entity& Entity::operator-=(const Entity &other) { // Decrease health based on another Entity's damage
    _currentHealth -= other._damage;
    if (_currentHealth < 0) {_currentHealth = 0 ;} // Ensure health doesn't go below 0
    return *this;
}

bool Entity::operator==(const Entity &other) const { // Check if two Entities are equal based on health and damage
    const int thisVal = _currentHealth * _damage;
    const int otherVal = other._currentHealth * other._damage;
    if (thisVal == otherVal){return true;}
    return false;
}

bool Entity::operator>(const Entity &other) const { // Compare two Entities to see if this one is stronger
    const int thisVal = _currentHealth * _damage;
    const int otherVal = other._currentHealth * other._damage;
    if (thisVal > otherVal) {
        return true;
    }
    return false;
}

int Entity::getCurrentHealth() const { // Getter for current health
    return _currentHealth;
}

int Entity::getDamage() const { // Getter for damage
    return _damage;
}

std::string& Entity::getName(){
    return name;
}


int Entity::getMaxHealth() const { // Getter for maximum health
    return _maxHealth;
}
#include "Entity.h"

void Entity::updateHealth(int i) {
    _currentHealth -= i;
    if (_currentHealth < 0) {
        _currentHealth = 0;
    }
}
ostream &operator<<(ostream &out, const Entity &entity) {
    std::string capitalizedName = entity.name;
    capitalizedName[0] = toupper(capitalizedName[0]);
    out << capitalizedName << " (" << entity._currentHealth << "/" << entity._maxHealth << ") " << "- " << entity._damage;
    return out;
}

