#pragma once
#include "../Entity.h"

class Enemy : public Entity
{
public:
    Enemy();

    virtual void startTurn() = 0;
    virtual void endTurn() = 0;

    float currentXP;
    float XPNeeded;

    float finalArmor;
    float finalPR;

    virtual void dropArtefacts() = 0;
};
