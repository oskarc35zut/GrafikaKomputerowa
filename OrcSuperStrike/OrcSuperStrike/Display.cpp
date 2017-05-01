#include "stdafx.h"
#include "Display.h"

class Display:DisplayInit {
public:
	#pragma region Konstruktor&Destruktor
		Display()
		{
			

			glutInitWindowPosition(100, 100);
			glutInitWindowSize(640, 360);
			glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

			glutCreateWindow("GKiW: Lab 3");

			glutDisplayFunc(OnRender);
			glutReshapeFunc(OnReshape);
			glutKeyboardFunc(OnKeyPress);
			glutKeyboardUpFunc(OnKeyUp);
			glutSpecialFunc(OnSpecialKeyPress); // klawisze specjalne (strzalki, F1-F12, PgUp/PgDn, Home, End, Delete, Insert)
			glutSpecialUpFunc(OnSpecialKeyUp);
			glutTimerFunc(17, OnTimer, 0);

			glEnable(GL_DEPTH_TEST);

			// Ustawiamy komponent ambient naszej sceny - wartosc niezalezna od swiatla (warto zresetowac)
			float gl_amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gl_amb);

			glEnable(GL_LIGHTING); // Wlaczenie oswietlenia
			glShadeModel(GL_SMOOTH); // Wybor techniki cieniowania
			glEnable(GL_LIGHT0); // Wlaczenie 0-go zrodla swiatla



			player.pos.x = 0.0f;
			player.pos.y = 0.0f;
			player.pos.z = 8.0f;

			player.dir.x = 0.0f;
			player.dir.y = 0.0f;
			player.dir.z = -1.0f;

			player.speed = 1.50f;
		}

		~Display()
		{
			ShutdownPhysics();
		}
	#pragma endregion





};