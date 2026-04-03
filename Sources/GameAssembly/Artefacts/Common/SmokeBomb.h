#pragma once
#include "../Artefact.h"

class SmokeBomb : public Artefact
{
public:
    SmokeBomb();

    void ActingArtefact(Entity& target) override;
    void onInflictedDamage(Entity& target) override;
    void ActingArtefactEveryTurns(Entity &target) override;
};