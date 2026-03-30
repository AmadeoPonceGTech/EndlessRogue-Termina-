#include "SmokeBomb.h"

SmokeBomb::SmokeBomb() {
    name = "Smoke Bomb";
    description = "Improve speed by 2%";
}

void SmokeBomb::ActingArtefact(Entity& target) {
    target.setCurrentSpeed(target.getCurrentSpeed() + target.getCurrentSpeed() * 2.0f / 100.0f);
}

void SmokeBomb::onDamageTaken(Entity& target) {
    //target.setCurrentHealth(target.getCurrentHealth() + target.getMaxHealth() * 2.0f / 100.0f);
}
