/*REM*	#include "BulletOpenGLApplication.h" **/
/*ADD*/	#include "BasicPhysics.h"
#include "FreeGLUTCallbacks.h"

int main(int argc, char** argv)
{
	/*REM*	BulletOpenGLApplication demo; **/
	/*ADD*/		BasicPhysics demo;
	return glutmain(argc, argv, 1024, 768, "Introduction to Game Physics with Bullet Physics and OpenGL", &demo);
}
