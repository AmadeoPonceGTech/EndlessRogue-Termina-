#pragma once
#include "../Artefact.h"

class MaliciousEye : public Artefact
{
public:
    MaliciousEye();

    void ActingArtefact(Entity& target) override;
    void onInflictedDamage(Entity& target) override;
    void ActingArtefactEveryTurns(Entity &target) override;
};