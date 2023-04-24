#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject {
public:
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl);

	void Update(float dt)override;
	void Render(SDL_Renderer* rend)override;

private:

	void UpdateMovemeent(float dt);

	Vector2 velocity;
	float angularVelocity;

	float linearDrag;
	float angularDrag;

	float accelerationFactor;
	float angularAccelerationFactor;
};