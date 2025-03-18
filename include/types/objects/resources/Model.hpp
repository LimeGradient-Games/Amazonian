#pragma once

#include <string>
#include <raylib.h>
#include <types/objects/CoreObject.hpp>

namespace Amazonian {
    class Model : public CoreObject {
    public:
        void draw();

        BoundingBox getBounds();
        Color getColor();
        Vector3 getPosition();
        float getScale();
        Texture2D getTexture();
        float getX();
        float getY();
        float getZ();

        static Model* init(std::string modelPath, Vector3 position, float scale, Color color);
        static Model* init(std::string modelPath, float x, float y, float z, float scale, Color color);
        static Model* init(char* modelPath, Vector3 position, float scaLe, Color color);
        static Model* init(char* modelPath, float x, float y, float z, float scale, Color color);

        void setColor(Color color);
        void setPosition(Vector3 position);
        void setPosition(float x, float y, float z);
        void setScale(float scale);
        void setTexture(Texture2D texture);
        void setX(float x);
        void setY(float y);
        void setZ(float z);

    protected:
        Color color;
        ::Model model;
        Texture2D texture;
        BoundingBox bounds;
        Vector3 position;
        float scale;
    };
}