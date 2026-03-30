#pragma once
#include "../Artefact.h"

class SmokeBomb : public Artefact
{
public:
    SmokeBomb();

    void ActingArtefact(Entity& target) override;
    void onDamageTaken(Entity& target) override;
};