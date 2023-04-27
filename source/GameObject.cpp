#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer, int w, int h, Vector2 pad)
	: width(w), heigth(h)
	{
	position = Vector2();
	rotation = 0;
	scale = Vector2(1.f, 1.f);

	//cargar texturas
	SDL_Surface* surf = IMG_Load("resources/asteroids.png");
	if (surf == nullptr) {
		std::cout << "Cannot load surfaces:" << SDL_GetError();
	}
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr) {
		std::cout << "Cannot load texture:" << SDL_GetError();
	}

	SDL_FreeSurface(surf);

	
}

GameObject::~GameObject() {
	SDL_DestroyTexture(texture);
}

void GameObject::Render(SDL_Renderer* rend) {

	SDL_Rect source;
	source.x = paddin.x;
	source.y = paddin.y;
	source.w = width;
	source.h = heigth;

	SDL_Rect dest;
	dest.x = position.x - (int)((float)source.w * scale.x / 2.0f);
	dest.y = position.y - (int)((float)source.h * scale.x / 2.0f);
	dest.w = (float)source.w * scale.x;
	dest.h = (float)source.h * scale.y;

	SDL_RenderCopyEx(rend, texture,
		&source, &dest,
		rotation + 90, NULL, //Punto de rotacion NULL = centrado)
		SDL_FLIP_NONE);// No hacemos fila
}


void GameObject::Update(float dt) {
	UpdateMovement(dt);
	ClampPosition();
}

void GameObject::ClampPosition() {

	float scaleWidth = (float)width * scale.x;
	float scaleHeigth = (float)heigth * scale.y;

	int biggestAxis = scaleWidth > scaleHeigth ? scaleWidth : scaleHeigth;

	if (position.x > GAME_WIDTH + biggestAxis)
		position.x -= (GAME_WIDTH + biggestAxis * 2);

	if (position.x < 0.0f - biggestAxis)
		position.x += (GAME_WIDTH + biggestAxis * 2);

	if (position.y > GAME_HEIGTH + biggestAxis)
		position.y -= (GAME_HEIGTH + biggestAxis * 2);

	if (position.y < 0.0f - biggestAxis)
		position.y += (GAME_HEIGTH + biggestAxis);

}

void GameObject::UpdateMovement(float dt) {
	// Update velocity y angular velocity

	velocity = velocity + acceleration * dt;
	angularVelocity = angularAcceleration + angularAcceleration * dt;

	// DRAG
	velocity = velocity * (1.0f - linearDrag * dt);
	angularVelocity = angularVelocity * (1.0f - angularDrag * dt);

	// posicion = posicion +velocidad *tiempo
	position = position + velocity * dt;

	//rotacion = roracion + angularrotation * tiempo
	rotation = rotation + angularVelocity * dt;
}
