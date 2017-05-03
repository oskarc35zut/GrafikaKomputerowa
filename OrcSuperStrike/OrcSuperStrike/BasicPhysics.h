#include "GameDisplay.h"
#include "btBulletDynamicsCommon.h"

class BasicPhysics : public GameDisplay
{
public:
	BasicPhysics();
	~BasicPhysics();
	virtual void InitializePhysics();
	virtual void ShutdownPhysics();
};
