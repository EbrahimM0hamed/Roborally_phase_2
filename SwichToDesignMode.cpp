#include "SwichToDesignMode.h"
#include "NewGame.h"


SwichToDesignMode::SwichToDesignMode(ApplicationManager *pApp):Action(pApp)
{
}

void SwichToDesignMode::ReadActionParameters()
{
}

void SwichToDesignMode::Execute()
{
    Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
    NewGame* pNewGame = new NewGame(pManager);
    pOut->CreateDesignModeToolBar();
	pOut->ClearGridArea();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			pGrid->RemoveObjectFromCell(CellPosition(i, j));
		}
	}
}

SwichToDesignMode::~SwichToDesignMode()
{
}