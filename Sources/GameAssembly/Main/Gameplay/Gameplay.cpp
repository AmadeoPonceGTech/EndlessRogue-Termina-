#include "../Gameplay/Gameplay.h"

/////// Include pour Alpha Sprint 1 ///////
#include <algorithm>

#include "../../Entities/Characters/Alex.h"
#include "../../Entities/Characters/Diane.h"
#include "../../Entities/Characters/Marcus.h"
//////////////////////////////////////////



Gameplay::Gameplay() {
    if (!enemyManager) {
        enemyManager = std::make_shared<EnemyManager>();
    }

    ////////////// Alpha Pour Sprint 1 ////////////////
    activeCharacters.push_back(std::make_shared<Alex>());
    activeCharacters.push_back(std::make_shared<Diane>());
    activeCharacters.push_back(std::make_shared<Marcus>());

    enemyManager->createEnemy<Rat>(1);
    enemyManager->createEnemy<Wolf>(1);
    enemyManager->createEnemy<Wolf>(1);

    for (auto& character : activeCharacters) {
        if (character) {
            speedVector.push_back(character);
        }
    }

    for (auto& ennemi : enemyManager->getEnemies()) {
        if (ennemi) {
            speedVector.push_back(ennemi);
        }
    }

    sort (speedVector.begin(), speedVector.end());
    ///////////////////////////////////////////////////

    StartRun();
    gameLoop();
}

void Gameplay::gameLoop()
{
    while (isRunning)
    {
        StartFight();
        /// manage speed
        EndFight();
    }
}

void Gameplay::StartRun() {
    //// Start the run and start all passif
    //// Chek if Diane is active
}


void Gameplay::EndRun() {
    ///// End the run (lose), reset and disable passif and give reward
    ///Apply XP
}

void Gameplay::StartFight() {
    /// create enemy in fight
    /// Add all Enemy in fight to the EnemyVector
    /// Check if Emilie is there
}

void Gameplay::EndFight() {
    /// Emilie
}
