#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_join.h"

#include "SDL.h"

// Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char *argv[]) {
    std::vector <std::string> strs{"Hello", "World!"};
    std::cout << absl::StrJoin(strs, " ") << std::endl;

    SDL_Window *window = NULL;

    SDL_Surface *screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface white
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    SDL_UpdateWindowSurface(window);

    // Wait two seconds
    SDL_Delay(2000);

    std::cout << "Loading..." << std::endl;

    SDL_Surface *helloWorldImg = SDL_LoadBMP("/Users/chris/Desktop/test.bmp");
    if (helloWorldImg == nullptr) {
        std::cerr << "Failed to load bmp: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_BlitSurface(helloWorldImg, NULL, screenSurface, NULL);

    // Update the surface
    SDL_UpdateWindowSurface(window);

    // Wait two seconds
    SDL_Delay(2000);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}