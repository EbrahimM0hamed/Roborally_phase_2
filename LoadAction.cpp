#include "LoadAction.h"
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
    ReadActionParameters();
    // if(!(file[file.length()]=='t' && file[file.length() - 1] == 'x' && file[file.length() - 3] == 'e' && file[file.length() - 2] == 't'))
    //     file+=".txet";
    ifstream Infile(file,ios::in);
    if(!Infile.is_open())
        Infile.open(file,ios::in);
    Grid *pGrid = pManager->GetGrid();
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
}
LoadAction::~LoadAction()
{
}
