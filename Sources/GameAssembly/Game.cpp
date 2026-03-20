#include "Game.h"


#include <iostream>
#include <ostream>

void Game::Start()
{
    if (!gameplay) {
        gameplay = std::make_unique<Gameplay>();
    }
}

void Game::Update(float deltaTime)
{
    bool show = true;
    ImGui::SetNextWindowSize(ImVec2(500, 500));
    ImGui::Begin("ImGui Menu", &show);
    ImGui::RadioButton("radio a",(int*)&gameState, GameRun); ImGui::SameLine();
    ImGui::RadioButton("radio b", (int*)&gameState, GameMenu); ImGui::SameLine();
    ImGui::RadioButton("radio c", (int*)&gameState, GameCharacterStats);
    ImGui::End();

    switch (gameState) {

        case GameRun :
            gameplay->EndFight();
            break;
        case GameMenu :
            gameplay->StartFight();
            break;
        case GameCharacterStats :
            gameplay->StartTurn();
            break;

        default:
            break;
    }

}
