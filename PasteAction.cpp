#include "PasteAction.h"
#include "Belt.h"
#include "Flag.h"
#include "Workshop.h"
#include "Antenna.h"
#include "RotatingGear.h"

PasteAction::PasteAction(ApplicationManager *pApp) : Action(pApp)
{
   // gameObject = nullptr;
}
void PasteAction::ReadActionParameters()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    pOut->PrintMessage("Paste: Click on Cell to paste its Object...");
    cellpos = pIn->GetCellClicked();

    pOut->ClearStatusBar();
}
void PasteAction::Execute()
{
    ReadActionParameters();
    Grid *pGrid = pManager->GetGrid();
    GameObject *pGameObj = pGrid->GetClipboard();

    gameObject = dynamic_cast<Flag *>(pGameObj);
    if (gameObject)
    {
        Flag *pFalg = new Flag(cellpos);
        pGrid->AddObjectToCell(pFalg);
        return;
    }
    gameObject = dynamic_cast<Belt *>(pGameObj);
    if (gameObject)
    {
       // Belt *belt = new Belt(cellpos);
        return;
    }
    gameObject = dynamic_cast<Workshop *>(pGameObj);
    if (gameObject)
    {
       
        return;
    }
    gameObject = dynamic_cast<Antenna *>(pGameObj);
    if (gameObject)
    {
       
        return;
    }
    gameObject = dynamic_cast<RotatingGear *>(pGameObj);
    if (gameObject)
    {
       
        return;
    }
    
    if (!gameObject)
    {
        pGrid->PrintErrorMessage("Error: Clipboard doesn't has any object ! Click to continue ...");
        return;
    }
    pGrid->AddObjectToCell(gameObject);
}
PasteAction::~PasteAction()
{
}