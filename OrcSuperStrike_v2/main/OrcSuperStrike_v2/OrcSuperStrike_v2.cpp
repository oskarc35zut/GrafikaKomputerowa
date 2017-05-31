/*REM*	#include "BulletOpenGLApplication.h" **/
/*ADD*/	#include "BasicPhysics.h"
#include "FreeGLUTCallbacks.h"

int main(int argc, char** argv)
{	
	BasicPhysics game;
	return glutmain(argc, argv, 1024, 768, "OrcSuperStrike", &game);
}
