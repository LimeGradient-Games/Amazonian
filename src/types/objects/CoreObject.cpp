#include "types/objects/CoreObject.hpp"
#include <cstring>

namespace Amazonian {
    char* CoreObject::getID() {
        return this->id;
    }

    void CoreObject::setID(char* id) {
        this->id = id;
    }

    void CoreObject::setID(std::string id) {
        std::strcpy(this->id, id.c_str());
    }
}