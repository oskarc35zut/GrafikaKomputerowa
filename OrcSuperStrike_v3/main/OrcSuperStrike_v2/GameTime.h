#pragma once
#include <Windows.h>
#include <math.h>

class GameTime
{
public:
	GameTime();
	~GameTime();

	static int GetMilliSeconds();
	static int GetSeconds();
	static int GetMinutes();

	static double GetTimeAnimation(int speed);
};

