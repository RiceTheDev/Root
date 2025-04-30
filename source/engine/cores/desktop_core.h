#include "raylib.h"
#include <string>

struct Sprite {
    std::string path;
    Texture texture;
    void load(const char* filename) {
        path = filename;
        std::string images = std::string("data/images/") + filename;
        Image img = LoadImage(images.c_str());
        texture = LoadTextureFromImage(img);
    }
    int posX;
    int posY;
};

void init_game() {
    InitWindow(800, 600, "Root Game Project");
    SetTargetFPS(60);
    BeginDrawing();
}

void render() {
    EndDrawing();
}

void clear_background(Color color) {
    ClearBackground(color);
}

bool is_held(int controller, int key) {
    if (IsKeyPressed(key)) {
        return true;
    } else {
        return false;
    }
}

bool is_down(int controller, int key) {
    if (IsKeyDown(key)) {
        return true;
    } else {
        return false;
    }
}

void end_render() {
    // TODO: Unload textures 
    exit(0);
}

void draw_sprite(Sprite sprite, Color tint = WHITE) {
    DrawTexture(sprite.texture, sprite.posX, sprite.posY, tint);
}