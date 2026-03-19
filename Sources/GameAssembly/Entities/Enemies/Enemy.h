#pragma once
#include "../Entity.h"

class Enemy : public Entity
{
public:
    Enemy();

    virtual void startTurn() = 0;
    virtual void endTurn() = 0;

    float baseExpDrop;
    float currentExpDrop;
    float maxExpDrop;

    float finalArmor;
    float finalPR;

    int landing;

    virtual void dropArtefacts() = 0;
};
