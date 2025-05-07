//
// Created by tamar on 24/01/2025.
//

#ifndef DRAGON_H
#define DRAGON_H
#include "Monster.h"
#include "Player.h"

class Dragon :public Monster {

    public:
    Dragon(int maxHealth, int damage) : Monster(maxHealth,damage){name = "dragon";};

    virtual int Attack(Player &other);

    virtual ~Dragon();

};


#endif //DRAGON_H
