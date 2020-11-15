#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
private:
    int x;
    int y;
    int moving;

public:
    Entity(int moving = 0);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getMoving();
    virtual void stats();
};

#endif