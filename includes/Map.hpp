#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Snake.hpp"

class Map
{
    private:
        std::vector<std::string> map;
        static const int x = 20;
        static const int y = 20;

        static const char char_empty = ' ';
        static const char char_snake = 'o';
        static const char char_apple = '@';

        static const int int_empty = ' ';
        static const int int_snake = 'o';
        static const int int_apple = '2';
    public:
        Map(Snake s);
        ~Map() {};

        void refresh(const Snake &s);

        std::vector<std::string> get_map() const { return map; }
};

std::ostream& operator<<(std::ostream &o, Map &field) {
    std::vector<std::string> baddys_field = field.get_map();

    for (std::vector<std::string>::iterator i = baddys_field.begin(); i != baddys_field.end(); i++)
    {
        o << *i << std::endl;
    }
    return o;
}

Map::Map(Snake s) : map(y, std::string(x, int_empty)) { }


void Map::refresh(const Snake &s) {
    for (std::vector<std::string>::iterator i = map.begin(); i != map.end(); i++)
    {
        *i = std::string(x, int_empty);
    }

    std::list<peaceOfSkane> baddys = s.get_snake();

    for (std::list<peaceOfSkane>::iterator i = baddys.begin(); i != baddys.end(); i++)
    {
        std::string &tmp = map[i->y];
        tmp[i->x] = int_snake;
    }
}
