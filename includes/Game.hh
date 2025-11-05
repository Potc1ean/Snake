#pragma once

#include "Snake.hh"
#include "Map.hh"
#include "Apple.hh"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif


class Game
{
    private:
        Snake nils;
        Apple apple;
        Map nils_garden;

        char step;
        int difficulty;
    public:
        Game();
        ~Game() = default;

        void settDifficulty(int diff_lvl);

    #ifdef _WIN32
        void loopWindows();
    #else
        void loopLinux();
    #endif

        void home();
        void end();
};
