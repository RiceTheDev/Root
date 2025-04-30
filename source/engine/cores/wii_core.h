#include "/opt/devkitpro/portlibs/wii/include/grrlib.h"
#include "/opt/devkitpro/libogc/include/wiiuse/wpad.h"
#include "images.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

// From Raylib
typedef struct Color {
    unsigned char r;        // Color red value
    unsigned char g;        // Color green value
    unsigned char b;        // Color blue value
    unsigned char a = 255;  // Color alpha value
} Color;

struct Sprite {
    std::string path;
    GRRLIB_texImg *texture;
    int posX;
    int posY;
    void load(const std::string& filename){
        path = filename;
        std::transform(path.begin(), path.end(), path.begin(), [](char c) { 
            return (c == '.') ? '_' : c;
        });

        auto it = std::find_if(images.begin(), images.end(), [&](const auto& pair) {
            return pair.first == path;
        });
        
        if (it != images.end()) {
            texture = GRRLIB_LoadTexture(it->second);
        } else {
            std::cerr << "ERROR: " << path << "was not found in the images, check the logs.\n";
        }
    }
};

void init_game() {
    GRRLIB_Init();
    WPAD_Init();
}

void render() {
    GRRLIB_Render();
    WPAD_ScanPads();
    if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {GRRLIB_Exit(); exit(1);};
}

bool is_down(int controller, int key) {
    if (WPAD_ButtonsHeld(controller) & key) {
        return true;
    } else {
        return false;
    }
}

bool is_down(int controller, int key) {
    if (WPAD_ButtonsDown(controller) & key) {
        return true;
    } else {
        return false;
    }
}

void clear_background(Color color) {
    uint32_t converted_color = (color.a << 24) | (color.r << 16) | (color.g << 8) | color.b;
    GRRLIB_FillScreen(converted_color);
}

void draw_sprite(Sprite sprite, Color color = {255, 255, 255, 255}) {
    uint32_t converted_color = (color.r << 24) | (color.g << 16) | (color.b << 8) | color.a;
    GRRLIB_DrawImg(sprite.posX, sprite.posY, sprite.texture, 0, 1, 1, converted_color);
}

void end_render() {
    // TODO: Unload textures 
    GRRLIB_Exit();
    exit(0);
}