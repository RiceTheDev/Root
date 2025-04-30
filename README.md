
![Banner](https://github.com/RiceTheDev/Root/blob/main/Readme/Banner.gif?raw=true)

# Root Game Engine

A Game Engine focused on "Write once, run anywhere"

## Available Platforms

- Desktop (Windows, Linux and MacOS)
- Wii (Nintendo Wii)
- Web (To be added)

And more to come!

## Usage/Examples

```cpp
#include "core.h"

int main() {
    // This is where we initialize everything
    init_game();

    // Defining the white color (optional)
    Color white = {255, 255, 255};

    // Now, we create a sprite
    Sprite spr;

    // Set the image for the sprite
    spr.load("Player.png");

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
```

More examples [here](https://github.com/RiceTheDev/Root/tree/main/examples/)

## FAQ

#### I got error X, how do I fix it?

If you need help, just send me a message on Discord [@raic.e](https://discord.com/users/570693486500773888) I will try to answer ASAP.

#### Can you add X feature?

Ideas are welcome, if you want a specific feature to be added, just create a issue.

## Installation

For now, I'm working on a installer for the engine

## Documentation

You can access the Documentation [Here](https://root-doc.pages.dev)

## Authors

- [@RiceTheDev](https://www.github.com/RiceTheDev) - Main Developer
