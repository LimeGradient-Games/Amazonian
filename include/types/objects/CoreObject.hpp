#pragma once

#include <algorithm>
#include <any>
#include <string>
#include <types/Component.hpp>
#include <vector>

namespace Amazonian {
    class CoreObject {
    protected:
        char* id;
        std::vector<Component*> components;
    
    public:
        char* getID();
        void setID(char* id);
        void setID(std::string id);

        template<typename T> 
        void addComponent(T* component) {
            this->components.push_back(component);
            component->init();
        }
        
        template<typename T>
        T* getComponent() {
            auto it = std::find_if(this->components.begin(), this->components.end(), [](Component* element) {
                return typeid(*element) == typeid(T);
            });
    
            if (it != this->components.end()) {
                return static_cast<T*>(*it);
            }
    
            return nullptr;
        }

        template<typename T>
        void removeComponent() {
            for (Component* component : this->components) {
                if (typeid(*component) == typeid(T)) {
                    static_cast<T*>(component)->remove();
                    this->components.erase(std::remove(this->components.begin(), this->components.end(), component), this->components.end());
                    return;
                }
            }
        }
    };
}