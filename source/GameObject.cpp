#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer) {
	position = Vector2();
	rotation = 0;
	scale = Vector2(1.f, 1.f);

	//cargar texturas
	SDL_Surface* surf = IMG_Load("resources/911.png");
	if (surf == nullptr) {
		std::cout << "Cannot load surfaces:" << SDL_GetError();
	}
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr) {
		std::cout << "Cannot load texture:" << SDL_GetError();
	}

	SDL_FreeSurface(surf);
}

void GameObject::Update(float dt) {

}

void GameObject::Render(SDL_Renderer* renderer) {

	SDL_Rect source{ 0,0,637/2,475/2 };

	SDL_Rect destination{100,100,100,100};//x-y-w-h

	SDL_RenderCopy(renderer, texture, &source, &destination);

}
