#pragma once

#include <vector>
#include <memory>
#include <random>
#include "../../Entities/Enemies/EnemyManager.h"

//////////////
#include "../../Entities/Characters/Close DPS/Alex.h"
#include "../../Entities/Characters/Close DPS/Penelope.h"
#include "../../Entities/Characters/Tank/Diane.h"
#include "../../Entities/Characters/Tank/Emilie.h"
#include "../../Entities/Characters/Support/Marcus.h"
#include "../../Entities/Characters/Support/Claire.h"
#include "../../Entities/Characters/Range DPS/Brutus.h"
#include "../../Entities/Characters/Range DPS/Edward.h"
//////////////////////////////////////////

#pragma region EntityInclude

#include "../../Entities/Characters/Character.h"
#include "../../Entities/Enemies/Rat.h"
#include "../../Entities/Enemies/Wolf.h"
#pragma endregion EntityInclude

enum class EGameRunState
{
    StartRun,
    StartFight,
    UpdateTurn,
    EndFight,
    EndRun
};

class Gameplay {
private:
    std::vector<std::string> tempCharacterVec;
    std::shared_ptr<EnemyManager> enemyManager;
    std::vector<std::shared_ptr<Entity>> activeCharacters;
    std::vector<std::shared_ptr<Entity>> turnOrderVector;

    bool isRunning = false;
    bool isInFight = false;

    EGameRunState runState;

public:

    Gameplay();
    void StartRun();
    void EndRun();

    void StartFight();
    void EndFight();

    void Gameloop();
    void UpdateTurn();

    std::vector<std::string> getTempCharacterVec();

    bool HasSameType(const Entity& entity) const;
    void AddToTeam(const std::shared_ptr<Entity>& entity);
    void RemoveFromTeam(const std::shared_ptr<Entity>& entity);

    bool TeamIsComplete();
    bool IsInTeam(const std::shared_ptr<Entity>& entity);

};

