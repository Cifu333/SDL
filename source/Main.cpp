#include "GameEngine.h"
#include <stdlib.h>
#include "Utils.h"

int SDL_main(int argc, char* argv[]) {
	srand(time(NULL));

	GameEngine engine(GAME_WIDTH, GAME_HEIGTH);
	engine.Update();
	engine.Finish();


	return 0;
}