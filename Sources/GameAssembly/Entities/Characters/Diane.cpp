//
// Created by mprevost on 18/03/2026.
//

#include "Diane.h"

Diane::Diane()
{
    name = "Diane";
    entityClass = EClass::TANK;
    description = "Diane is a women";

    level = 1;

    baseHealth = 100;
    maxHealth = baseHealth + (1000 - baseHealth) * ((level - 1) / (maxLevel - 1));
    currentHealth = maxHealth;

    baseAttackDamage = 2.5f;
    maxAttackDamage = baseAttackDamage + (250 - baseAttackDamage) * ((level - 1) / (maxLevel - 1));
    currentAttackDamage = baseAttackDamage;

    baseAttackPower = 20;
    maxAttackPower = baseAttackPower + (200 - baseAttackPower) * ((level - 1) / (maxLevel - 1));
    currentAttackPower = baseAttackPower;

    baseArmor = 5;
    maxArmor = baseArmor + (50 - baseArmor) * ((level - 1) / (maxLevel - 1));
    currentArmor = baseArmor;

    basePowerResist = 4;
    maxPowerResist = baseAttackPower + (30 - basePowerResist) * ((level - 1) / (maxLevel - 1));
    currentPowerResist = basePowerResist;

    speed = 100;
}

void Diane::Start()
{
    // Called once when the scene starts playing.
}

void Diane::Update(float deltaTime)
{
    // Called every frame. deltaTime is seconds since last frame.
}
