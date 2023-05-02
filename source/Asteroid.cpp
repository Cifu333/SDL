#include "Asteroid.h"

Asteroid::Asteroid(SDL_Renderer* rend) 
	: GameObject(rend, 40, 40, Vector2(40, 0)) {
	float objectRadius = width > heigth ? width / 2 : heigth / 2;

	float radius = CalculateRadius(width + objectRadius + 2.0f, heigth + objectRadius + 2.0f);
	
	Vector2 permimeterPosition = CalculatePositionInRadius(radius);


	float halfHeight = (float)GAME_HEIGTH / 2.f + (float)objectRadius;
	float halfWidth = (float)GAME_WIDTH / 2.f + (float)objectRadius;

	permimeterPosition = ClampPositionToRectangle(permimeterPosition, halfWidth, halfHeight);

	position = permimeterPosition;
	position = position + Vector2(halfWidth, halfHeight);
	rotation = rand() % 360;
	scale = Vector2(1.0, 1.0f);

	acceleration = Vector2(0.0f, 0.0f);
	angularAcceleration = 0.0f;

	velocity = CalculatePositionInRadius(100);
	angularVelocity = 100 - (rand() % 201);

}