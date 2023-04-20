#pragma once


#include "Scene.h"
#include "InputManager.h"

class GamePlayScene : public Scene {

public:
	GamePlayScene()
		: Scene() {}
	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;
};
