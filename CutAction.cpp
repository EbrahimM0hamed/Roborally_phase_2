#include "CutAction.h"

CutAction::CutAction(ApplicationManager *pApp) : Action(pApp)
{
    gameObject = nullptr;
}

void CutAction::ReadActionParameters()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    pOut->PrintMessage("Cut: Click on Cell to Cut its Object...");
    cellpos = pIn->GetCellClicked();

    pOut->ClearStatusBar();
}

void CutAction::Execute()
{
    ReadActionParameters();
    Grid *pGrid = pManager->GetGrid();
    gameObject = pGrid->GetGameObject(cellpos);

    if (!gameObject)
    {
        pGrid->PrintErrorMessage("Error: Cell doesn't has any object ! Click to continue ...");
        return;
    }
    pGrid->SetClipboard(gameObject);
    pGrid->RemoveObjectFromCell(cellpos);
}