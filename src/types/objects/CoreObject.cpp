#include "types/objects/CoreObject.hpp"
#include "types/Component.hpp"
#include <algorithm>
#include <string.h>

namespace Amazonian {
    char* CoreObject::getID() {
        return this->id;
    }

    void CoreObject::setID(char* id) {
        this->id = id;
    }

    void CoreObject::setID(std::string id) {
        strcpy_s(this->id, sizeof this->id, id.c_str());
    }
}