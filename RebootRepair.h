#pragma once
#include "Action.h"
#include "Player.h"
using namespace std;
class RebootRepairAction : public Action
{
private:
	Player* player;
	Grid* pGrid;
public:
	RebootRepairAction(ApplicationManager* pApp, Player* player, Grid* pGrid);

	virtual void  ReadActionParameters();

	virtual void  Execute();
	virtual  ~RebootRepairAction();


};