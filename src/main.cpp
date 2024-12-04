#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "sdl.hpp"
#define USE_SDL
#include "key.hpp"

int main() {
    init_window(800, 600, "krypto mine", 60);

    // Create player object with row offset (e.g., starting at row 4)
    Obj_ss player("assets/Miner_AllAnimations_SpriteSheet.png", 100, 100, 5.0f, 16, 16, 12, 0.2f, 4);

    while (!window_should_close()) {
        // Check for key presses
        if(key_down(UnifiedKey::Right)) {
            player.update_animation_ss("assets/Miner_AllAnimations_SpriteSheet.png", 5.0f, 16, 16, 6, 0.2f,0);
            player.x++;
        }        if (key_down(UnifiedKey::Left)) {
                        player.update_animation_ss("assets/Miner_AllAnimations_SpriteSheet.png", 5.0f, 16, 16, 6, 0.2f,0);
            player.x--;
        }
        
        float delta_time = 1.0f / 60.0f; // Simulate frame time

        // Render frame
        start_drawing();
        clear_screen(COLOR_SKY_BLUE);
        player.render(delta_time);
        stop_drawing();
    }

    quit_window();
    return 0;
}

// changes
// update_animation_ss()