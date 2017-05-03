#include "stdafx.h"
#include "BasicPhysics.h"
#include "FreeGlutCallsBack.h"


int main(int argc, char* argv[])
{
	//GameDisplay* gra = new GameDisplay();
	BasicPhysics* gra = new BasicPhysics();

	return glutmain(argc, argv, 1024, 768, "OrcSuperStrike", gra);
}