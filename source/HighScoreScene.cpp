#include "HighScoreScene.h"
#include "InputManager.h"

void HighScoreScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);
}

void HighScoreScene::Update(float dt) {
	Scene::Update(dt);
	if (IM.GetKey(SDLK_SPACE, DOWN)) {//transicion code
		finished = true;
		targetScene = "Main Menu";
	}
}

void HighScoreScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);
	std::cout << "hs" << std::endl;
}

void HighScoreScene::Exit() {

}