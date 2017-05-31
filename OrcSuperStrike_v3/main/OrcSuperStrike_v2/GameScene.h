#pragma once



static class GameScene
{
public:
	 GameScene();
	 ~GameScene();

	// Funkcja laduje dany poziom
	static void LoadLevel(int LevelWhatYouWantToDraw);
	// Funkcja laduje aktualny poziom
	static void LoadLevel();

protected:
	static int ActualLevel;

	// Zmien scene
	static void PushActualLevelObjects();
	// Funkcja podstawowymi obiektami kazdego poziomu
	static void MainObjects();

public:
	static int GetActualLevel();
};

