
#include "PlayerXP.h"

#include "../../ThirdParty/ImGui/imgui.h"

PlayerXP::PlayerXP() {
    upgradeState = EUpgradeState::CHECKINGXP;
}

bool PlayerXP::levelUp(int level)
{
    if (currentXP >= XPNeeded)
    {
        currentXP -= XPNeeded;
        XPNeeded = XPNeededForLvl2 + (finalXPNeeded - XPNeededForLvl2) * ((level - 1) / (9999 - 1));
        return true;
    }
    return false;
}

void PlayerXP::upgradeSystem(int level)
{
    static std::mt19937 rng(rd());

    switch (upgradeState) {
        case EUpgradeState::CHECKINGXP : {
            if (levelUp(level))
            {
                upgradeState = EUpgradeState::CHOOSINGUPGRADE;
            }
            break;
        }

        case EUpgradeState::GENERATEUPGRADE : {
            tempVec.clear();

            std::uniform_int_distribution<int> rarity(1, 100);
            std::uniform_int_distribution<int> commonBonuses(1, 8);
            std::uniform_int_distribution<int> rareBonuses(1, 8);
            std::uniform_int_distribution<int> epicBonuses(1, 8);
            std::uniform_int_distribution<int> legendaryBonuses(1, 4);

            for (int i = 0; i < 3; i++)
            {
                int rarityPercent = rarity(rng);

                if (rarityPercent <= 5) {
                    tempVec.push_back(ERarities::LEGENDARY);
                }
                else if (rarityPercent <= 15) {
                    tempVec.push_back(ERarities::EPIC);
                }
                else if (rarityPercent <= 30) {
                    tempVec.push_back(ERarities::RARE);
                }
                else if (rarityPercent <= 100) {
                    tempVec.push_back(ERarities::COMMON);
                }
            }

            rarity1 = tempVec[0];
            rarity2 = tempVec[1];
            rarity3 = tempVec[2];

            switch (rarity1) {
                case ERarities::COMMON : {
                    int bonus = commonBonuses(rng);

                    if (bonus == 1) {

                    }
                    else if (bonus == 2) {

                    }
                    else if (bonus == 3) {

                    }
                    else if (bonus == 4) {

                    }
                    else if (bonus == 5) {

                    }
                    else if (bonus == 6) {

                    }
                    else if (bonus == 7) {

                    }
                    else if (bonus == 8) {

                    }

                    break;
                }

                case ERarities::RARE : {
                    int bonus = rareBonuses(rng);
                    break;
                }

                case ERarities::EPIC : {
                    int bonus = epicBonuses(rng);
                    break;
                }

                case ERarities::LEGENDARY : {
                    int bonus = legendaryBonuses(rng);
                    break;
                }
            }

        }

        case EUpgradeState::CHOOSINGUPGRADE : {

            ImGui::Begin("Choose an upgrade");



            ImGui::End();
            break;
        }

        case EUpgradeState::APPLYUPGRADE : {

            break;
        }
    }
}
