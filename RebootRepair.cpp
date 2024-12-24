#include "RebootRepair.h"
#include"ApplicationManager.h"
#include"Player.h"
using namespace std;

RebootRepairAction::RebootRepairAction(ApplicationManager* pApp, Player* player, Grid* pGrid) :Action(pApp)
{
	this->player = player;
	this->pGrid = pGrid;
}
void RebootRepairAction::ReadActionParameters()
{
}

void RebootRepairAction::Execute()
{
	player->SetHealth(10);
	pGrid->AdvanceCurrentPlayer();
}
RebootRepairAction:: ~RebootRepairAction()
{
}