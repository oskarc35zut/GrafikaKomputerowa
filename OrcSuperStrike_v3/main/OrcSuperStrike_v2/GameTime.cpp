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

double GameTime::GetTimeAnimation(int speed)
{
	SYSTEMTIME systemtime;
	GetSystemTime(&systemtime);

	////printf("%.f", systemtime.wSecond % 360);

	//int a = (1000 * systemtime.wSecond + (double)systemtime.wMilliseconds)* speed * 6;
	//double b = ((double)(a % (360*1000)))/1000;


	//	//double ScondsLimiter = systemtime.wSecond % 360;
	//if (systemtime.wSecond > 58 || systemtime.wSecond <2)
	//{
	//	printf("%f   %d   %d    %d\n", b, a, systemtime.wSecond, systemtime.wMilliseconds);
	//}


	return ((double)(((int)(1000 * systemtime.wSecond + (double)systemtime.wMilliseconds)* speed * 6) % (360 * 1000)))/1000;
}
