#pragma once

#include <string>

namespace Amazonian {
    class CoreObject {
    protected:
        char* id;
    
    public:
        char* getID();
        void setID(char* id);
        void setID(std::string id);
    };
}