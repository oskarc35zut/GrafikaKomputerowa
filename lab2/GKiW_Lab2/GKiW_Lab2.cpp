#include "stdafx.h"
#include "GKiW_Lab2.h"
float tmp = 0;
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("GKiW: Lab 2");

	glutSetCursor(GLUT_CURSOR_NONE);
	glutFullScreen();

	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyUp);
	glutTimerFunc(17, OnTimer, 0);

	glEnable(GL_DEPTH_TEST);
	
	// Inicjalizacja stanu kamery:
	player.pos.x = 0.0f;
	player.pos.y = 1.75f;
	player.pos.z = 0.0f;
	player.dir.x = 0.0f;
	player.dir.y = 0.0f;
	player.dir.z = -1.0f;
	player.speed = 0.1f;

	

	glutMainLoop();

	return 0;
}

// Tablica przechowująca stan klawiszy w formie flag, indeksowana wg kodów ASCII.
bool keystate[256];

// Obsługa zdarzenia, gdy zostanie wciśnięty klawisz - zdarzenie nieoodporne na repetycję klawiszy.
void OnKeyPress(unsigned char key, int x, int y) {
	printf("KeyPress: %c\n", key);
	if (!keystate[key]) {
		OnKeyDown(key, x, y); // Emulacja zdarzenia związanego z pojedynczym wciśnięciem klawisza
	}
	keystate[key] = true;
}

// Obsługa naszego własnego zdarzenia, gdy zostanie po raz pierwszy wciśnięty klawisz - zdarzenie odporne na repetycję.
void OnKeyDown(unsigned char key, int x, int y) {
	//printf("KeyDown: %c\n", key);
	if (key == 27) { // ESC - wyjście
		glutLeaveMainLoop();
	}
}

// Obsługa zdarzenia puszczenia klawisza.
void OnKeyUp(unsigned char key, int x, int y) {
	printf("KeyUp: %c\n", key);
	keystate[key] = false;
}

// Aktualizacja stanu gry - wywoływana za pośrednictwem zdarzenia-timera.
void OnTimer(int id) {

	// Chcemy, by ta funkcja została wywołana ponownie za 17ms.
	glutTimerFunc(17, OnTimer, 0);


	// Chodzenie do przodu:
	if (keystate['w']) {
		player.pos.x += player.dir.x * player.speed;
		player.pos.y += player.dir.y * player.speed;
		player.pos.z += player.dir.z * player.speed;
	}

	// Chodzenie do tyłu:
	if (keystate['s']) {
		player.pos.x -= player.dir.x * player.speed;
		player.pos.y -= player.dir.y * player.speed;
		player.pos.z -= player.dir.z * player.speed;
	}

	if (keystate['a']) {
		player.pos.x += player.dir.z * player.speed;
		player.pos.y += player.dir.y * player.speed;
		player.pos.z += player.dir.x * player.speed;
	}

	if (keystate['d']) {
		player.pos.x -= player.dir.z * player.speed;
		player.pos.y += player.dir.y * player.speed;
		player.pos.z -= player.dir.x * player.speed;
	}

	if (keystate['j']) {
		printf("J rotate: X=%f Z=%f z=5f x=%f delta=%f\n ", cos(5.0f + atan2f(player.dir.z, player.dir.x)), sin(5.0f + atan2f(player.dir.z, player.dir.x)), player.dir.z, player.dir.x, player.dir.x - tmp);
		tmp = player.dir.x;

		player.dir.x = cos(atan2f(player.dir.z, player.dir.x) - 0.06f);
		player.dir.z = sin(atan2f(player.dir.z, player.dir.x) - 0.06f);

	}

	if (keystate['l']) {
		printf("L rotate: %f\n", cos(5 + atan2f(player.dir.z, player.dir.x)));
		player.dir.x = cos(atan2f(player.dir.z, player.dir.x) + 0.06f);
		player.dir.z = sin(atan2f(player.dir.z, player.dir.x) + 0.06f);
	}

	if (keystate['i']) {
		printf("Up Xd= %f  Zd= %f  Yd= %f\n", player.dir.x, player.dir.z, player.dir.y);
		player.dir.y += 0.04f;
	}

	if (keystate['k']) {
		printf("do Xd= %f  Zd= %f  Yd= %f\n", player.dir.x, player.dir.z, player.dir.y);
		player.dir.y -= 0.04f;
	}

}

int tmpX;
int tmpY;

void Mysz(int x, int y)
{
	if (x>tmpX)
	{
		player.dir.x = cos(atan2f(player.dir.z, player.dir.x) - 0.03f);
		player.dir.z = sin(atan2f(player.dir.z, player.dir.x) - 0.03f);
	}
	if (x<tmpX)
	{
		player.dir.x = cos(atan2f(player.dir.z, player.dir.x) + 0.03f);
		player.dir.z = sin(atan2f(player.dir.z, player.dir.x) + 0.03f);
	}
	tmpX = x;

	if (y>tmpY)
	{
		player.dir.y -= 0.03f;
	}
	if (y<tmpY)
	{
		player.dir.y += 0.03f;
	}
	tmpY = y;
}

void OnRender() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Ustawienie kamery na podstawie jej stanu przechowywanego w zmiennej player.
	gluLookAt(
		player.pos.x, player.pos.y, player.pos.z, // Pozycja kamery
		player.pos.x + player.dir.x, player.pos.y + player.dir.y, player.pos.z + player.dir.z, // Punkt na ktory patrzy kamera (pozycja + kierunek)
		0.0f, 1.0f, 0.0f // Wektor wyznaczajacy pion
	);

	// Narysowanie "siatki" złożonej ze 121 kolorowych sfer.
	for (int ix = -5; ix <= 5; ix+=1) {
		for (int iz = -5; iz <= 5; iz+=1) {
			glColor3f(.5f + .1f * ix, .5f - .1f * iz, 0.0f);
			glPushMatrix();
				glTranslatef(ix, 1.0f, iz);
				glutSolidSphere(.05f, 8, 8);
			glPopMatrix();
		}
	}

	glutPassiveMotionFunc(&Mysz);

	if (tmpY > 250 || tmpY < 150 || tmpX > 250 || tmpX < 150)
	{
		glutWarpPointer(200, 200);
	}
	
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void OnReshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float) width / height, .01f, 100.0f);
}
