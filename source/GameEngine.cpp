#include "GameEngine.h"
#include "InputManager.h"

GameEngine::GameEngine(int windowWidth, int WindowHeigth) {
	InitSDL();
	InitWindowAndRenderer(windowWidth, WindowHeigth);
}

void GameEngine::InitSDL() {
	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result < 0) {
		std::cout << " SDL_INIT Error: " << SDL_GetError();
	}
}

void GameEngine::InitWindowAndRenderer(int windowWidth, int WindowHeigth) {
	window = SDL_CreateWindow("Vaporeon",
		SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED,//posicion de la ventana
		windowWidth,WindowHeigth,//tamaño de la ventana en X Y
		SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "Error creating window: " << SDL_GetError();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (window == nullptr) {
		std::cout << "Error creating window: " << SDL_GetError();
	}
}

void GameEngine::Update() {

	GameObject object(renderer);
	float dt = 0.0f;
	float lastTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();

	const float FPS = 60;
	const float frameTime = 1.0 / (float)FPS;


	while (!IM.GetLeftQuit()) {


		float currenTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
		dt += currenTime - lastTime;
		lastTime = currenTime;

		if (dt > frameTime) {


			//Update input
			IM.Listen();

			//Update Logic
			object.Update(dt);
			std::cout << dt << std::endl;

			//Render

			if (IM.GetKey(SDLK_SPACE, DOWN)) {
				SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 0xFF);//color de fondo
			}



			SDL_RenderClear(renderer);
			object.Render(renderer);//render objects
			SDL_RenderPresent(renderer);//SDL_RenderCopyEx(...)

			dt -= frameTime;
		}
	}
}

void GameEngine::Finish() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}