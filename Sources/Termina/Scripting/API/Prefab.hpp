#pragma once

#include <string>

namespace TerminaScript {
    /// A reference to a prefab asset (.trp file). Use as a component field
    /// to allow spawning actors from saved prefabs at runtime.
    struct Prefab {
        std::string Path;

        Prefab() = default;
        explicit Prefab(const std::string& path) : Path(path) {}
        Prefab(const char* path) : Path(path) {}

        bool IsValid() const { return !Path.empty(); }
        operator bool() const { return IsValid(); }

        /// Renders a label and a drop-target button for this prefab in the inspector.
        /// Returns true if the path was changed by a drag-drop.
        bool Inspect(const char* label);
    };
}
