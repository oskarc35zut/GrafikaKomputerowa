#pragma once
#ifndef _GRAPHICDRAW_H_
#define _GRAPHICDRAW_H_


#include <Windows.h>
#include <GL/GL.h>
#include <GL/freeglut.h>

#include "BulletDynamics/Dynamics/btDynamicsWorld.h"

#include "MotionState.h"

// Our custom debug renderer
#include "DebugDrawer.h"

#include "PhysicsObject.h"
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

	// a convenient typedef to reference an STL vector of PhysicsObjects
	typedef std::vector<PhysicsObject*> PhysicsObjects;

	// convenient typedefs for collision events
	typedef std::pair<const btRigidBody*, const btRigidBody*> CollisionPair;
	typedef std::set<CollisionPair> CollisionPairs;


	// struct to store our raycasting results
	struct RayResult {
	btRigidBody* pBody;
	btVector3 hitPoint;
	};

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

	virtual void RenderScene();
	virtual void UpdateScene(float dt);

	virtual void InitializePhysics() {};
	virtual void ShutdownPhysics() {};

	void UpdateCamera();
	void RotateCamera(float &angle, float value);
	void ZoomCamera(float distance);

	// drawing functions
	void DrawBox(const btVector3 &halfSize);
		void DrawShape(btScalar* transform, const btCollisionShape* pShape, const btVector3 &color);
	
		// object functions
		PhysicsObject* CreatePhysicsObject(btCollisionShape* pShape,
		const float &mass,
		const btVector3 &color = btVector3(1.0f, 1.0f, 1.0f),
		const btVector3 &initialPosition = btVector3(0.0f, 0.0f, 0.0f),
		const btQuaternion &initialRotation = btQuaternion(0, 0, 1, 1));

		void ShootBox(const btVector3 &direction);
		void DestroyGameObject(btRigidBody* pBody);
		PhysicsObject* FindPhysicsObject(btRigidBody* pBody);

		// picking functions
		btVector3 GetPickingRay(int x, int y);
		bool Raycast(const btVector3 &startPosition, const btVector3 &direction, RayResult &output);


		// constraint functions
		void CreatePickingConstraint(int x, int y);
		void RemovePickingConstraint();

		// collision event functions
		void CheckForCollisionEvents();
		virtual void CollisionEvent(btRigidBody* pBody0, btRigidBody * pBody1);
		virtual void SeparationEvent(btRigidBody * pBody0, btRigidBody * pBody1);

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



	
	// a simple clock for counting time
	btClock m_clock;

	// an array of our game objects
	PhysicsObjects m_objects;

	// debug renderer
	DebugDrawer* m_pDebugDrawer;

	// constraint variables ograniczenia/przymuszenia
	btRigidBody* m_pPickedBody;				// the body we picked up
	btTypedConstraint*  m_pPickConstraint;	// the constraint the body is attached to
	btScalar m_oldPickingDist;				// the distance from the camera to the hit point (so we can move the object up, down, left and right from our view)

	// collision event variables
	CollisionPairs m_pairsLastUpdate;

};
#endif
