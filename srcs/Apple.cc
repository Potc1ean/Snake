#include "Apple.hh"
#include "Map.hh"
#include "Snake.hh"

#include <algorithm>
#include <chrono>
#include <exception>

std::mt19937 Apple::gen(std::random_device{}());

Apple::Apple(const Snake &s) {
    newApple(s);
}

void Apple::newApple(const Snake &s) {
    std::uniform_int_distribution<> Xdistrib(0, MapConfig::WIDTH - 1);
    std::uniform_int_distribution<> Ydistrib(0, MapConfig::HEIGHT - 1);

    bool in_snake;
    int tmp_x, tmp_y;
    int trys = 0;
    do {
        tmp_x = Xdistrib(gen);
        tmp_y = Ydistrib(gen);
        in_snake = std::any_of(
            s.get_snake().begin(),
            s.get_snake().end(),
            [&](const peaceOfSkane& p) { return p.x == tmp_x && p.y == tmp_y; }
        );
        trys++;
        if (trys > 100)
            throw std::out_of_range("No space for a new apple");
    } while (in_snake);
    x = tmp_x;
    y = tmp_y;
}

std::ostream& operator<<(std::ostream& o,const Apple& a) {
    o << "Apple : x = " << a.getX() << " | " << a.getY() << std::endl;
    return o;
}
