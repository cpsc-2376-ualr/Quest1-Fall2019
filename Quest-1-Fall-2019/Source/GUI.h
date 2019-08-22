#ifndef GUI_H
#define GUI_H

#include <string>

//GUI definitions
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Timer.h"

//User-defined tools
#include "constants.h"

using namespace std;

class GUI
{

public:
	GUI();
	~GUI();
	void startTimer();
	void delay();
	void displayWord(vector2D position, RGB wordColors, std::string textToDisplay);
	vector2D getDimensions();
private:
	const int FPS{ 30 };
	const int frameDelay{ 1000 / FPS };
	//
	// PRIVATE METHODS
	//
	void initGUI();
	void cleanUp();

	//
	//PRIVATE MEMBERS
	//
	//Window(s) to display graphics
	SDL_Window* window{ nullptr };

	//Hardware accelerated renderer
	SDL_Renderer* renderer{ nullptr };

	//The texture to be used for the text
	TTF_Font* normalFont{ nullptr };

	SDL_Texture* textSheetTexture{ nullptr };
	vector2D textDimensions;
	Timer* frame;

};

#endif
