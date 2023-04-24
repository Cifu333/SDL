#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include<iostream>

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);

	~GameObject();

	virtual void Update(float dt) = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;

protected:
	Vector2 position;
	float rotation;
	Vector2 scale;

	SDL_Texture* texture;

};


