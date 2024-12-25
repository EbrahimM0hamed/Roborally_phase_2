
#include "ShieldMechanic.h"

ShieldMechanic::ShieldMechanic(ApplicationManager* pApp) :Action(pApp)
{
}

void ShieldMechanic::ReadActionParameters()
{
}

void ShieldMechanic::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Player* currPlayer = pGrid->GetCurrentPlayer();

	if (currPlayer->getIsShielded() == false)
	{
		currPlayer->activateShield();
		pGrid->PrintErrorMessage("Shield activated");
	}
	else
	{
		pGrid->PrintErrorMessage("Shield already activated");
	}
}

ShieldMechanic::~ShieldMechanic()
{
}
