#pragma once
#include<SDL.h>
#include<iostream>
#include<stdlib.h>

#include<stdlib.h>
#include<time.h>
#include"GameObject.h"
#include"InputManager.h"
#include"MenuScene.h"
#include "GamePlayScene.h"
#include "HighScoreScene.h"


class GameEngine {
public:
	GameEngine(int windowWidth, int WindowHeigth);
	void Update();
	void Finish();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;


	void InitSDL();
	void InitWindowAndRenderer(int windowWidth, int WindowHeigth);
};