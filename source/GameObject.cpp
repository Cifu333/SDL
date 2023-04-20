#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer) {
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

void GameObject::Update(float dt) {

}

void GameObject::Render(SDL_Renderer* renderer) {

	position = Vector2(100.0f, 100.0f);
	rotation += 1.0f;


	SDL_Rect source{ 0,0,31,39 };

	SDL_Rect destination{
		position.x - (source.w * scale.x) /2,
		position.y - (source.h * scale.y) /2,
		(source.w * scale.x),
		(source.h * scale.y) };//x-y-w-h

	

	SDL_RenderCopyEx(renderer, texture, &source, &destination, rotation, NULL, SDL_FLIP_NONE);

}
