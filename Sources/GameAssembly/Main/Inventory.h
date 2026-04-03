#pragma once

#include <string>
#include <unordered_map>
#include "../Artefacts/Artefact.h"

enum class EInventoryState {
    SHOWALL,
    SHOWONE,
    ASSIGNONE
};

class Inventory {
public:
    Inventory();
    void addItem(const std::string& name, int amount);
    int getItemCount(const std::string& name) const;
    void removeItem(const std::string& name, int amount);

    void addArtefact(std::shared_ptr<Artefact> artefact);
    std::vector<std::shared_ptr<Artefact>> getArtefactsInventory() const;
    void removeArtefactInventory(std::shared_ptr<Artefact> artefact);

    void drawArtefactsInventory(std::vector<std::shared_ptr<Entity>>& characters);

private:
    std::unordered_map<std::string, int> items;
    std::vector<std::shared_ptr<Artefact>> artefactsInventory;
    EInventoryState currentInventoryState;

    std::shared_ptr<Artefact> targetArtefact;
    std::shared_ptr<Character> selectedCharacter;

    void checkArtefactsInventory();

};