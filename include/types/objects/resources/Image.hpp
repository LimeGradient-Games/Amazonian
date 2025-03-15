#pragma once

#include <string>

#include <raylib.h>
#include <types/objects/CoreObject.hpp>

namespace Amazonian {
    class Image : public CoreObject {
    public:
        Image() {}

        void draw();

        Color getColor();
        float getHeight();
        Vector2 getPosition();
        Vector2 getSize();
        Texture2D getTexture();
        float getWidth();
        float getX();
        float getY();

        static Image* init(std::string resourcePath, Vector2 size, Vector2 position, Color color);
        static Image* init(std::string resourcePath, float width, float height, Vector2 position, Color color);
        static Image* init(std::string resourcePath, Vector2 size, float x, float y, Color color);
        static Image* init(std::string resourcePath, float width, float height, float x, float y, Color color);
        static Image* init(char* resourcePath, Vector2 size, Vector2 position, Color color);
        static Image* init(char* resourcePath, float width, float height, Vector2 position, Color color);
        static Image* init(char* resourcePath, Vector2 size, float x, float y, Color color);
        static Image* init(char* resourcePath, float width, float height, float x, float y, Color color);

        void setColor(Color color);
        void setHeight(float height);
        void setPosition(Vector2 position);
        void setPosition(float x, float y);
        void setSize(Vector2 size);
        void setSize(float width, float height);
        void setTexture(Texture2D texture);
        void setWidth(float width);

    protected:
        Vector2 size;
        Vector2 position;
        Texture2D texture;
        Color color;
    };
}