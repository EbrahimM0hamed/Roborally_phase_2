#include "RebootRepair.h"
#include"ApplicationManager.h"
#include"Player.h"
using namespace std;

RebootRepairAction::RebootRepairAction(ApplicationManager* pApp) :Action(pApp)
{
}
void RebootRepairAction::ReadActionParameters()
{
}

void RebootRepairAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pPlayer = pGrid->GetCurrentPlayer();
	pPlayer->SetHealth(10);
	pGrid->AdvanceCurrentPlayer();
}
RebootRepairAction:: ~RebootRepairAction()
{
}