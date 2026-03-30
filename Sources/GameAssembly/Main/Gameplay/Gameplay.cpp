#include "../Gameplay/Gameplay.h"

Gameplay::Gameplay() {
    if (!enemyManager) {
        enemyManager = std::make_shared<EnemyManager>();
    }
}

void Gameplay::StartRun() {
    auto it = std::find_if(activeCharacters.begin(), activeCharacters.end(),
        [](const std::shared_ptr<Entity>& e)
        {
            return dynamic_cast<Diane*>(e.get()) != nullptr;
        });

    if (it != activeCharacters.end()) {
        std::shared_ptr<Diane> diane = std::dynamic_pointer_cast<Diane>(*it);
        diane->startRun(activeCharacters);
    }
}


void Gameplay::EndRun() {
    isRunning = false;
    ///// End the run (lose), reset and disable passif and give reward
    ///Apply XP
}


void Gameplay::StartFight() {

    isInFight = true;

    for (auto& character : activeCharacters) {
        if (character) {
            turnOrderVector.push_back(character);
        }
    }

    /// Add all Enemy in fight to the EnemyVector
    /// create predeterminated ennemy, push in vector and rearrange order via speed
    enemyManager->createEnemy<Rat>(1);
    enemyManager->createEnemy<Wolf>(1);
    enemyManager->createEnemy<Wolf>(1);

    for (auto& ennemi : enemyManager->getEnemies()) {
        if (ennemi) {
            turnOrderVector.push_back(ennemi);
        }
    }

    UpdateTurn();
    /// Check if Emilie is there
}

void Gameplay::EndFight() {
    turnOrderVector.clear();

    for (auto& character : activeCharacters)
    {
        if (character)
            turnOrderVector.push_back(character);
    }
    enemyManager->clearEnemies();
    isInFight = false;
    /// Emilie
    /// Clean du vector enemy
}

void Gameplay::UpdateTurn()
{
    while (isInFight)
    {
        for (auto& entity : turnOrderVector)
        {
            if (!entity || entity->getIsDead())
                continue;

            entity->entityTurn(activeCharacters, enemyManager->getEnemies());
        }

        bool allPlayersDead = std::all_of( activeCharacters.begin(),activeCharacters.end(),[](const std::shared_ptr<Entity>& e){return !e || e->getIsDead();});
        bool allEnemiesDead = std::all_of(enemyManager->getEnemies().begin(),enemyManager->getEnemies().end(),[](const std::shared_ptr<Entity>& e){return !e || e->getIsDead(); });

        if (allPlayersDead)
        {
            isInFight = false;
            isRunning = false;
        }

        if (allEnemiesDead)
        {
            isInFight = false;
        }

    }
}

void Gameplay::Gameloop()
{
    switch (runState) {
        case EGameRunState::StartRun :
            StartRun();
            runState = EGameRunState::StartFight;
            break;
        case EGameRunState::StartFight :
            StartFight();
            runState = EGameRunState::UpdateTurn;
            break;
        case EGameRunState::UpdateTurn :
            UpdateTurn();
            break;
        case EGameRunState::EndFight :
            EndFight();
            runState = EGameRunState::StartFight;
            break;
        case EGameRunState::EndRun :
            EndRun();
            break;
    }
}

std::vector<std::string> Gameplay::getTempCharacterVec() {
    return tempCharacterVec;
}

bool Gameplay::HasSameType(const Entity& entity) const
{
    return std::any_of(activeCharacters.begin(), activeCharacters.end(),
        [&entity](const std::shared_ptr<Entity>& e) {
            return typeid(*e) == typeid(entity);
        });
}

void Gameplay::AddToTeam(const std::shared_ptr<Entity>& entity) {
    if (!entity) {
        std::cout << "Invalid entity\n";
        return;
    }

    if (activeCharacters.size() > 3 ) {
        std::cout << "Team Max Size Reached" << std::endl;
        return;
    }

    if (HasSameType(*entity)) {
        std::cout << entity->getName() << " is already in the team\n";
        return;
    }
    activeCharacters.push_back(entity);
    std::cout << entity->getName() << " added to team" << std::endl;
}

void Gameplay::RemoveFromTeam(const std::shared_ptr<Entity>& entity)
{
    if (!entity) {
        std::cout << "Invalid entity\n";
        return;
    }

    auto it = std::find(activeCharacters.begin(), activeCharacters.end(), entity);

    if (it == activeCharacters.end()) {
        std::cout << entity->getName() << " not in team\n";
        return;
    }

    activeCharacters.erase(it);
    std::cout << entity->getName() << " remove from team" << std::endl;
}


////////// Check if Team is Complete or If the character is already in team
bool Gameplay::TeamIsComplete() {
    if (activeCharacters.size() == 4) {
        return true;
    }
    return false;
}

bool Gameplay::IsInTeam(const std::shared_ptr<Entity> &entity) {
    auto it = std::find(activeCharacters.begin(), activeCharacters.end(), entity);
    if (it != activeCharacters.end()) {
        return true;
    }
    return false;
}


