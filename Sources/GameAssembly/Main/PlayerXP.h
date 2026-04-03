#pragma once
#include <iostream>
#include <random>

enum class ERarities {
    COMMON,
    RARE,
    EPIC,
    LEGENDARY
};

enum class EUpgradeState {
    CHECKINGXP,
    GENERATEUPGRADE,
    CHOOSINGUPGRADE,
    APPLYUPGRADE
};

class PlayerXP {

    float currentXP;
    float XPNeededForLvl2;
    float XPNeeded;
    float finalXPNeeded;

    EUpgradeState upgradeState;

    std::random_device rd;

    std::vector<ERarities> tempVec;

    ERarities rarity1;
    ERarities rarity2;
    ERarities rarity3;

    int upgradeChoose1;
    int upgradeChoose2;
    int upgradeChoose3;

public:
    PlayerXP();

    void upgradeSystem(int level);
    bool levelUp(int level);
};

