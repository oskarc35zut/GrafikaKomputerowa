#include "StdAfx.h"
#include "GameScene.h"


GameScene::GameScene()
{
	ActualLevel = 0;
}

GameScene::~GameScene(){}

// Funkcja podstawowymi obiektami kazdego poziomu
void GameScene::MainObjects()
{

}

#pragma region LoadLevel
// Funkcja laduje dany poziom
void GameScene::LoadLevel(int LevelWhatYouWantToDraw)
{
	ActualLevel = LevelWhatYouWantToDraw;
	PushActualLevelObjects();
}

// Funkcja laduje aktualny poziom
void GameScene::LoadLevel()
{
	PushActualLevelObjects();
}
#pragma endregion //LoadLevel

void GameScene::PushActualLevelObjects()
{
	//Usuwanie wszystkich obiektow

	//Reset podstawowej sceny
	MainObjects();

	switch (ActualLevel)
	{
	case 0:
		break;
	default:
		break;
	}




}







int GameScene::GetActualLevel()
{
	return ActualLevel;
}
