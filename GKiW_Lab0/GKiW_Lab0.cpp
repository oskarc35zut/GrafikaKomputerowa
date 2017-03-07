#include "stdafx.h"

void OnRender();

int main(int argc, char * argv[])
{
#pragma region glutInit
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // aktywowanie podwojengo buforowanai i RGBA
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
#pragma endregion


	glutCreateWindow("GKiW");

	glutFullScreen();

	glutDisplayFunc(OnRender);
	glutMainLoop();

	return 0;
}

void OnRender() {
	glClear(GL_COLOR_BUFFER_BIT);

	glutSolidCube(1.0f);
	glutSolidCube(1.0f);
	glutSolidCube(1.0f);


	glFlush();
	glutSwapBuffers();
}
