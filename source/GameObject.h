#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include "Utils.h"
#include<iostream>

class GameObject {
public:
	GameObject(SDL_Renderer* renderer, int w, int h, Vector2 pad);
	~GameObject();

	virtual void Update(float dt);
	virtual void Render(SDL_Renderer* renderer);

	virtual void Destroy(){ pendingDestroy = true; };
	bool IsPendingDestroy(){ return pendingDestroy; };

	Vector2 GetPosition() { return position; }
protected:

	bool pendingDestroy = false;

	void ClampPosition();
	virtual void UpdateMovement(float dt);

	Vector2 velocity;
	float angularVelocity;

	Vector2 acceleration;
	float angularAcceleration;

	float linearDrag;
	float angularDrag;

	float accelerationFactor;
	float angularAccelerationFactor;

	Vector2 position;
	float rotation;
	Vector2 scale;

	SDL_Texture* texture;
	int width, heigth;
	Vector2 paddin;

};


