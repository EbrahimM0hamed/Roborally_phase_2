#include "PasteAction.h"
#include "Belt.h"
#include "Flag.h"
#include "Workshop.h"
#include "Antenna.h"
#include "RotatingGear.h"

PasteAction::PasteAction(ApplicationManager *pApp) : Action(pApp)
{
    gameObject = nullptr;
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

    if (!pGameObj)
    {
        pGrid->PrintErrorMessage("Error: Clipboard doesn't has any object ! Click to continue ...");
        return;
    }
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
        Workshop *pWorkshop = new Workshop(cellpos);
        pGrid->AddObjectToCell(pWorkshop);
        return;
    }
    gameObject = dynamic_cast<Antenna *>(pGameObj);
    if (gameObject)
    {
       
        return;
    }
    RotatingGear *pRotatingGear = dynamic_cast<RotatingGear *>(pGameObj);
    bool clock=pRotatingGear->GetisClockWise();
    if (pRotatingGear)
    {
        RotatingGear *pRotatingGear = new RotatingGear(cellpos,clock);
        pGrid->AddObjectToCell(pRotatingGear);
        return;
    }
    
    //pGrid->AddObjectToCell(gameObject);
}
PasteAction::~PasteAction()
{
}