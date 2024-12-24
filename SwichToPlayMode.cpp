#include "SwichToPlayMode.h"


SwichToPlayMode::SwichToPlayMode(ApplicationManager *pApp):Action(pApp)
{
}

void SwichToPlayMode::ReadActionParameters()
{
}

void SwichToPlayMode::Execute()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
    pOut->CreatePlayModeToolBar();
    
    Antenna* pAntenna = new Antenna(pGrid->GetAntennaPosition());
    pAntenna->Apply(pGrid, pGrid->GetCurrentPlayer(), pIn);
}

SwichToPlayMode::~SwichToPlayMode()
{
}