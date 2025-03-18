#include "types/objects/resources/Model.hpp"

namespace Amazonian {
    void Model::draw() {
        DrawModel(this->model, this->position, this->scale, this->color);
    }

    BoundingBox Model::getBounds() {
        return this->bounds;
    }

    Color Model::getColor() {
        return this->color;
    }

    Vector3 Model::getPosition() {
        return this->position;
    }

    float Model::getScale() {
        return this->scale;
    }

    Texture2D Model::getTexture() {
        return this->texture;
    }

    float Model::getX() {
        return this->position.x;
    }

    float Model::getY() {
        return this->position.y;
    }

    float Model::getZ() {
        return this->position.z;
    }

    Model* Model::init(std::string modelPath, Vector3 position, float scaLe, Color color) {
        Model* newModel = new Model();
        newModel->model = LoadModel(modelPath.c_str());
        
    }
}