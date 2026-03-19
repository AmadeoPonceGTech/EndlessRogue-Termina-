//
// Created by lmarcucci on 18/03/2026.
//

#include "EnemyManager.h"

#include <memory>

EnemyManager::EnemyManager() {}

void EnemyManager::clearEnemies() { enemies.clear(); }

const std::vector<std::unique_ptr<Enemy>>& EnemyManager::getEnemies() const { return enemies; }