#pragma once


#include "Scene.h"
#include "InputManager.h"

class HighScoreScene : public Scene {

public:
	HighScoreScene()
		: Scene() {}
	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;
};
