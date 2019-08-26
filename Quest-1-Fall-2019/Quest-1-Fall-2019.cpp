#include <string>
#include <iostream>

#include "Source/GUI.h"
#include "Source/constants.h"

using namespace std;


int main(int argc, char *argv[]) {
	//Construct GUI
	GUI gui;
	//you will need the following lines somewhere in your code!

	//Use at the beginning of the frame to time how long the frame takes to process.
	gui.startTimer();

	//gets the dimensions of the current word being displayed
	//NOTE:: x is width, y is height!
	gui.getDimensions().x;
	gui.getDimensions().y;

	//displays the word on the scren. Parameters are:
		//vector2D struct which I named wordPosition
		//RGB struct which I named wordColor
		//string which I named wordToDisplay
	vector2D wordPosition{ 0,0 };
	wordPosition.x = 3;
	RGB wordColor;
	wordColor.B = maxColors;
	wordColor.G = maxColors;
	wordColor.R = maxColors;
	wordColor.B -= colorJump;
	wordColor.B = wordColor.B - colorJump;
	gui.displayWord(wordPosition, wordColor, wordToDisplay);

	//Use at the end of a frame to pause for the proper length of time!
	gui.delay();


	return 0;

}

