#pragma once
#ifndef _GRAPHICDRAW_H_
#define _GRAPHICDRAW_H_


#include <Windows.h>
#include <GL/GL.h>
#include <GL/freeglut.h>

#include "BulletDynamics/Dynamics/btDynamicsWorld.h"

class GraphicDraw
{
public:
	GraphicDraw();
	~GraphicDraw();
	void Initialize();
	// FreeGLUT callbacks
	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void KeyboardUp(unsigned char key, int x, int y);
	virtual void Special(int key, int x, int y);
	virtual void SpecialUp(int key, int x, int y);
	virtual void Reshape(int w, int h);
	virtual void Idle();
	virtual void Mouse(int button, int state, int x, int y);
	virtual void PassiveMotion(int x, int y);
	virtual void Motion(int x, int y);
	virtual void Display();


	virtual void InitializePhysics() {};
	virtual void ShutdownPhysics() {};


	void UpdateCamera();
	void RotateCamera(float &angle, float value);
	void ZoomCamera(float distance);

	// drawing functions
	void DrawBox(const btVector3 &halfSize, const btVector3 &color = btVector3(1.0f, 1.0f, 1.0f));

protected:
	// camera control
	btVector3 m_cameraPosition;
	btVector3 m_cameraTarget;// LookAt
	float m_nearPlane; // Minimalny dystans renderowania
	float m_farPlane; // Maksymalny dystans renderowania
	btVector3 m_upVector; // Vektor oboru kamery
	float m_cameraDistance; // Odleglosc od celu
	float m_cameraPitch; // Skok kamery
	float m_cameraYaw; // Znieksztalcenie kamery

	int m_screenWidth;
	int m_screenHeight;

	// core Bullet components
	btBroadphaseInterface* m_pBroadphase;
	btCollisionConfiguration* m_pCollisionConfiguration;
	btCollisionDispatcher* m_pDispatcher;
	btConstraintSolver* m_pSolver;
	btDynamicsWorld* m_pWorld;
};
#endif
