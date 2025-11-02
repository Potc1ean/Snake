#pragma once
#include <iostream>
#include <list>

struct peaceOfSkane {
    int x;
    int y;
};

class Snake
{
    private:
        std::list<peaceOfSkane> body;
        int body_len;
    public:
        Snake();
        ~Snake();

        void run(char step);

        // --- getters ---
        std::list<peaceOfSkane> get_snake() const { return body; }
        int get_snake_len() { return body_len; }
};

std::ostream& operator<<(std::ostream &o, Snake s);
