#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
#include "Cell.h"
class NewGame :
    public Action
{
public:
	NewGame(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~NewGame();
};

