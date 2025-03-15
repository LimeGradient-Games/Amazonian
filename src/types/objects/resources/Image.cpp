#include "types/objects/resources/Image.hpp"
#include <raylib.h>
#include <string>

namespace Amazonian {
    void Image::draw() {
        DrawTexture(this->texture, this->position.x, this->position.y, this->color);
    }

    Color Image::getColor() {
        return this->color;
    }

    float Image::getHeight() {
        return this->size.y;
    }
    
    Vector2 Image::getPosition() {
        return this->position;
    }

    Vector2 Image::getSize() {
        return this->size;
    }

    Texture2D Image::getTexture() {
        return this->texture;
    }

    float Image::getWidth() {
        return this->size.x;
    }

    float Image::getX() {
        return this->position.x;
    }

    float Image::getY() {
        return this->position.y;
    }

    Image* Image::init(std::string resourcePath, Vector2 size, Vector2 position, Color color) {
        Amazonian::Image* newImage = new Amazonian::Image();
        
        ::Image image = LoadImage(resourcePath.c_str());
        newImage->texture = LoadTextureFromImage(image);
        UnloadImage(image);

        newImage->size = size;
        newImage->position = position;
        newImage->color = color;
        return newImage;
    }

    Image* Image::init(std::string resourcePath, float width, float height, Vector2 position, Color color) {
        return Image::init(resourcePath, Vector2{width, height}, position, color);
    }

    Image* Image::init(std::string resourcePath, Vector2 size, float x, float y, Color color) {
        return Image::init(resourcePath, size, Vector2{x, y}, color);
    }

    Image* Image::init(std::string resourcePath, float width, float height, float x, float y, Color color) {
        return Image::init(resourcePath, Vector2{width, height}, Vector2{x, y}, color);
    }

    Image* Image::init(char* resourcePath, Vector2 size, Vector2 position, Color color) {
        return Image::init(std::string(resourcePath), size, position, color);
    }

    Image* Image::init(char* resourcePath, float width, float height, Vector2 position, Color color) {
        return Image::init(resourcePath, Vector2{width, height}, position, color);
    }

    Image* Image::init(char* resourcePath, Vector2 size, float x, float y, Color color) {
        return Image::init(resourcePath, size, Vector2{x, y}, color);
    }

    Image* Image::init(char* resourcePath, float width, float height, float x, float y, Color color) {
        return Image::init(resourcePath, Vector2{width, height}, Vector2{x, y}, color);
    }

    void Image::setColor(Color color) {
        this->color = color;
    }

    void Image::setHeight(float height) {
        this->size.y = height;
    }

    void Image::setPosition(Vector2 position) {
        this->position = position;
    }

    void Image::setPosition(float x, float y) {
        this->position = Vector2{x, y};
    }

    void Image::setSize(Vector2 size) {
        this->size = size;
    }

    void Image::setSize(float width, float height) {
        this->position = Vector2{width, height};
    }

    void Image::setTexture(Texture2D texture) {
        this->texture = texture;
    }

    void Image::setWidth(float width) {
        this->size.x = width;
    }
}