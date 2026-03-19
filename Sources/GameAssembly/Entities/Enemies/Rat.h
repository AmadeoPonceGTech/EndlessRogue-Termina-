#pragma once
#include "Enemy.h"

class Rat : public Enemy {
    Rat();

    void dropArtefacts() override;

    void firstAbility() override;
    void secondAbility() override;
    void thirdAbility() override;
    void fourthAbility() override;
};
