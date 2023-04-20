#pragma once
#include <SDL.h>
#include <unordered_map>

enum KeyState{EMPTY, DOWN, UP, HOLD};

#define IM InputManager::Instance()

class InputManager {
public:
	static InputManager& Instance() {
		static InputManager manager;
		return manager;
	}
	InputManager(const InputManager&) = delete;
	InputManager& operator = (const InputManager&) = delete;
	void Listen();
	bool GetKey(Sint32 key, KeyState state) {return keys[key] == state;
		//aceder al diccionario de keys y comprobar que el state es el que pide
	}

	int GetMouseX() { return mouseX; }
	int GetMouseY() { return mouseY; }
	bool GetLeftQuit() { return leftClick; }
	bool Get() { return quit; }


private:
	InputManager() {
		quit = false;
	}

	

	std::unordered_map<Sint32, KeyState> keys;
	int mouseX, mouseY;
	bool leftClick;
	bool quit;
};