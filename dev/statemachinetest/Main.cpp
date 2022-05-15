#include "SceneManager.h"
#include "Level0.h"
#include "Level1.h"


int main() {
	SceneManager* sceneM = new SceneManager();
	Level0* lvl0 = new Level0();
	Level1* lvl1 = new Level1();
	sceneM->Add_States(lvl0);
	sceneM->Add_States(lvl1);
	sceneM->Initial_States = lvl0;
	sceneM->Reset_FSM();


	return 0;
}