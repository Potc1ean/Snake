#pragma once
#include <iostream>
#include <list>

struct peaceOfSkane {
    int x;
    int y;
};

class Apple;

class Snake
{
    private:
        std::list<peaceOfSkane> body;
        int body_len;
    public:
    // --- Constructors / Destructors ---
        Snake();
        ~Snake();
    // --- Methods ---
        void run(char step, Apple &apple);
    // --- getters ---
        const std::list<peaceOfSkane>& get_snake() const { return body; }
        int get_snake_len() { return body_len; }
};

std::ostream& operator<<(std::ostream &o, Snake s);
