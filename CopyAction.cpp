#include "CopyAction.h"

CopyAction::CopyAction(ApplicationManager *pApp) : Action(pApp)
{
    gameObject = NULL;
}

void CopyAction::ReadActionParameters()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    pOut->PrintMessage("Copy: Click on Cell to Copy its Object...");
    cellpos = pIn->GetCellClicked();

    pOut->ClearStatusBar();
}

void CopyAction::Execute()
{
    ReadActionParameters();
    Grid *pGrid = pManager->GetGrid();
    Cell cell(cellpos);
    gameObject = cell.GetGameObject();

    if (!gameObject)
    {
        pGrid->PrintErrorMessage("Error: Cell doesn't has any object ! Click to continue ...");
        return;
    }
    pGrid->SetClipboard(gameObject);
}