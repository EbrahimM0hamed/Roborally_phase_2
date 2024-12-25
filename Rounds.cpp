#include "Rounds.h"
#include "ShootingPhase.h"
#include "Antenna.h"

Rounds::Rounds()
{
	playerRound = 0;
}

void Rounds::Execute(ApplicationManager* pApp, ActionType ActType)
{
	pManager = pApp;
	Grid* pGrid = pManager->GetGrid();
	if (ActType == EXECUTE_COMMANDS)
	{
			playerRound++;
		if (!(pGrid->GetCurrentPlayer()->GetIsHack()))
		{
			int lazerDamage = 1;
			if (pGrid->GetCurrentPlayer()->GetDoubleLaser() > 0)
				lazerDamage = 2;
			ShootingPhase* pAct = new ShootingPhase(pManager, lazerDamage);
			pAct->Execute();
			pGrid->AdvanceCurrentPlayer();
			if (playerRound == 2)
			{
				playerRound = 0;
			}
			if (playerRound == 0)
			{
				Antenna* pAntenna = pGrid->GetAntenna();
				pAntenna->Apply(pGrid, pGrid->GetCurrentPlayer(), pGrid->GetInput());
			}
		}
	}

}

Rounds::~Rounds()
{
}
