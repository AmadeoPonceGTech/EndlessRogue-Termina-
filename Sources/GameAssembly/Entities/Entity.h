#pragma once
#include <iostream>

enum class EClass {
    ASSASSIN,
    CLOSEDDPS,
    RANGEDDPS,
    TANK,
    SUPPORT
};

class Entity
{
protected:
    std::string name;
    EClass entityClass;
    std::string description;

    int level;
    int maxLevel;

    float baseHealth; // lvl 1 value
    float currentHealth;
    float maxHealth; // calculated depending on the level

    float baseAttackDamage;
    float currentAttackDamage;
    float maxAttackDamage;

    float baseAttackPower;
    float currentAttackPower;
    float maxAttackPower;

    float baseArmor;
    float currentArmor;
    float maxArmor;

    float basePowerResist;
    float currentPowerResist;
    float maxPowerResist;

    float speed;

public:
    virtual ~Entity() = default;

    Entity() = default;

    virtual void firstAbility(bool isPassive) = 0;
    virtual void secondAbility(bool isPassive) = 0;
    virtual void thirdAbility(bool isPassive) = 0;
    virtual void fourthAbility(bool isPassive) = 0;
};