#include "Rat.h"

Rat::Rat() {
    name = "Rat";
    eClass = EClass::Assassin;
    description = "Le rat est un animal discret, très proche de l'homme";

    level = 1;
    maxLevel = 9999;

    baseHealth = 20;
    maxHealth = baseHealth + (9999 - baseHealth) * (level - 1 / 9999 - 1);
    currentHealth = maxHealth;


}
