#pragma once
#include "GraphicDraw.h"
#include "btBulletDynamicsCommon.h"

class BasicPhysics : public GraphicDraw
{
public:
	BasicPhysics();
	~BasicPhysics();

	virtual void InitializePhysics() override;
	virtual void ShutdownPhysics() override;

	void CreateObjects();

		virtual void CollisionEvent(btRigidBody* pBody0, btRigidBody* pBody1) override;

	protected:
		// our box to lift
		PhysicsObject* m_pBox;

		// a simple trigger volume
		btCollisionObject* m_pTrigger;
};

