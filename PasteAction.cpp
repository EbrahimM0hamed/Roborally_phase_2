#include "PasteAction.h"
#include "Belt.h"
#include "Flag.h"
#include "Workshop.h"
#include "Antenna.h"
#include "RotatingGear.h"
#include "WaterPit.h"
#include "DangerZone.h"
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
    if(dynamic_cast<GameObject *>(pGrid->GetGameObject(cellpos))){
        pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
    }

    gameObject = dynamic_cast<Flag *>(pGameObj);
    if (gameObject)
    {
        if(pGrid->GetHasFlag()){
            pGrid->PrintErrorMessage("Error: Can't paste a flag more than one time ! Click to continue ...");
            return;
        }
        Flag *pFalg = new Flag(cellpos);
        pGrid->AddObjectToCell(pFalg);
        return;
    }
    Belt *pBelt = dynamic_cast<Belt *>(pGameObj);
    if (pBelt)
    {
        CellPosition sartPos=pBelt->GetPosition();
        CellPosition EndPos=pBelt->GetEndPosition();
        if(sartPos.VCell()==EndPos.VCell()){
            int h=EndPos.HCell()-sartPos.HCell()+cellpos.HCell();
            CellPosition endPos(cellpos.VCell(),h);
            Belt *belt = new Belt(cellpos,endPos);
            pGrid->AddObjectToCell(belt);
        }else{
            int v=EndPos.VCell()-sartPos.VCell()+cellpos.VCell();
            CellPosition endPos(v,cellpos.HCell());
            Belt *belt = new Belt(cellpos,endPos);
            pGrid->AddObjectToCell(belt);
        }
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
        if(pGrid->GetHasAntenna()){
            pGrid->PrintErrorMessage("Error: Can't paste an antenna more than one time ! Click to continue ...");
            return;
        }
        Antenna *pAntenna = new Antenna(cellpos);
        pGrid->AddObjectToCell(pAntenna);
        return;
    }
    RotatingGear *pRotatingGear = dynamic_cast<RotatingGear *>(pGameObj);
    if (pRotatingGear)
    {
        bool clock=pRotatingGear->GetisClockWise();
        RotatingGear *rotatingGear = new RotatingGear(cellpos,clock);
        pGrid->AddObjectToCell(rotatingGear);
        return;
    } 
    gameObject = dynamic_cast<DangerZone *>(pGameObj);
    if (gameObject)
    {
        DangerZone *pDangerZone = new DangerZone(cellpos);
        pGrid->AddObjectToCell(pDangerZone);
        return;
    }
    gameObject = dynamic_cast<WaterPit *>(pGameObj);
    if (gameObject)
    {
        WaterPit *pWaterPit = new WaterPit(cellpos);
        pGrid->AddObjectToCell(pWaterPit);
        return;
    }
    // pGrid->AddObjectToCell(gameObject);
}
PasteAction::~PasteAction()
{
}
//try