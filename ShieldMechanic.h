#pragma once
#include "Action.h"
#include "Player.h"
#include "Grid.h"
class ShieldMechanic:public Action
{
public:
	ShieldMechanic(ApplicationManager* pApp);	
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~ShieldMechanic();
};

