#include "BasicDemo.h"
#include "FreeGLUTCallbacks.h"

int main(int argc, char** argv)
{
	BasicDemo demo;
	return glutmain(argc, argv, 1024, 768, "OrcSuperStrike", &demo);
}