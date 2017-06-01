#include "BasicDemo.h"


// Funkcja podstawowymi obiektami kazdego poziomu
void BasicDemo::MainObjects()
{
	// create a tube
	btVector3 TubeBoxShape = btVector3(0.1, 5, 100);
	btVector3 Tubecolor = btVector3(1.46f, 0.87f, 0.35f);
	btVector3 Position = btVector3(0.0f, 0.0f, 0.0f);
	btQuaternion TubeRotate = btQuaternion(0,0,1,1);

	CreateGameObject(std::string("plane"), new btBoxShape(TubeBoxShape), 0, btVector3(0.46f, 0.87f, 0.35f), Position, btVector3(0.0, 0.0, 0.0));

	//CreateGameObject(std::string("plane2"), new btBoxShape(TubeBoxShape), 0, Tubecolor, Position, btVector3(0.0, 0.0, 0.0));


}



#pragma region LoadLevel
// Funkcja laduje dany poziom
void BasicDemo::LoadLevel(int LevelWhatYouWantToDraw)
{
	ActualLevel = LevelWhatYouWantToDraw;
	PushActualLevelObjects();
}

// Funkcja laduje aktualny poziom
void BasicDemo::LoadLevel()
{
	PushActualLevelObjects();
}
#pragma endregion //LoadLevel

void BasicDemo::PushActualLevelObjects()
{
	//Usuwanie wszystkich obiektow

#pragma region Declarations

	btTransform triggerTrans;
	btVector3 points[5];
	btConvexHullShape* pShape;
	btCollisionShape* pRod;
	btCollisionShape* pLoad;
	btTransform trans;
	btCompoundShape* pCompound;

#pragma endregion //Declarations

	//Reset podstawowej sceny
	MainObjects();



	switch (ActualLevel)
	{
	case 0:
		#pragma region Lvl0

		// create our red box, but store the pointer for future usage
		m_pBox = CreateGameObject(std::string("brak"), new btBoxShape(btVector3(1, 1, 1)), 1.0, btVector3(1.0f, 0.2f, 0.2f), btVector3(0.0f, 10.0f, 0.0f));

		// create a second box
		CreateGameObject(std::string("brak"), new btBoxShape(btVector3(1, 1, 1)), 1.0, btVector3(0.0f, 0.2f, 0.8f), btVector3(1.25f, 20.0f, 0.0f));

		// create a trigger volume
		m_pTrigger = new btCollisionObject();
		// create a box for the trigger's shape
		m_pTrigger->setCollisionShape(new btBoxShape(btVector3(1, 0.25, 1)));
		// set the trigger's position
		triggerTrans.setIdentity();
		triggerTrans.setOrigin(btVector3(0, 1.5, 0));
		m_pTrigger->setWorldTransform(triggerTrans);
		// flag the trigger to ignore contact responses
		m_pTrigger->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
		// add the trigger to our world
		m_pWorld->addCollisionObject(m_pTrigger);

		// create a yellow sphere
		CreateGameObject(std::string("brak"), new btSphereShape(1.0f), 1.0, btVector3(0.7f, 0.7f, 0.0f), btVector3(-5.0, 10.0f, 0.0f));

		// create a green cylinder
		CreateGameObject(std::string("brak"), new btCylinderShape(btVector3(1, 1, 1)), 1.0, btVector3(0.0f, 0.7f, 0.0f), btVector3(-2, 10.0f, 0.0f));

		// create a vertex cloud defining a square-based pyramid
		points[0] = btVector3(-0.5, 1, 1);
		points[1] = btVector3(-0.5, 1, -1);
		points[2] = btVector3(-0.5, -1, 1);
		points[3] = btVector3(-0.5, -1, -1);
		points[4] = btVector3(1, 0, 0);
	
		// create our convex hull
		pShape = new btConvexHullShape(&points[0].getX(), 5);
		// initialize the object as a polyhedron
		pShape->initializePolyhedralFeatures();
		// create the game object using our convex hull shape
		CreateGameObject(std::string("brak"), pShape, 1.0, btVector3(1, 1, 1), btVector3(5, 15, 0));

		// create two shapes for the rod and the load
		pRod = new btBoxShape(btVector3(1.5f, 0.2f, 0.2f));
		pLoad = new btSphereShape(0.5f);
		// create a transform we'll use to set each object's position
		trans.setIdentity();
		// create our compound shape
		pCompound = new btCompoundShape();
		// add the rod
		pCompound->addChildShape(trans, pRod);
		trans.setOrigin(btVector3(-1.75f, 0.0f, 0.0f));
		// add the top load
		pCompound->addChildShape(trans, pLoad);
		trans.setIdentity();
		// add the bottom load
		trans.setOrigin(btVector3(1.75f, 0.0f, 0.0f));
		pCompound->addChildShape(trans, pLoad);
		// create a game object using the compound shape
		CreateGameObject(std::string("brak"), pCompound, 2.0f, btVector3(0.8, 0.4, 0.1), btVector3(-4, 10.0f, 0.0f));
		#pragma endregion //Lvl0
		break;
	case 1:
		#pragma region Lvl1

		#pragma endregion //Lvl1
		break;
	case 2:
		#pragma region Lvl2

		#pragma endregion //Lvl2
		break;
	default:
		break;
	}




}

int BasicDemo::GetActualLevel()
{
	return ActualLevel;
}
