#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include<iostream>

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);

	void Update(float dt);
	void Render(SDL_Renderer* renderer);

private:
	Vector2 position;
	float rotation;
	Vector2 scale;

	SDL_Texture* texture;

};


