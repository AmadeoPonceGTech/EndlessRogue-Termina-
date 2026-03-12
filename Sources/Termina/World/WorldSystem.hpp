#pragma once

#include <Termina/Core/System.hpp>

namespace Termina {
    class WorldSystem : public ISystem {
    public:
        WorldSystem() {}
        ~WorldSystem() {}

        void PreUpdate(float deltaTime) override {}
        void Update(float deltaTime) override {}
        void PostUpdate(float deltaTime) override {}
        void PrePhysics(float deltaTime) override {}
        void Physics(float deltaTime) override {}
        void PostPhysics(float deltaTime) override {}
        void PreRender(float deltaTime) override {}
        void Render(float deltaTime) override {}
        void PostRender(float deltaTime) override {}

        void RegisterComponents() override;
        void UnregisterComponents() override;

        UpdateFlags GetUpdateFlags() const override { return UpdateFlags::UpdateDuringEditor | UpdateFlags::RenderUpdateDuringEditor | UpdateFlags::PhysicsUpdateDuringEditor; }
        std::string GetName() const override { return "World System"; }
        int GetPriority() const override { return 0; }
    };
}
