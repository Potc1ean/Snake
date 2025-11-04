#include "Snake.hh"
#include "Map.hh"
#include "Apple.hh"

Snake::Snake() : body_len(3) {
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

Snake::~Snake()
{
}

void Snake::run(char step, Apple &apple) {
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
    if (head.x == apple.getX() && head.y == apple.getY()) {
        apple.newApple(*this);
        body_len++;
    }
    else
        body.pop_front();
}

std::ostream& operator<<(std::ostream &o, Snake s) {
    std::list<peaceOfSkane> baddys = s.get_snake();
    int n = 0;

    o << "////////////////////"<< std::endl;
    for (std::list<peaceOfSkane>::iterator it = baddys.begin(); it != baddys.end(); it++)
    {
        o << "Peace of snake n*" << n << " : " << std::endl;
        o << "x = " << it->x << " | " <<  "y = " << it->y << std::endl;
        n++;
    }
    o << "////////////////////"<< std::endl;

    return o;
}
