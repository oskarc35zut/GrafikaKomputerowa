#include "stdafx.h"
#include "OpenGL.h"
#include "bullet.h"

class DisplayInit
{

public:
	//DisplayInit();
	//~DisplayInit();

	// Deklaracje funkcji u¿ywanych jako obs³uga zdarzeñ GLUT-a.
	void OnRender();
	void OnReshape(int, int);
	void OnKeyPress(unsigned char, int, int);
	void OnKeyDown(unsigned char, int, int);
	void OnKeyUp(unsigned char, int, int);
	void OnSpecialKeyPress(int, int, int);
	void OnSpecialKeyDown(int, int, int);
	void OnSpecialKeyUp(int, int, int);
	void OnTimer(int);

	struct vec3 {
		float x, y, z;
	};

	struct SCameraState {
		vec3 pos;
		vec3 dir;
		float speed;
		float velM, velS; // zmienne pomocnicze do efektu bezwladnosci kamery - aktualna predkosc
	};

	SCameraState player;

	double T = 0.0; // aktualny czas (a dokladniej - czas z ostatniego wywolania OnTimer())

	vec3 LightPos; // pozycja zrodla swiatla


	//Fizyka
	virtual void InitializePhysics() {};
	virtual void ShutdownPhysics() {};

	void UpdateCamera();
	void RotateCamera(float &angle, float value);
	void ZoomCamera(float distance);

	void DrawBox(const btVector3 &halfSize, const btVector3 &color = btVector3(1.0f, 1.0f, 1.0f));



//private:
//
//	// camera control
//	btVector3 m_cameraPosition; // the camera's current position
//	btVector3 m_cameraTarget;	 // the camera's lookAt target
//	float m_nearPlane; // minimum distance the camera will render
//	float m_farPlane; // farthest distance the camera will render
//	btVector3 m_upVector; // keeps the camera rotated correctly
//	float m_cameraDistance; // distance from the camera to its target
//	float m_cameraPitch; // pitch of the camera 
//	float m_cameraYaw; // yaw of the camera
//
//	int m_screenWidth;
//	int m_screenHeight;
//
};