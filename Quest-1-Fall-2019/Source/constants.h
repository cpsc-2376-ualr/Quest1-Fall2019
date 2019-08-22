#ifndef CONSTANTS_H
#define CONSTANTS_H
const int maxColors{ 255 };
const int colorJump{ 10 };

//GUI Constants
const int screenWidth{ 20 * 30 };
const int screenHeight{ int(floor((float(2) / 3)*screenWidth)) };

//structs
struct vector2D
{
	int x;
	int y;
};
struct RGB
{
	int R{ 0 };
	int G{ 0 };
	int B{ 0 };
};





#endif