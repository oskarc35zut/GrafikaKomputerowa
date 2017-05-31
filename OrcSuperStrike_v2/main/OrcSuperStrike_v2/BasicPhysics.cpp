#include "StdAfx.h"
#include "BasicPhysics.h"


BasicPhysics::BasicPhysics()
{
	
}


BasicPhysics::~BasicPhysics()
{
}

void BasicPhysics::InitializePhysics()
{
	// create the collision configuration
	m_pCollisionConfiguration = new btDefaultCollisionConfiguration();
	// create the dispatcher
	m_pDispatcher = new btCollisionDispatcher(m_pCollisionConfiguration);
	// create the broadphase
	m_pBroadphase = new btDbvtBroadphase();
	// create the constraint solver
	m_pSolver = new btSequentialImpulseConstraintSolver();
	// create the world
	m_pWorld = new btDiscreteDynamicsWorld(m_pDispatcher, m_pBroadphase, m_pSolver, m_pCollisionConfiguration);
	
	// create our scene's physics objects
	CreateObjects();
}

void BasicPhysics::ShutdownPhysics()
{
	delete m_pWorld;
	delete m_pSolver;
	delete m_pBroadphase;
	delete m_pDispatcher;
	delete m_pCollisionConfiguration;
}

void BasicPhysics::CreateObjects()
{
		// create a ground plane
		CreatePhysicsObject(new btBoxShape(btVector3(1, 20, 100)), 0, btVector3(0.2f, 0.6f, 0.6f), btVector3(0.0f, 0.0f, 50.0f));
	
		// create our original red box
		CreatePhysicsObject(new btBoxShape(btVector3(1, 1, 1)), 1.0, btVector3(1.0f, 0.2f, 0.2f), btVector3(0.0f, 10.0f, 0.0f));
	
		// create a second box
		CreatePhysicsObject(new btBoxShape(btVector3(1, 1, 1)), 1.0, btVector3(0.0f, 0.2f, 0.8f), btVector3(1.25f, 20.0f, 0.0f));
}
