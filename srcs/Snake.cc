#include "Snake.hh"
#include "Map.hh"
#include "Apple.hh"

#include <algorithm>
#include <cstring>

bool Snake::isOutOfBounds() const {
    const auto& head = body.back();
    return head.x < 0 || head.x >= MapConfig::WIDTH ||
           head.y < 0 || head.y >= MapConfig::HEIGHT;
}

bool Snake::isCollidingWithSelf() const {
    const auto& head = body.back();
    return std::any_of(body.begin(), std::prev(body.end()),
        [&](const peaceOfSkane& p) { return p.x == head.x && p.y == head.y; });
}

Snake::Snake(char step) : body_len(3), has_collided(false), last_step(step) {
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

void Snake::updateCollision() {
    has_collided = isOutOfBounds() || isCollidingWithSelf();
}

void Snake::run(char step, Apple &apple) {
    peaceOfSkane tmp = body.back();

    peaceOfSkane head;
    head.x = tmp.x;
    head.y = tmp.y;

    if (std::strchr("wsda", step) == NULL)
        step = last_step;
    if (step == 'w')
        head.y--;
    else if (step == 's')
        head.y++;
    else if (step == 'd')
        head.x++;
    else if (step == 'a')
        head.x--;

    body.push_back(head);

    if (head.x == apple.getX() && head.y == apple.getY()) {
        apple.newApple(*this);
        body_len++;
    }
    else
        body.pop_front();

    updateCollision();
    last_step = step;
}

std::ostream& operator<<(std::ostream &o, const Snake& s) {
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
