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
};

