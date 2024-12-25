#include "NewGame.h"


NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGame::ReadActionParameters()
{
}

void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	Player* NextPlayer = pGrid->GetNextPlayer();
	pOut->ClearGridArea();
	pOut->CreatePlayModeToolBar();

	CurrentPlayer->SetCell(&Cell(CellPosition(1)));
	CurrentPlayer->SetCurrDirection(RIGHT);
	CurrentPlayer->SetHealth(10);
	CurrentPlayer->SetToolkit(0);
	CurrentPlayer->SetNumHacked(0);
	CurrentPlayer->SetIsHack(false);
	pGrid->UpdatePlayerCell(CurrentPlayer, CellPosition(1));


	NextPlayer->SetCell(&Cell(CellPosition(1)));
	NextPlayer->SetCurrDirection(RIGHT);
	NextPlayer->SetHealth(10);
	NextPlayer->SetToolkit(0);
	NextPlayer->SetNumHacked(0);
	NextPlayer->SetIsHack(false);
	pGrid->UpdatePlayerCell(NextPlayer, CellPosition(1));

	pGrid->SetCurrentPlayerNumber(0);
	pGrid->UpdateInterface();
	pOut->ClearCommandsBar();
	pOut->ClearStatusBar();
}

NewGame::~NewGame()
{
}