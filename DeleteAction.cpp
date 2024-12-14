#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager *pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    pOut->PrintMessage("Delete: Click on Cell to delete its Object...");
    cellpos = pIn->GetCellClicked();

    pOut->ClearStatusBar();
}
void DeleteAction::Execute()
{
    ReadActionParameters();
    Grid *pGrid = pManager->GetGrid();
    bool deleted=pGrid->RemoveObjectFromCell(cellpos);
    if (!deleted)
	{
		// Print an appropriate message
        pGrid->PrintErrorMessage("Error: Cell doesn't has any object ! Click to continue ...");
	}
}
DeleteAction::~DeleteAction()
{
}