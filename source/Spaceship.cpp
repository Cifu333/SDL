#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) 
	:GameObject(renderer, 31, 39, Vector2(0,0)) {
	position = pos;
	rotation = rot;
		scale = scl;

		velocity =Vector2();
		 angularVelocity = 0.0f;

		 acceleration = Vector2();
		 angularAcceleration = 0.0f;

		 linearDrag = 1.2 ;
		 angularDrag = 6.0f;

		 accelerationFactor = 500.0f;  //px / sec^
		 angularAccelerationFactor = 180000.0f; //Degs /sec^2

}



void Spaceship::UpdateMovement(float dt) {

	acceleration = Vector2();

	if (IM.GetKey(UP, HOLD) || (IM.GetKey(SDLK_UP, DOWN))) {
		Vector2 dir;

		acceleration = Vector2();

		float rotationInRadians = rotation * (M_PI / 180.f);

		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);

		acceleration = dir * accelerationFactor;
	
	}

	angularAcceleration = 0;
	if (IM.GetKey(SDLK_RIGHT, HOLD) || IM.GetKey(SDLK_RIGHT, HOLD)) {
		angularAcceleration = dt *  angularAccelerationFactor ; //units ºsegundo
	}


	if (IM.GetKey(SDLK_LEFT, HOLD) || IM.GetKey(SDLK_LEFT, HOLD)) {
		angularAcceleration = dt * - angularAccelerationFactor; //units ºsegundo
	}
	GameObject::UpdateMovement(dt);

}



