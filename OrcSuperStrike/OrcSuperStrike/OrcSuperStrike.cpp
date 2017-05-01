#include "stdafx.h"
#include "glutmain.h"


int main(int argc, char* argv[])
{
	GameDisplay* gra = new GameDisplay();
	
	return glutmain(argc, argv, 1024, 768, "Introduction to Game Physics with Bullet Physics and OpenGL", gra);
}