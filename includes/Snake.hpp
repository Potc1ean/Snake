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
    int len;
public:
    Snake(/* args */);
    ~Snake();

    void run(char step);

    std::list<peaceOfSkane> get_snake() const { return body; }
    int get_snake_len() { return len; }
};

Snake::Snake() : len(3) {
    peaceOfSkane head;
    head.x = 2;
    head.y = 0;

    peaceOfSkane mid;
    mid.x = 1;
    mid.y = 0;

    peaceOfSkane tail;
    tail.x = 0;
    tail.y = 0;

    body.push_back(tail);
    body.push_back(mid);
    body.push_back(head);
}

std::ostream& operator<<(std::ostream &o, Snake s) {
    std::list<peaceOfSkane> baddys = s.get_snake();
    int n = 0;

    o << "////////////////////"<< std::endl;

    for (std::list<peaceOfSkane>::iterator i = baddys.begin(); i != baddys.end(); i++)
    {
        o << "Peace of snake n*" << n << " : " << std::endl;
        o << "x = " << i->x << " | " <<  "y = " << i->y << std::endl;
        n++;
    }
    o << "////////////////////"<< std::endl;

    return o;
}

Snake::~Snake()
{
}

void Snake::run(char step) {
    peaceOfSkane tmp = body.back();

    peaceOfSkane head;
    head.x = tmp.x;
    head.y = tmp.y;

    if (step == 'w')
        head.y--;
    else if (step == 's')
        head.y++;
    else if (step == 'd')
        head.x++;
    else if (step == 'a')
        head.x--;
    else 
        return;
    body.push_back(head);
    body.pop_front();
}
