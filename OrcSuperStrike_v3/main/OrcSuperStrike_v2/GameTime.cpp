#include "StdAfx.h"
#include "GameTime.h"


GameTime::GameTime()
{
}


GameTime::~GameTime()
{
}

int GameTime::GetMilliSeconds()
{
	SYSTEMTIME systemtime;
	GetSystemTime(&systemtime);

	return systemtime.wMilliseconds;
}

int GameTime::GetSeconds()
{
	SYSTEMTIME systemtime;
	GetSystemTime(&systemtime);

	return systemtime.wSecond;
}

int GameTime::GetMinutes()
{
	SYSTEMTIME systemtime;
	GetSystemTime(&systemtime);

	return systemtime.wMinute;
}

double GameTime::GetTimeAnimation(double speed)
{
	SYSTEMTIME systemtime;
	GetSystemTime(&systemtime);

	return ((double)systemtime.wSecond + (double)systemtime.wMilliseconds/1000) * speed;
}
