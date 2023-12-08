build:
	g++ -oout ./src/* -I./include -lSDL2 -lSDL2_image

build-windows:
	x86_64-w64-mingw32-g++ ./src/* -oout.exe -I./include -I./mingw/include -L./mingw/lib -lSDL2 -lSDL2_image
