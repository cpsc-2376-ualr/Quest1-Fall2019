#include <string>
#include <iostream>

#include "GUI.h"
#include "constants.h"

using namespace std;

int main(int argc, char *argv[]){
	//Construct GUI
	GUI gui;

	string wordToDisplay;
	//Keep looping until "quit" entered!
	while (wordToDisplay != "quit")
	{
		cout << "What word do you want to display: ";
		cin >> wordToDisplay;

		RGB wordColor;
		vector2D wordPosition{ 0,0 };
		vector2D direction{ 2,1 };
		int currentFrame{ 0 };

		if (wordToDisplay != "quit")
		{
			for (int red = maxColors; red > 0; red-= colorJump)
			{
				for (int green = maxColors; green > 0; green -= colorJump)
				{					
					for (int blue = maxColors; blue > 0; blue -= colorJump)
					{
						gui.startTimer();
						
						wordColor.R = red;
						wordColor.G = green;
						wordColor.B = blue;

						
						gui.displayWord(wordPosition, wordColor, wordToDisplay);
						wordPosition.x += direction.x;
						wordPosition.y += direction.y;
						

						if (wordPosition.x < 0)
						{
							direction.x *= -1;
							wordPosition.x = 0;
						}
						if (wordPosition.x + gui.getDimensions().x > screenWidth)
						{
							direction.x *= -1;
							wordPosition.x = screenWidth - gui.getDimensions().x;
						}

						if (wordPosition.y < 0)
						{
							direction.y *= -1;
							wordPosition.y = 0;
						}
						if (wordPosition.y + gui.getDimensions().y > screenHeight)
						{
							direction.y *= -1;
							wordPosition.y = screenHeight- gui.getDimensions().y;
						}

						gui.delay();
					}
				}
			}
		}
	}

	return 0;

}