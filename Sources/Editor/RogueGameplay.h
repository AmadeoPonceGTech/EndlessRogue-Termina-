#pragma once
#include <Termina/Scripting/API/ScriptingAPI.hpp>

using namespace TerminaScript;

class RogueGameplay : public TerminaScript::ScriptableComponent
{
public:

    RogueGameplay() = default;
    RogueGameplay(Termina::Actor* owner) : TerminaScript::ScriptableComponent(owner) {}

    void Start()  override;
    void Update(float deltaTime) override;
};