#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
class ShootingPhase:public Action
{
	Player* PlayerList[MaxPlayerCount];
	int damage;

public:
	ShootingPhase(ApplicationManager* pApp,int damage);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~ShootingPhase();
};

