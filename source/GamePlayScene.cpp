#include "GamePlayScene.h"

void GamePlayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);
	objects.push_back(new GameObject(rend));
}

void GamePlayScene::Update(float dt) {
	Scene::Update(dt);
	if (IM.GetKey(SDLK_SPACE, DOWN)) {//transicion code
		finished = true;
		targetScene = "Main Menu";
	}
}

void GamePlayScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);
	std::cout << "gameplay" << std::endl;
}

void GamePlayScene::Exit() {
	for (auto it = objects.begin(); it != objects.end(); it++)
		delete(*it);

	objects.clear();
}