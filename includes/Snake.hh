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
    // --- Attributs ---
        std::list<peaceOfSkane> body;
        int body_len;
        bool has_collided;
        char last_step;
        
    // --- Privates methods ---
        bool isOutOfBounds() const;
        bool isCollidingWithSelf() const;
        
    public:
    // --- Constructors / Destructors ---
        Snake();
        ~Snake() = default;

    // --- Methods ---
        void run(char step, Apple &apple);
        void updateCollision();
        
    // --- getters ---
        const std::list<peaceOfSkane>& get_snake() const { return body; }
        int get_snake_len() { return body_len; }
        bool hasCollided() const { return has_collided; }
};

std::ostream& operator<<(std::ostream &o, const Snake &s);
