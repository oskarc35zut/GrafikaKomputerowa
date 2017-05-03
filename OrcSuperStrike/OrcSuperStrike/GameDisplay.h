#pragma once
#include "stdafx.h"
#include "BulletDynamics/Dynamics/btDynamicsWorld.h"

class GameDisplay
{
public:
	GameDisplay();
	~GameDisplay();

	// Deklaracje funkcji u¿ywanych jako obs³uga zdarzeñ GLUT-a.
	void OnKeyPress(unsigned char, int, int);
	void OnSpecialKeyPress(int, int, int);

	void OnKeyDown(unsigned char, int, int);
	void OnSpecialKeyDown(int, int, int);

	void OnKeyUp(unsigned char, int, int);
	void OnSpecialKeyUp(int, int, int);

	void OnTimer(int);

	void OnRender();
	void OnReshape(int, int);
	
	struct vec3 {
		float x = 0.0f, y = 0.0f, z = 0.0f;
	};

	struct SCameraState {
		vec3 pos;
		vec3 dir;
		float speed = 0.0f;
		float velM = 0.0f, velS = 0.0f; // zmienne pomocnicze do efektu bezwladnosci kamery - aktualna predkosc
	};

	SCameraState player;

	double T = 0.0; // aktualny czas (a dokladniej - czas z ostatniego wywolania OnTimer())

	vec3 LightPos; // pozycja zrodla swiatla

	bool keystate[256];
	bool keystate_special[256];








	// Funckje fizyczne.
	virtual void InitializePhysics() {};
	virtual void ShutdownPhysics() {};

	// Bullet core
	btBroadphaseInterface* m_pBroadphase;
	btCollisionConfiguration* m_pCollisionConfiguration;
	btCollisionDispatcher* m_pDispatcher;
	btConstraintSolver* m_pSolver;
	btDynamicsWorld* m_pWorld;
};

