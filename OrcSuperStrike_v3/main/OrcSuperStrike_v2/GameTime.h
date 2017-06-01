#pragma once
#include <Windows.h>

class GameTime
{
public:
	GameTime();
	~GameTime();

	static int GetMilliSeconds();
	static int GetSeconds();
	static int GetMinutes();

	static double GetTimeAnimation(double speed);
};

