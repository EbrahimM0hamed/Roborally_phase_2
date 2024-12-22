#include "LoadAction.h"
#include "Cellposition.h"
LoadAction::LoadAction(ApplicationManager *pApp) : Action(pApp)
{
    // Initializes the pManager pointer of Action with the passed pointer
}

void LoadAction::ReadActionParameters()
{
    // Get a Pointer to the Input / Output Interfaces
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    // Read the parameter
    pOut->PrintMessage("New Load: Please Enter the File Name ...");
    file=pIn->GetSrting(pOut)+".txt";
    // Clear messages
    pOut->ClearStatusBar();
}
void LoadAction::Execute()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    for(int i=1;i<56;i++){
        pGrid->RemoveObjectFromCell(CellPosition(i));
    }
    ReadActionParameters();
    ifstream Infile(file,ios::in);
    if(!Infile.is_open()){
        pOut->PrintMessage("Can't find file with this file name, loading failed.");
        Infile.open(file,ios::in);
    }else{
    // Load the grid
    pGrid->LoadAll(Infile,file,FLAG);
    pGrid->LoadAll(Infile,file,BELT);
    pGrid->LoadAll(Infile,file,ANTENNA);
    pGrid->LoadAll(Infile,file,ROTATINGGEAR);
    pGrid->LoadAll(Infile,file,WORKSHOP);
    pGrid->LoadAll(Infile,file,WATERPIT);
    pGrid->LoadAll(Infile,file,DANGERZONE);
    // Close the file
    Infile.close();
    pOut->PrintMessage("Loading done successfully.");
    }
}
LoadAction::~LoadAction()
{
}