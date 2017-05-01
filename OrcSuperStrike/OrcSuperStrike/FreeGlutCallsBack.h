#pragma once
#include "stdafx.h"
#include "GameDisplay.h"

// global pointer to our application object
static GameDisplay* game;

#pragma region CallBaki

	// Deklaracje funkcji u¿ywanych jako obs³uga zdarzeñ GLUT-a.
	static void OnKeyPressCallBack(unsigned char key, int x, int y)
	{
		game->OnKeyPress(key, x, y);
	}
	static void OnSpecialKeyPressCallBack(int key, int x, int y)
	{
		game->OnSpecialKeyPress(key, x, y);
	}

	static void OnKeyDownCallBack(unsigned char key, int x, int y)
	{
		game->OnKeyDown(key, x, y);
	}
	static void OnSpecialKeyDownCallBack(int key, int x, int y)
	{
		game->OnSpecialKeyDown(key, x, y);
	}

	static void OnKeyUpCallBack(unsigned char key, int x, int y)
	{
		game->OnKeyUp(key, x, y);
	}
	static void OnSpecialKeyUpCallBack(int key, int x, int y)
	{
		game->OnSpecialKeyUp(key, x, y);
	}

	static void OnTimerCallBack(int id)
	{
		game->OnTimer(id);
	}



	static void OnRenderCallBack()
	{
		game->OnRender();
	}
	static void OnReshapeCallBack(int width, int height)
	{
		game->OnReshape(width, height);
	}

#pragma endregion //Callbaki


int glutmain(int argc, char **argv, int width, int height, const char* title, GameDisplay* gameOn) {
	// store the application object so we can
	// access it globally
	game = gameOn;

	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("Orc SuperStrike");



	glutDisplayFunc(OnRenderCallBack);
	glutReshapeFunc(OnReshapeCallBack);
	glutKeyboardFunc(OnKeyPressCallBack);
	glutKeyboardUpFunc(OnKeyUpCallBack);
	glutSpecialFunc(OnSpecialKeyPressCallBack); // klawisze specjalne (strzalki, F1-F12, PgUp/PgDn, Home, End, Delete, Insert)
	glutSpecialUpFunc(OnSpecialKeyUpCallBack);
	glutTimerFunc(17, OnTimerCallBack, 0);

	glEnable(GL_DEPTH_TEST);

	// Ustawiamy komponent ambient naszej sceny - wartosc niezalezna od swiatla (warto zresetowac)
	float gl_amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gl_amb);

	glEnable(GL_LIGHTING); // Wlaczenie oswietlenia
	glShadeModel(GL_SMOOTH); // Wybor techniki cieniowania
	glEnable(GL_LIGHT0); // Wlaczenie 0-go zrodla swiatla


	glutMainLoop();
	return 0;
}