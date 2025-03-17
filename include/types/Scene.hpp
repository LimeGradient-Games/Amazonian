#pragma once

namespace Amazonian {
    class Scene {
    public:
        virtual void init() {}
        virtual void draw() {}
        virtual void remove() {}
        virtual void get() {}
    };
}