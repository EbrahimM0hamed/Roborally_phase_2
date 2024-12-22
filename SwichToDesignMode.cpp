#include "SwichToDesignMode.h"


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
    pOut->CreateDesignModeToolBar();
}

SwichToDesignMode::~SwichToDesignMode()
{
}