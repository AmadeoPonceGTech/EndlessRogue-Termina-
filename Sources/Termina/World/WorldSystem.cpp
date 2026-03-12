#include "WorldSystem.hpp"

#include "ComponentRegistry.hpp"
#include "Components/Transform.hpp"

namespace Termina {
    void WorldSystem::RegisterComponents()
    {
        ComponentRegistry::Get().Register<Transform>("Transform");
    }

    void WorldSystem::UnregisterComponents()
    {
        ComponentRegistry::Get().Unregister<Transform>();
    }
}
