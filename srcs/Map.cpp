#include "Map.hpp"
#include "Snake.hpp"

#include <cstdlib>

Map::Map(const Snake &s) 
    : map(MapConfig::HEIGHT, std::string(MapConfig::WIDTH, MapConfig::EMPTY)) { }


void Map::refresh(const Snake &s) {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    for (std::vector<std::string>::iterator i = map.begin(); i != map.end(); i++)
        *i = std::string(MapConfig::WIDTH, MapConfig::EMPTY);

    std::list<peaceOfSkane> baddys = s.get_snake();

    for (std::list<peaceOfSkane>::iterator i = baddys.begin(); i != baddys.end(); i++)
    {
        std::string &tmp = map[i->y];
        tmp[i->x] = MapConfig::SNAKE;
    }
}

std::ostream& operator<<(std::ostream &o, Map &field) {
    std::vector<std::string> baddys_field = field.getMap();

    for (int i = 0; i < MapConfig::WIDTH * 2 + 2; i++)
        o << MapConfig::BORDER;
    o <<std::endl;
    for (std::vector<std::string>::iterator i = baddys_field.begin(); i != baddys_field.end(); i++)
    {
        std::string tmp;
        tmp.reserve(MapConfig::WIDTH * 2);
        for (int y = 0; y < MapConfig::WIDTH; ++y) {
            tmp.push_back((*i)[y]);
            tmp.push_back(' ');
        }
        o << MapConfig::BORDER << tmp << MapConfig::BORDER <<std::endl;
    }
    for (int i = 0; i < MapConfig::WIDTH * 2 + 2; i++)
        o << MapConfig::BORDER;
    o <<std::endl;
    return o;
}
