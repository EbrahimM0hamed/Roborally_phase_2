#include "ShootingPhase.h"

ShootingPhase::ShootingPhase(ApplicationManager* pApp,int damage) : Action(pApp)
{
	this->damage=damage;
}

void ShootingPhase::ReadActionParameters()
{
}

void ShootingPhase::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* currPlayer = pGrid->GetCurrentPlayer();
	Player* oppPlayer = pGrid->GetNextPlayer();
	CellPosition currPosition = currPlayer->GetCell()->GetCellPosition();
	CellPosition oppPosition = oppPlayer->GetCell()->GetCellPosition();

	bool isFaced = false;
	Direction currDirection = currPlayer->GetCurrDirection();

	if (currPosition.HCell() == oppPosition.HCell())
	{
		if (currDirection == DOWN && oppPosition.VCell() > currPosition.VCell())
		{
			isFaced = true;
		}
		else if (currDirection == UP && oppPosition.VCell() < currPosition.VCell()) 
		{
			isFaced = true;
		}
	}
	else if (currPosition.VCell() == oppPosition.VCell())
	{
		if (currDirection == LEFT && oppPosition.HCell() < currPosition.HCell())
		{
			isFaced = true;
		}
		else if(currDirection == RIGHT && oppPosition.HCell() > currPosition.HCell()) 
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
		pOut->DrawLaser(currPosition, oppPosition);
		oppPlayer->reduceHealth(damage);
		pGrid->PrintErrorMessage("You hit another player, click to continue");
		pIn->GetCellClicked();
		pOut->RemoveLaser(currPosition, oppPosition);
		if (oppPlayer->GetHealth() <= 0)
		{
			pGrid->PrintErrorMessage("Player " +to_string(currPlayer->GetplayerNum())+ " wins");

			pGrid->SetEndGame(true);
		}

	}
}

ShootingPhase::~ShootingPhase()
{
}
