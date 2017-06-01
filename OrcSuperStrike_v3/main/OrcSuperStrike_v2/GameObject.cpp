#include "GameObject.h"
GameObject::GameObject(std::string & name, btCollisionShape * pShape, float mass, const btVector3 & color, const btVector3 & initialPosition, const btVector3 & angles)
{
	//set object name
	m_name = name;

	// store the shape for later usage
	m_pShape = pShape;

	// store the color
	m_color = color;

	// store the mass
	m_mass = mass;



	// create the initial transform
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(initialPosition);
	
	// rotate the body
	btQuaternion rotation;
	double onegrade = (M_PI / 180);
	rotation.setEuler(onegrade * angles.getY(), onegrade *  angles.getX(), onegrade *  angles.getZ() + M_PI / 2);
	
	transform.setRotation(rotation);


	// create the motion state from the
	// initial transform
	m_pMotionState = new OpenGLMotionState(transform);



	// calculate the local inertia
	btVector3 localInertia(0,0,0);

	// objects of infinite mass can't
	// move or rotate
	if (mass != 0.0f)
		pShape->calculateLocalInertia(mass, localInertia);
	
	// create the rigid body construction
	// info using the mass, motion state
	// and shape
	btRigidBody::btRigidBodyConstructionInfo cInfo(mass, m_pMotionState, pShape, localInertia);
	
	// create the rigid body
	m_pBody = new btRigidBody(cInfo);


}


void GameObject::RotateGameObject(const btVector3 & angles)
{
	

	btTransform transform;
	transform.setIdentity();

	btQuaternion rotate;
	double onegrade = (M_PI / 180);
	rotate.setEuler(onegrade * angles.getY(), onegrade *  angles.getX(), onegrade *  angles.getZ() + M_PI / 2);
	
	transform.setRotation(rotate);

	(this->m_pBody)->setCenterOfMassTransform(transform);

	// create the motion state from the
	// initial transform
	m_pMotionState = new OpenGLMotionState(transform);



	// calculate the local inertia
	//btVector3 localInertia(0, 0, 0);

	// create the rigid body construction
	// info using the mass, motion state
	// and shape
	//btRigidBody::btRigidBodyConstructionInfo cInfo(m_mass, m_pMotionState, m_pShape, localInertia);

	// create the rigid body
	//m_pBody = new btRigidBody(cInfo);

}




GameObject::~GameObject() {
	delete m_pBody;
	delete m_pMotionState;
	delete m_pShape;
}


