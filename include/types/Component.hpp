#pragma once

namespace Amazonian {
    class Component {
    public:
        virtual void init() {};
        virtual void update() {};
        virtual void remove() {};
    };
}