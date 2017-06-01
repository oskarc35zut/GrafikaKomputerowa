#include "GameObject.h"
GameObject::GameObject(std::string & name, btCollisionShape * pShape, float mass, const btVector3 & color, const btVector3 & initialPosition, const btVector3 & angles)
{
	//set object name
	m_name = name;

	// store the shape for later usage
	m_pShape = pShape;

	// store the color
	m_color = color;





	// create the initial transform
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(initialPosition);
	

	btQuaternion rotation;// = btQuaternion(0, 0, 1, 1);
	rotation.setEuler(angles.getY(), angles.getX(), angles.getZ() + M_PI / 2);
	

	//// create orientation vectors
	//btVector3 up(0, 1, 0);
	//btVector3 lookat = quatRotate(rotation, btVector3(0, 0, 1));
	//btVector3 forward = btVector3(lookat.getX(), 0, lookat.getZ()).normalize();
	//btVector3 side = btCross(up, forward);

	//// rotate camera with quaternions created from axis and angle
	//rotation = btQuaternion(up, angles.getY()) * rotation;
	//rotation = btQuaternion(side, angles.getX()) * rotation;
	//rotation = btQuaternion(forward, angles.getZ()) * rotation;



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


void GameObject::RotateGameObject(GameObject * obj, const btVector3 & angles)
{
	

	btTransform transform;
	transform.setIdentity();

	btQuaternion quat;

	quat.setEuler(angles.getY(), angles.getX(), angles.getZ() + M_PI / 2);

	obj->m_pBody->setCenterOfMassTransform(transform);

	//// create the initial transform
	//btTransform transform;
	////transform = obj->m_pMotionState;

	//btQuaternion rotation = btQuaternion(0, 0, 1, 1);

	//// create orientation vectors
	//btVector3 up(0, 1, 0);
	//btVector3 lookat = quatRotate(rotation, btVector3(0, 0, 1));
	//btVector3 forward = btVector3(lookat.getX(), 0, lookat.getZ()).normalize();
	//btVector3 side = btCross(up, forward);

	//// rotate camera with quaternions created from axis and angle
	//rotation = btQuaternion(up, angles.getY()) * rotation;
	//rotation = btQuaternion(side, angles.getX()) * rotation;
	//rotation = btQuaternion(forward, angles.getZ()) * rotation;



	//transform.setRotation(rotation);



	//// create the motion state from the
	//// initial transform
	//m_pMotionState = new OpenGLMotionState(transform);
}




GameObject::~GameObject() {
	delete m_pBody;
	delete m_pMotionState;
	delete m_pShape;
}


