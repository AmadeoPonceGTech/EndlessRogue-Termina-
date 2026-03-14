#include "Prefab.hpp"
#include <Termina/Renderer/UIUtils.hpp>
#include <ImGui/imgui.h>

namespace TerminaScript {
    bool Prefab::Inspect(const char* label)
    {
        ImGui::TextUnformatted(label);
        ImGui::SameLine();
        return Termina::UIUtils::PrefabPicker(Path);
    }
}
