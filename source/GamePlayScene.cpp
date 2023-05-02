#include "GamePlayScene.h"

void GamePlayScene::Start(SDL_Renderer* rend) {
	Scene::Start(rend);
	spaceship= new Spaceship(rend, Vector2(100.f, 100.f), 0.f, Vector2(1.f, 1.f));
	objects.push_back(spaceship);
	for (int i = 0; i < 10; i++) {
		objects.push_back(new Asteroid(rend));
	}
}

void GamePlayScene::Update(float dt) {
	Scene::Update(dt);

	for (auto it = objects.begin(); it != objects.end(); it++) {
		if (Asteroid* a = dynamic_cast <Asteroid*>(*it)) {
			Vector2 SToA = a->GetPosition() - spaceship->GetPosition();
			float distanceSquared = SToA.x * SToA.x + SToA.y * SToA.y;
			float squaredRadiusSum = 20 + 20;
			squaredRadiusSum *= squaredRadiusSum;
			if (distanceSquared < squaredRadiusSum) {
				spaceship->Destroy();
				a->Destroy();
			}
		}
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