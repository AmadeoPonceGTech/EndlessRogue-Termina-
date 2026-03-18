#pragma once
#include "Character.h"

#include <Termina/Scripting/API/ScriptingAPI.hpp>

using namespace TerminaScript;

class Diane : public Character
{
public :
    Diane();
    Diane(Termina::Actor* owner) : TerminaScript::ScriptableComponent(owner) {}

    void Start()  override;
    void Update(float deltaTime) override;

    void checkAbilites() override;
    void firstAbility() override;
};
