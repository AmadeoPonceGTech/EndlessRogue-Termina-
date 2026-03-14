#include "ScriptSystem.hpp"
#include "Core/Application.hpp"
#include "Core/FileSystem.hpp"
#include "Platform/LaunchProcess.hpp"
#include "Scripting/ScriptModuleManager.hpp"
#include "World/WorldSystem.hpp"
#include "Core/Logger.hpp"

#include <ImGui/imgui.h>
#include <cstring>

namespace Termina {
    std::string ScriptSystem::GetLibName() const
    {
#if defined(TRMN_DEBUG)
        const std::string& base = m_AssemblyName;
#else
        const std::string base = "GameAssembly";
#endif
#if defined(TRMN_LINUX)
        return "lib" + base + ".so";
#elif defined(TRMN_WINDOWS)
        return base + ".dll";
#elif defined(TRMN_MACOS)
        return "lib" + base + ".dylib";
#endif
    }

    ScriptSystem::ScriptSystem()
    {
        ScriptModuleManager::Get().Load("Game", GetLibName());
#if defined(TRMN_DEBUG)
        RebuildWatches();
#endif
    }

    ScriptSystem::~ScriptSystem()
    {
        for (auto& [name, path] : ScriptModuleManager::Get().GetLoadedModules())
            ScriptModuleManager::Get().Unload(name);
    }

    bool ScriptSystem::Compile()
    {
#if defined(TRMN_DEBUG)
        return LaunchProcess::Launch("xmake", {"build", m_AssemblyName}) == 0;
#else
        return true;
#endif
    }

    bool ScriptSystem::Recompile()
    {
#if defined(TRMN_DEBUG)
        LaunchProcess::Launch("xmake", {"clean", m_AssemblyName});
        return LaunchProcess::Launch("xmake", {"build", m_AssemblyName}) == 0;
#else
        return true;
#endif
    }

    void ScriptSystem::RebuildWatches()
    {
#if defined(TRMN_DEBUG)
        m_Watches.clear();
        if (FileSystem::DirectoryExists(m_GameCodeDir)) {
            for (auto& file : FileSystem::GetFilesRecursive(m_GameCodeDir)) {
                if (FileSystem::HasExtension(file, ".cpp") || FileSystem::HasExtension(file, ".hpp"))
                    m_Watches.push_back(FileSystem::WatchFile(file));
            }
        }
#endif
    }

    void ScriptSystem::Update(float deltaTime)
    {
#if defined(TRMN_DEBUG)
        // Execute reload at start of frame (priority -1 ensures we run before WorldSystem)
        // so no component list is being iterated when we add/remove components.
        if (m_PendingReload) {
            m_PendingReload = false;
            if (!Compile()) {
                TN_ERROR("Failed to compile scripts");
                RebuildWatches();
                return;
            } else {
                World* world = Application::GetSystem<WorldSystem>()->GetCurrentWorld();
                ScriptModuleManager::Get().Reload("Game", world);
                RebuildWatches();
                return;
            }
        }

        for (const auto& watch : m_Watches) {
            if (FileSystem::HasFileChanged(watch)) {
                m_PendingReload = true;
                return;
            }
        }
#endif
    }

    void ScriptSystem::ShowDebugWindow(bool* open)
    {
        if (!ImGui::Begin("Script System", open))
        {
            ImGui::End();
            return;
        }

#if defined(TRMN_DEBUG)
        ImGui::SeparatorText("Settings");

        char dirBuf[256];
        char nameBuf[256];
        std::strncpy(dirBuf, m_GameCodeDir.c_str(), sizeof(dirBuf) - 1);
        std::strncpy(nameBuf, m_AssemblyName.c_str(), sizeof(nameBuf) - 1);

        if (ImGui::InputText("Script Directory", dirBuf, sizeof(dirBuf)))
        {
            m_GameCodeDir = dirBuf;
            RebuildWatches();
        }
        if (ImGui::InputText("Assembly Name", nameBuf, sizeof(nameBuf)))
            m_AssemblyName = nameBuf;

        ImGui::Spacing();
        ImGui::SeparatorText("Actions");

        if (ImGui::Button("Build"))
            Compile();
        ImGui::SameLine();
        if (ImGui::Button("Rebuild"))
            Recompile();
        ImGui::SameLine();
#endif
        {
            bool alreadyLoaded = ScriptModuleManager::Get().IsLoaded("Game");
            if (alreadyLoaded)
                ImGui::BeginDisabled();
            if (ImGui::Button("Load"))
                ScriptModuleManager::Get().Load("Game", GetLibName());
            if (alreadyLoaded)
                ImGui::EndDisabled();
        }
        ImGui::SameLine();
        if (ImGui::Button("Reload"))
        {
            World* world = Application::GetSystem<WorldSystem>()->GetCurrentWorld();
            ScriptModuleManager::Get().Reload("Game", world);
        }

        ImGui::SeparatorText("Status");

        ImGui::Text("Pending reload: %s", m_PendingReload ? "yes" : "no");
        ImGui::Text("Watched files: %zu", m_Watches.size());
        ImGui::Separator();

        auto modules = ScriptModuleManager::Get().GetLoadedModules();
        ImGui::Text("Loaded modules: %zu", modules.size());

        for (auto& [name, path] : modules)
        {
            if (ImGui::CollapsingHeader(name.c_str()))
            {
                ImGui::TextUnformatted(path.c_str());
                ImGui::Spacing();

                auto components = ScriptModuleManager::Get().GetComponentNamesForModule(name);
                ImGui::Text("Components (%zu):", components.size());
                for (auto& comp : components)
                    ImGui::BulletText("%s", comp.c_str());
            }
        }

        ImGui::End();
    }
}
