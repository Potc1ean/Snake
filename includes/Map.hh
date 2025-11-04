#pragma once

#include <string>
#include <vector>
#include <iostream>

class Snake;
class Apple;

namespace MapConfig {
    // --- Dimensions ---
    inline constexpr int WIDTH = 20;
    inline constexpr int HEIGHT = 20;

    // --- Map symboles ---
    inline constexpr char BORDER = '+';
    inline constexpr char EMPTY  = ' ';
    inline constexpr char SNAKE  = 'o';
    inline constexpr char APPLE  = '@';
}

class Map {
    private:
        std::vector<std::string> map;
    public:
    // --- Constructors / Destructors ---
        explicit Map();
        ~Map() = default;
    // --- Methods ---
        void refresh(const Snake& s, const Apple& apple);
    // --- Getters ---
        const std::vector<std::string>& getMap() const { return map; }
};

std::ostream& operator<<(std::ostream &o, const Map &field);
