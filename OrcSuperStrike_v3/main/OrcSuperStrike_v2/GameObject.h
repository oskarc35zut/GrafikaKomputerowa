#define _USE_MATH_DEFINES

#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "btBulletDynamicsCommon.h"

#include "OpenGLMotionState.h"
#include <math.h>
class GameObject {
public:
	GameObject(std::string &name, btCollisionShape* pShape, float mass, const btVector3 &color, const btVector3 &initialPosition = btVector3(0,0,0), const btVector3 &angles = btVector3(0, 0, 0));
	~GameObject();

	// accessors
	btCollisionShape* GetShape() { return m_pShape; }

	btRigidBody* GetRigidBody() { return m_pBody; }

	btMotionState* GetMotionState() { return m_pMotionState; }

	std::string GetName() { return m_name; }

	void RotateGameObject(const btVector3 & angles);

	void GetTransform(btScalar* transform) { 
		if (m_pMotionState) m_pMotionState->GetWorldTransform(transform); 
	}
	
	btVector3 GetColor() { return m_color; }

	void SetColor(const btVector3 &color) { m_color = color; }

protected:
	btCollisionShape*  m_pShape;
	btRigidBody*    m_pBody;
	OpenGLMotionState*  m_pMotionState;
	btVector3      m_color;
	std::string m_name;
	float m_mass;
};
#endif
