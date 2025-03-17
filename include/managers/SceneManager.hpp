#pragma once

#include <vector>

#include <types/Scene.hpp>

namespace Amazonian {
    class SceneManager {
    public:
        static SceneManager* get() {
            static SceneManager instance;
            return &instance;
        }

    protected:
        std::vector<Scene*> scenes;
    };
}