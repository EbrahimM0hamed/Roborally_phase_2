#pragma once
#include "ApplicationManager.h"
class Rounds
{
	ApplicationManager* pManager;
	int playerRound;
public:
    Rounds();
    void Execute(ApplicationManager* pApp, ActionType ActType);
	~Rounds();
};
