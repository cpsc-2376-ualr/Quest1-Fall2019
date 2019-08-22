#include <iostream>
#include <fstream>
#include <string>

#include "GUI.h"
#include "constants.h"

using namespace std;

GUI::GUI() {

	//Initialize the window
	window = nullptr;

	//Initialize the renderer

	//Start-up the GUI!
	initGUI();
	frame = new Timer();

}

GUI::~GUI() {
	cleanUp();
}

void GUI::startTimer()
{
	frame->start();//start the timer!
}

void GUI::delay()
{
	if (frame->get_ticks() < frameDelay)
	{
		SDL_Delay(frameDelay - frame->get_ticks());
	}
}



void GUI::initGUI() {

	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		exit(1);
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		exit(1);
	}
	normalFont = TTF_OpenFont("./Assets/Fonts/impact.ttf", 48);
	if (normalFont == nullptr) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	//Construct and check window construction
	window = SDL_CreateWindow("CPSC 2376 Quests",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	if (window == NULL) {

		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	//Construct and check renderer construction
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {

		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);

	}

}


void GUI::cleanUp() {

	//Free the window
	SDL_DestroyWindow(window);
	window = NULL;

	//Free the renderer
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	//Free font structures
	TTF_CloseFont(normalFont);

	//Quit SDL Subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

}

void GUI::displayWord(vector2D position, RGB wordColor, std::string textToDisplay) {

	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//Render Command to Text
	SDL_Color textColor = { wordColor.R, wordColor.G, wordColor.B };
	//if(textSheetTexture!= nullptr) delete textSheetTexture;
	SDL_DestroyTexture(textSheetTexture);
	textSheetTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(normalFont, textToDisplay.c_str(), textColor));

	//Set rendering space and render to screen
	SDL_QueryTexture(textSheetTexture, NULL, NULL, &textDimensions.x, &textDimensions.y);
	SDL_Rect renderQuad = {position.x, position.y, textDimensions.x, textDimensions.y};

	//Render to screen
	SDL_RenderCopy(renderer, textSheetTexture, NULL, &renderQuad);
	//-------------------------------------------------------------
	//-------------------------------------------------------------

	//Update the visible screen
	SDL_RenderPresent(renderer);

}

vector2D GUI::getDimensions()
{
	return textDimensions;
	
}
