#pragma once
#include "../Character.h"
#include "../../Enemies/Enemy.h"

#include <Termina/Scripting/API/ScriptingAPI.hpp>

using namespace TerminaScript;

class Enemy;

class Diane : public Character, public TerminaScript::ScriptableComponent
{
    std::shared_ptr<Enemy> selectedTargetE = nullptr;
    std::shared_ptr<Character> selectedTargetC = nullptr;

public :
    Diane();
    Diane(Termina::Actor* owner) : TerminaScript::ScriptableComponent(owner) {}

    void startRun(std::vector<std::shared_ptr<Entity>> &targets);
    void startTurn() override;
    void endTurn() override;
    bool entityTurn(std::vector<std::shared_ptr<Entity>> characters, std::vector<std::shared_ptr<Entity>> enemies) override;

    void Start() override;
    void Update(float deltaTime) override;

    void firstAbility(std::shared_ptr<Enemy>target);
    void secondAbility(std::shared_ptr<Enemy>target);
    void thirdAbility(std::shared_ptr<Character>target);
    void fourthAbility(std::vector<std::shared_ptr<Entity>> &targets);

};
