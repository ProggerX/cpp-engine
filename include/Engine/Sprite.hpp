#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Sprite {
private:
	SDL_Surface* surface;
public:
	Sprite(std::string path) {
		IMG_Init(IMG_INIT_PNG);
		IMG_Init(IMG_INIT_JPG);
		surface = IMG_Load(path.c_str());
	}
	
	SDL_Surface* get_surface() { return surface; }
	void set_image_path(std::string path) { surface = IMG_Load(path.c_str()); }

	void copy_to(SDL_Surface* dst, int x, int y) {
		SDL_Rect dst_rect;
		dst_rect.w = 0;
		dst_rect.h = 0;
		dst_rect.x = x;
		dst_rect.y = y;

		SDL_BlitSurface(surface, NULL, dst, &dst_rect);
	}

	~Sprite() {
		SDL_FreeSurface(surface);
	}
};
