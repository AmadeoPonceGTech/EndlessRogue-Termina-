#pragma once
#include "Enemy.h"
#include <GameAssembly/Entities/Characters/Character.h>

#include <Termina/Scripting/API/ScriptingAPI.hpp>

class Character;

class Rat : public Enemy, public TerminaScript::ScriptableComponent
{
public :
    Rat(int level);
    Rat(Termina::Actor* owner) : TerminaScript::ScriptableComponent(owner) {}

    void Start() override;
    void Update(float deltaTime) override;

    void checkAbilities() override;
    void dropArtefacts() override;

    float firstAbility(Character& target);
    void secondAbility(Character& target);
    float thirdAbility(Character& target);

    /// \brief Prend le vector des characters présents sur le terrain, et renvoie un vector des degats qu'ils doivent prendre dans l'ordre
    std::vector<float> fourthAbility(const std::vector<Character*>& targets);
};
