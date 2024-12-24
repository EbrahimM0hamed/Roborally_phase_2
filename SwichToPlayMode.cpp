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
    pOut->CreatePlayModeToolBar();
    
}

SwichToPlayMode::~SwichToPlayMode()
{
}