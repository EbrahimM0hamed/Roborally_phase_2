#include "ShootingPhase.h"

ShootingPhase::ShootingPhase(ApplicationManager* pApp) : Action(pApp)
{
	Grid* pGrid = pManager->GetGrid();

	for (int i = 0;i < MaxPlayerCount; i++)
	{
		PlayerList[i] = pGrid->GetCurrentPlayer();
	}
}

void ShootingPhase::ReadActionParameters()
{
}

void ShootingPhase::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Player* currPlayer = pGrid->GetCurrentPlayer();
	Player* oppPlayer = NULL;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i] != currPlayer)
		{
			oppPlayer = PlayerList[i];
			break;
		}
	}
	if (oppPlayer == NULL)
	{
		pGrid->PrintErrorMessage("Opponent not found");
		return;
	}
	CellPosition currPosition = currPlayer->GetCell()->GetCellPosition();
	CellPosition oppPosition = oppPlayer->GetCell()->GetCellPosition();

	bool isFaced = false;
	Direction currDirection = currPlayer->GetCurrDirection();

	if (currPosition.HCell() == oppPosition.HCell())
	{
		if (currDirection == RIGHT && oppPosition.VCell() > currPosition.VCell())
		{
			isFaced = true;
		}
		else if (currDirection == LEFT && oppPosition.VCell() < currPosition.VCell()) 
		{
			isFaced = true;
		}
	}
	else if (currPosition.VCell() == oppPosition.VCell())
	{
		if (currDirection == UP && oppPosition.HCell() < currPosition.HCell())
		{
			isFaced = true;
		}
		else if(currDirection == DOWN && oppPosition.HCell() > currPosition.HCell()) 
		{
			isFaced = true;
		}
	}
	else
	{
		pGrid->PrintErrorMessage("Opponent not in the same row or column");
		return;
	}


	if (isFaced == true)
	{
		// double laser condition must be done here
		oppPlayer->reduceHealth(damage);
		pGrid->PrintErrorMessage("You hit another player, click to continue");

		if (oppPlayer->GetHealth() <= 0)
		{
			pGrid->PrintErrorMessage("Player // wins");

			pGrid->SetEndGame(true);
		}
	}
}

ShootingPhase::~ShootingPhase()
{
}
