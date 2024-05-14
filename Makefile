all:
	g++ -Iinclude -Iinclude/SDL2 -Iinclude/headers -Llib -o Main src/*.cpp src/*.h -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf