#pragma once
#include "../Entity.h"

class Character : public Entity
{
public:
    Character();

    virtual void checkAbilities() = 0;
};
