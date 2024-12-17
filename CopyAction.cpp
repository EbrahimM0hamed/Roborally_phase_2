#include "CopyAction.h"
#include "Flag.h"
#include "Antenna.h"

CopyAction::CopyAction(ApplicationManager *pApp) : Action(pApp)
{
    gameObject = nullptr;
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
    gameObject = pGrid->GetGameObject(cellpos);
    if(Flag *pFlag=dynamic_cast<Flag *>(gameObject)){
        pGrid->PrintErrorMessage("Error: Can't Copy Flag ! Click to continue ...");
        return;
    }
    if(Antenna *pFlag=dynamic_cast<Antenna *>(gameObject)){
        pGrid->PrintErrorMessage("Error: Can't Copy Antenna ! Click to continue ...");
        return;
    }
    if (!gameObject)
    {
        pGrid->PrintErrorMessage("Error: Cell doesn't has any object ! Click to continue ...");
        return;
    }
    pGrid->SetClipboard(gameObject);
}

CopyAction::~CopyAction()
{
}