#include "Game.hh"

int main(void)
{
    Game game;
    game.home();

    int diff_lvl;
    while (true) {
        std::cin >> diff_lvl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between 1 and 3.\n";
            continue;
        }
        if (diff_lvl >= 1 && diff_lvl <= 3) {
            break;
        }
    }
    game.settDifficulty(diff_lvl);

    try {
        #ifdef _WIN32
            game.loopWindows();
        #else
            game.loopLinux();
        #endif
    } catch (std::exception &e) {
        game.end();
        std::cout << e.what() << std::endl;
        return 0;
    }
    game.end();
    return 0;
}
