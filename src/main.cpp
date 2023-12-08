#include <Engine.hpp>

int main() {
	Screen scr("pon", 800, 800);
	Sprite sprite("sample.png");
	sprite.copy_to(scr.get_surface(), 0, 0);
	sprite.copy_to(scr.get_surface(), 100, 100);
	while (true) {
		scr.update();
		SDL_Event e;
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			break;
		}
	}

	return 0;
}

int WinMain() {
	main();
	return 0;
}
