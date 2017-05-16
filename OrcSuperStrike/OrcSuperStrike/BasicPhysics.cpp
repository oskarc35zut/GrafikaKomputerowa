#include "stdafx.h"
#include "BasicPhysics.h"
#include "bullet.h"



BasicPhysics::BasicPhysics()
{
}

BasicPhysics::~BasicPhysics()
{
}




void BasicPhysics::InitializePhysics()
{
	//stworz konfiguracje kolizji
	//m_pCollisionConfiguration = new btDefaultCollisionConfiguration();
	//// stworz dispatcher
	//m_pDispatcher = new btCollisionDispatcher(m_pCollisionConfiguration);
	//// stworz broadphase
	//m_pBroadphase = new btDbvtBroadphase();
	//// stworz constraint solver
	//m_pSolver = new btSequentialImpulseConstraintSolver();
	//// stworz swiat
	//m_pWorld = new btDiscreteDynamicsWorld(m_pDispatcher, m_pBroadphase, m_pSolver, m_pCollisionConfiguration);
}


void BasicPhysics::ShutdownPhysics()
{
	delete m_pWorld;
	delete m_pSolver;
	delete m_pBroadphase;
	delete m_pDispatcher;
	delete m_pCollisionConfiguration;
}
