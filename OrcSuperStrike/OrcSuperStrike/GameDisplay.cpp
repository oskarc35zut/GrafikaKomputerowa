#include "stdafx.h"
#include "GameDisplay.h"


GameDisplay::GameDisplay()
	:
	m_pBroadphase(0),
	m_pCollisionConfiguration(0),
	m_pDispatcher(0),
	m_pSolver(0),
	m_pWorld(0)
{

	LightPos.x = 0.0f;
	LightPos.y = 0.0f;
	LightPos.z = 0.0f;

	player.pos.x = 0.0f;
	player.pos.y = 0.0f;
	player.pos.z = 8.0f;

	player.dir.x = 0.0f;
	player.dir.y = 0.0f;
	player.dir.z = -1.0f;

	player.speed = 1.50f;

	for (int i = 0; i < 256; i++)
	{
		keystate[i] = false;
		keystate_special[i] = false;
	}

	
}

 

GameDisplay::~GameDisplay()
{
	ShutdownPhysics();
}

#pragma region Obsluga wejscia

void GameDisplay::OnKeyPress(unsigned char key, int x, int y)
{
	if (!keystate[key]) {
		OnKeyDown(key, x, y);
	}
	keystate[key] = true;
}

void GameDisplay::OnSpecialKeyPress(int key, int x, int y)
{
	if (!keystate_special[key]) {
		OnSpecialKeyDown(key, x, y);
	}
	keystate_special[key] = true;
}

void GameDisplay::OnKeyDown(unsigned char key, int x, int y)
{
	if (key == 27) {
		glutLeaveMainLoop();
	}
}

void GameDisplay::OnSpecialKeyDown(int key, int x, int y)
{
}

void GameDisplay::OnKeyUp(unsigned char key, int x, int y)
{
	keystate[key] = false;
}

void GameDisplay::OnSpecialKeyUp(int key, int x, int y)
{
	keystate_special[key] = false;
}

#pragma endregion //Obsluga wejscia

void GameDisplay::OnTimer(int id)
{
	T = glutGet(GLUT_ELAPSED_TIME); // Ile milisekund uplynelo od momentu uruchomienia programu?

#pragma region Ruch kamery

									// Zmiana predkosci gracza jesli wcisniete W/S/A/D
	if (keystate['w']) {
		player.velM = player.speed;
	}
	if (keystate['s']) {
		player.velM = -player.speed;
	}
	if (keystate['a']) {
		player.velS = -player.speed;
	}
	if (keystate['d']) {
		player.velS = player.speed;
	}

	// Obrot kamery
	float phi = (float)atan2(player.dir.z, player.dir.x);
	if (keystate['q']) {
		phi -= .03f;
	}
	if (keystate['e']) {
		phi += .03f;
	}

	player.dir.x = (float)cos(phi);
	player.dir.z = (float)sin(phi);

	// Znalezienie kierunku prostopadlego
	vec3 per;
	per.x = -player.dir.z;
	per.z = player.dir.x;

	// Chodzenie przod/tyl
	player.pos.x += player.dir.x * player.velM * .1f;
	player.pos.y += player.dir.y * player.velM * .1f;
	player.pos.z += player.dir.z * player.velM * .1f;

	// Chodzenie na boki
	player.pos.x += per.x * player.velS * .1f;
	player.pos.z += per.z * player.velS * .1f;

	// Bezwladnosc - w kazdym cyklu maleje predkosc gracza
	player.velM /= 1.2f;
	player.velS /= 1.2f;

#pragma endregion

#pragma region Ruch swiatla

	if (keystate_special[GLUT_KEY_LEFT]) {
		LightPos.x -= .05f;
	}
	if (keystate_special[GLUT_KEY_RIGHT]) {
		LightPos.x += .05f;
	}
	if (keystate_special[GLUT_KEY_UP]) {
		LightPos.y += .05f;
	}
	if (keystate_special[GLUT_KEY_DOWN]) {
		LightPos.y -= .05f;
	}

#pragma endregion

}

void GameDisplay::OnRender()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		player.pos.x, player.pos.y, player.pos.z,
		player.pos.x + player.dir.x, player.pos.y + player.dir.y, player.pos.z + player.dir.z,
		0.0f, 1.0f, 0.0f
	);

#pragma region Swiatlo






	float l0_amb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float l0_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float l0_spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	printf("X=%f Y=%f Z=%f\n", LightPos.x, LightPos.y, LightPos.z);
	float l0_pos[] = { LightPos.x, 1.0f, LightPos.y, 0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l0_spe);
	glLightfv(GL_LIGHT0, GL_POSITION, l0_pos);

#pragma endregion


#pragma region Kule

	for (int ix = -30; ix <= 30; ix += 5) {
		for (int iz = -30; iz <= 30; iz += 5) {
			float m1_amb[] = { 0.0f, 1.0f, 0.0f, 1.0f };
			float m1_dif[] = { 0.0f, 1.0f, 0.0f, 1.0f };
			float m1_spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
			glMaterialfv(GL_FRONT, GL_AMBIENT, m1_amb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, m1_dif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, m1_spe);
			glMaterialf(GL_FRONT, GL_SHININESS, 20.0f);

			glPushMatrix();
			glTranslatef((GLfloat)ix, 5.0f, (GLfloat)iz);
			glutSolidSphere(1.0f, 16, 16);
			glPopMatrix();

		}
	}

#pragma endregion //Kule

#pragma region Szesciany

	for (int ix = -30; ix <= 30; ix += 5) {
		for (int iz = -30; iz <= 30; iz += 5) {
			float m1_amb[] = { 0.0f, 0.2f, 1.0f, 1.0f };
			float m1_dif[] = { 0.0f, 0.2f, 1.0f, 1.0f };
			float m1_spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
			glMaterialfv(GL_FRONT, GL_AMBIENT, m1_amb);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, m1_dif);
			glMaterialfv(GL_FRONT, GL_SPECULAR, m1_spe);
			glMaterialf(GL_FRONT, GL_SHININESS, 20.0f);

			glPushMatrix();
			glTranslatef((GLfloat)ix, -0.2f, (GLfloat)iz);
			glutSolidCube(1.4);
			glPopMatrix();

		}
	}

#pragma endregion //Szeœcian





	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();

}

void GameDisplay::OnReshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float)width / height, .01f, 100.0f);
}


