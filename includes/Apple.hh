#pragma once

#include <ostream>
#include <random>

class Snake;

class Apple
{
    private:
        int x, y;
        static std::mt19937 gen;
    public:
    // --- Constructors / Destructors ---
        Apple(const Snake &s);
        ~Apple() = default;
    // --- Methods ---
        void newApple(const Snake &s);
    // --- getters ---
        int getX() const { return x; }
        int getY() const { return y; }
};

std::ostream& operator<<(std::ostream& o, const Apple& a);
