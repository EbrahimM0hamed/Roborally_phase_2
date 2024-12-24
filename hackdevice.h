#pragma once
#include "Action.h"
class hackdevice : public Action
{
private:
	ApplicationManager* pApp;
	Player* player;
	Grid* pGrid;

public:
	hackdevice(ApplicationManager* pApp, Player* player, Grid* pGrid);

	virtual void  ReadActionParameters();

	virtual void  Execute();
	virtual  ~hackdevice();
};

