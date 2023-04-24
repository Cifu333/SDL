#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) 
	:GameObject(renderer) {
	position = pos;
	rotation = rot;
		scale = scl;
}

void Spaceship::Update(float dt) {
	UpdateMovemeent(dt);

}

void Spaceship::UpdateMovemeent(float dt) {


	if (IM.GetKey(UP, HOLD) || (IM.GetKey(SDLK_UP, DOWN))) {
		Vector2 dir;

		float rotationInRadians = rotation * (M_PI / 180.f);

		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);

		velocity = velocity + (dir * dt * 100.f);
	
	}


	if (IM.GetKey(SDLK_RIGHT, HOLD) || (IM.GetKey(SDLK_RIGHT, HOLD))) {
		rotation += dt * 180; //units ºsegundo
	}


	if (IM.GetKey(SDLK_LEFT, HOLD) || (IM.GetKey(SDLK_LEFT, HOLD))) {
		rotation -= dt * 180; //units ºsegundo
	}

	Vector2 velocityDT = velocity * dt;
	position = position + velocityDT;
}

void Spaceship::Render(SDL_Renderer* rend){

	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = 31;
	source.h = 39;

	SDL_Rect dest;
	dest.x = position.x - (int)((float)source.w *scale.x / 2.0f);
	dest.y = position.y - (int)((float)source.h * scale.x / 2.0f);
	dest.w = (float)source.w * scale.x;
	dest.h = (float)source.h * scale.y;

	SDL_RenderCopyEx(rend , texture,
		&source, &dest,
		rotation + 90, NULL, //Punto de rotacion NULL = centrado)
		SDL_FLIP_NONE);// No hacemos fila
}
