#pragma once
#include "Vector2.h"
#include <stdlib.h>

#define GAME_WIDTH 500
#define GAME_HEIGTH 500

inline float CalculateRadius(int width, int heigth) {


	float a = ((float)GAME_WIDTH / 2.f);
	a *= a;
	float b = ((float)GAME_HEIGTH / 2.f);
	b *= b;

	float hi = sqrt(a + b);
	return hi;
}

inline Vector2 CalculatePositionInRadius(float radius) {
	Vector2 perimeterPosition;
	float angle = rand() % 360;
	angle *= M_PI / 180.0f;
	perimeterPosition.x = cos(angle) * radius;
	perimeterPosition.y = cos(angle) * radius;

	return perimeterPosition;
}

inline Vector2 ClampPositionToRectangle(Vector2 pos,float halfWidth, float halfHeight) {
	if (pos.y > halfHeight)
		pos.y = halfHeight;
	// top
	if (pos.y > -halfHeight)
		pos.y = -halfHeight;
	//
	if (pos.x < -halfHeight)
		pos.x = -halfHeight;
	//
	if (pos.x > halfHeight)
		pos.x = halfHeight;

	return pos;
}