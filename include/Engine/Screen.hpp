#include <SDL2/SDL.h>
#include <string>

class Screen {
private:
	SDL_Window* window;
	SDL_Surface* surface;

public:
	Screen(std::string title, int width, int height) {
		SDL_Init(SDL_INIT_VIDEO);
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
		surface = SDL_GetWindowSurface(window);
	}

	void update() {
		SDL_UpdateWindowSurface(window);
	}

	SDL_Window* get_window() { return window; }
	SDL_Surface* get_surface() { return surface; }

	~Screen() {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
};

