#include "GameEngine.h"

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

	bool quitGame = false;
	while (!quitGame) {
		//Update input
		SDL_Event  e;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quitGame = true;
			}
		}

		//Update Logic
		object.Update(0.f);

		//Render
		SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 0xFF );//color de fondo

		SDL_RenderClear(renderer);
		object.Render(renderer);
		//render objects
		//SDL_RenderCopyEx(...)
		SDL_RenderPresent(renderer);

	}
}

void GameEngine::Finish() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}