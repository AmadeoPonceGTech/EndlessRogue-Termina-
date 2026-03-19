#pragma once
#include "../Entity.h"

class Enemy : public Entity
{
public:
    Enemy() = default;

    virtual void dropArtefacts() = 0;

    void firstAbility(bool isPassive) override;
    void secondAbility(bool isPassive) override;
    void thirdAbility(bool isPassive) override;
    void fourthAbility(bool isPassive) override;
};
