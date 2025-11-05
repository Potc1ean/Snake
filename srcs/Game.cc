#include "Game.hh"

#include <thread>
#include <chrono>
#include <iomanip>

Game::Game() : step('d'), nils(step), apple(nils) { }

void Game::settDifficulty(int diff_lvl) {
    difficulty = diff_lvl;
}

#ifdef _WIN32
    void Game::loopWindows() {
        int step_speed = 750 /difficulty;

        nils_garden.refresh(nils, apple);
        std::cout << nils_garden << std::endl;

        while (step != 'p') {
            if (_kbhit())
                step = _getch();
            nils.run(step, apple);
            if (nils.hasCollided())
                break;
            nils_garden.refresh(nils, apple);
            std::cout << nils_garden << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(step_speed));
        }
    }
#else
    int kbhit() {
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if(ch != EOF) {
            ungetc(ch, stdin);
            return 1;
        }

        return 0;
    }

    void Game::loopLinux() {
        int step_speed = 750 /difficulty;
        
        nils_garden.refresh(nils, apple);
        std::cout << nils_garden << std::endl;

        while (step != 'p') {
            if (kbhit())
                step = getchar();
            nils.run(step, apple);
            if (nils.hasCollided())
                break;
            nils_garden.refresh(nils, apple);
            std::cout << nils_garden << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(step_speed));
        }
    }
#endif

void Game::home() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+          ____  _   _    _    _  __ _____           +"<< std::endl;
    std::cout << "+         / ___|| \\ | |  / \\  | |/ /| ____|          +"<< std::endl;
    std::cout << "+         \\___ \\|  \\| | / _ \\ | ' / |  _|            +"<< std::endl;
    std::cout << "+          ___) | |\\  |/ ___ \\| . \\ | |___           +"<< std::endl;
    std::cout << "+         |____/|_| \\_/_/   \\_\\_|\\_\\|_____|          +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+              Enter difficulty level                +"<< std::endl;
    std::cout << "+                   1, 2 or 3                        +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+              Created by Potc1ean                   +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< std::endl;
}

void Game::end() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+          ____   ____   _____   _____ _____         +"<< std::endl;
    std::cout << "+         / ___| / ___| /  _  \\ |  _  | ____|        +"<< std::endl;
    std::cout << "+         \\___ \\| |    |  | |  || |_) |  _|          +"<< std::endl;
    std::cout << "+          ___) | |___ |  |_|  ||  _ <| |___         +"<< std::endl;
    std::cout << "+         |____/ \\____| \\_____/ |_| \\_\\_____|        +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                      "
                << std::setw(3) << std::setfill(' ')
                << nils.get_snake_len() - 3
                << "                           +"
                << std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+               difficulty level " << difficulty <<"                   +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+             thank you for playing !                +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "+                                                    +"<< std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< std::endl;
}
