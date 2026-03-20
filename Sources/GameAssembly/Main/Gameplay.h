#pragma once

#include <vector>
#include <memory>

#include "../Entities/Enemies/EnemyManager.h"

#pragma region EntityInclude

#include "../Entities/Characters/Character.h"
#include "../Entities/Enemies/Rat.h"
#include "../Entities/Enemies/Wolf.h"
#pragma endregion EntityInclude

class Gameplay {
private:
    std::shared_ptr<EnemyManager> enemyManager;
    std::vector<std::shared_ptr<Character>> activeCharacters;
    std::vector<std::shared_ptr<Entity>> speedVector;

public:

    Gameplay();
    void StartRun();
    void EndRun();

    void StartFight();
    void EndFight();

    void StartTurn();
    void EndTurn();


};

