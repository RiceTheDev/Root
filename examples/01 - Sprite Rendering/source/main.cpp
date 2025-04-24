#include "core.h"

int main() {
    // This is where we initialize everything
    init_game();

    // Defining the white color (optional)
    Color white = {255, 255, 255};

    // Now, we create a sprite
    Sprite spr;

    // Set the image for the sprite
    spr.path = "Player.png";

    // And lastly the position (optional)
    spr.posX = 50;
    spr.posY = 50;

    while (true) 
    {
        // Self explanatory...
        clear_background(white);

        // When calling draw_sprite, you need to set the sprite and the tint
        draw_sprite(spr, white);

        // Render everything
        render();
    }

    // And last but not least, end_render() for cleaning everything after the user close the game
    end_render();
}
