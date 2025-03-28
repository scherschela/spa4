#include "Game.h"
#include <iostream>

void Game::start() {
    while (true) {
        gameMap.display();
        std::cout << "Action: N)orth, S)outh, E)ast, W)est, use ne(T), use C)atnip, H)elp, Q)uit: ";
        char input;
        std::cin >> input;

        bool validAction = false;
        switch (toupper(input)) {
            case 'N':
                gameMap.movePlayer(0);
                validAction = true;
                break;
            case 'E':
                gameMap.movePlayer(1);
                validAction = true;
                break;
            case 'S':
                gameMap.movePlayer(2);
                validAction = true;
                break;
            case 'W':
                gameMap.movePlayer(3);
                validAction = true;
                break;
            case 'T': {
                std::cout << "Use the net in which direction? N)orth, S)outh, E)ast, W)est: ";
                char netDirection;
                std::cin >> netDirection;

                int direction = -1;
                switch (toupper(netDirection)) {
                    case 'N': direction = 0; break;
                    case 'E': direction = 1; break;
                    case 'S': direction = 2; break;
                    case 'W': direction = 3; break;
                    default:
                        std::cout << "Invalid direction for net.\n";
                        break;
                }

                if (direction != -1) {
                    if (gameMap.checkNetCatch(direction)) {
                        std::cout << "You caught the cat with the net! You win!\n";
                        return;
                    } else {
                        std::cout << "You missed the cat with the net.\n";
                    }
                }
                validAction = true;
                break;
            }
            case 'C': {
                if (gameMap.playerCollectsCatnip()) {
                    gameMap.moveCatWithCatnip();
                }
                validAction = true;
                break;
            }
            case 'H':
                std::cout << "Instructions:\n";
                std::cout << "- Move with N, S, E, W.\n";
                std::cout << "- Use the Net (T) to catch the cat.\n";
                std::cout << "- Use Catnip (C) to lure the cat.\n";
                std::cout << "- H for help, Q to quit.\n";
                validAction = true;
                break;
            case 'Q':
                std::cout << "Quitting game.\n";
                return;
            default:
                std::cout << "Invalid input. Try again.\n";
        }

        if (validAction) {
            if (gameMap.checkLoss()) {
                std::cout << "You stepped into the cat's room. You lose!\n";
                return;
            }

        }
    }
}
