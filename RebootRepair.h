#pragma once
#include "Action.h"
#include "Player.h"
using namespace std;
class RebootRepairAction : public Action
{
private:
	Player* pPlayer;
	Grid* pGrid;
public:
	RebootRepairAction(ApplicationManager* pApp);

	virtual void  ReadActionParameters();

	virtual void  Execute();
	virtual  ~RebootRepairAction();


};