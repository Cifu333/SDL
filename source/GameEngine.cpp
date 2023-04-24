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


	//------- TIME Control
	float dt = 0.0f;
	float lastTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();

	// delta time control

	
	const float FPS = 60;
	const float frameTime = 1.0 / (float)FPS;

	//Scenes
	std::unordered_map<std::string, Scene*> gameScenes;

	gameScenes["Main Menu"] = new MenuScene();
	gameScenes["Gameplay"] = new GamePlayScene();
	gameScenes["Highscores"] = new HighScoreScene();

	Scene* currentScene =  gameScenes["Gameplay"];
	currentScene->Start(renderer);

	while (!IM.GetLeftQuit()) {


		float currenTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
		dt += currenTime - lastTime;
		lastTime = currenTime;

		if (dt > frameTime) {


			//Update input
			IM.Listen();

			//Update Logic
			currentScene->Update(dt);

			

			//Render
			SDL_RenderClear(renderer);
			currentScene->Render(renderer);//render objects
			SDL_RenderPresent(renderer);//SDL_RenderCopyEx(...)

			//scene transition
			if (currentScene->isFinished()) {
				currentScene->Exit();
				currentScene = gameScenes[currentScene->GetTargetScene()];
				currentScene->Start(renderer);
			}

			dt -= frameTime;
		}
	}
	currentScene->Exit();

	for (auto it = gameScenes.begin(); it != gameScenes.end(); it++ ) {
		delete it->second;
	}
}

void GameEngine::Finish() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);


}