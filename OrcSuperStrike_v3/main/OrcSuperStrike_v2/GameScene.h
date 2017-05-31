#pragma once



static class GameScene
{
public:
	 GameScene();
	 ~GameScene();

	// Funkcja laduje dany poziom
	void LoadLevel(int LevelWhatYouWantToDraw);
	// Funkcja laduje aktualny poziom
	void LoadLevel();

protected:
	static int ActualLevel;

	// Zmien scene
	void PushActualLevelObjects();
	// Funkcja podstawowymi obiektami kazdego poziomu
	void MainObjects();

public:
	int GetActualLevel();
};

