#pragma once
#include <memory>
#include <Termina/Scripting/API/ScriptingAPI.hpp>
#include "ImGui/imgui.h"
#include "ImGui/ImGuizmo.h"
#include "ImGui/imgui_internal.h"
#include "RogueGameplay.h"

using namespace TerminaScript;

enum GameState {
    GameMenu,
    GameRun,
    GameCharacterStats
};


class Game : public TerminaScript::ScriptableComponent
{
public:
    std::unique_ptr<RogueGameplay> gameplay;
    GameState gameState = GameCharacterStats;

    Game() = default;
    Game(Termina::Actor* owner) : TerminaScript::ScriptableComponent(owner) {}

    void Start()  override;
    void Update(float deltaTime) override;
};