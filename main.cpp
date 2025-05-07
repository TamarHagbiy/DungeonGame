#include <iostream>
#include <string>
#include <cstdlib> // for EXIT_SUCCESS, EXIT_FAILURE
#include "Game.h"
#include "Fighter.h"
#include "Sorcerer.h"

int main(int argc, char* argv[]) {

    if (argc < 5) {
        return EXIT_FAILURE;
    }
    // please note - in order not to change the original code from work number 4.
    // I chose to check the arguments before using the constructor. also, Exception class was after this assignment was release.
    //in some places in this assigntment, i chose to use MyExption class. 
    // Parse command-line arguments
    std::string playerTypeStr = argv[1];  // e.g. "F"
    char playerType = playerTypeStr[0];   // the first character, e.g. 'F'
    int maxHealth   = std::stoi(argv[2]);
    if (maxHealth < 0) {
        std::cout << "Invalid Value" << std::endl;
        return EXIT_FAILURE;
    }
    int damage = std::stoi(argv[3]);
    if (damage < 0) {
        std::cout << "Invalid Value" << std::endl;
        return EXIT_FAILURE;
    }
    std::string configFile = argv[4];

    // Create the appropriate player
    Player* player = nullptr;
    switch (playerType) {
        case 'F':
            // Ensure Fighter has a matching constructor: Fighter(int maxHealth, int damage)
            player = new Fighter(maxHealth, damage);
            if (player == nullptr) {
                std::cout <<"Memory Problem" << std::endl;
                return EXIT_FAILURE;

            }
        break;
        case 'S':
            // Ensure Sorcerer has a matching constructor: Sorcerer(int maxHealth, int damage)
            player = new Sorcerer(maxHealth, damage);
        break;
    }

    // Create the Game object with the parsed parameters
    // Make sure your Game constructor is Game(std::string&, Player*)

    try {
        Game game(configFile, player);
        // Run the game
        game.RunGame();
    } catch (const std::exception& e) { //only the Game constracture can throw Exception. RunGame will not throw.
        // Handle exceptions from the Game constructor or other runtime errors
        std::cout << e.what() << std::endl;
        // Cleanup
        delete player; // Prevent memory leak
        return EXIT_FAILURE;
    }


    // Cleanup
    // delete player; // Prevent memory leak
    return EXIT_SUCCESS;

}
