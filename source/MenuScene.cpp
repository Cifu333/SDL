#include "MenuScene.h"
#include "InputManager.h"

void MenuScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);
}

void MenuScene::Update(float dt) {
	Scene::Update(dt);
	if (IM.GetKey(SDLK_SPACE, DOWN)) {//transicion code
		finished = true;
		targetScene = "Gameplay";
		std::cout << "------SPACE PRESED------" <<std::endl;
	}
	if (IM.GetKey(SDLK_h, DOWN)) {//transicion code
		finished = true;
		targetScene = "Highscores";
		std::cout << "------SPACE PRESED------" << std::endl;
	}
}

void MenuScene::Render(SDL_Renderer* rend) {
	Scene::Render(rend);;//paramos funcion
	std::cout << "Main Menu" << std::endl;
}

void MenuScene::Exit() {

}